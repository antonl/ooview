#include <QObject>
#include <QVector>
#include <iostream>

#include "mock_usb4000.h"

using std::cout; using std::endl;    

MockUSB4000::MockUSB4000(QObject *owner) : 
    Spectrometer(owner), m_spectrum(3648), m_wlcoef(4), m_acoef(10)
{
    cout << "reserved memory\n";

    cout << "initialized libusb\n";

    cout << endl;
}

MockUSB4000::~MockUSB4000() 
{
    cout << "destroyed spectrometer" << endl;
}

void MockUSB4000::setIntegrationTime(unsigned int usec) 
{
    // do range checking here
    m_integration_time = usec;
    cout << "set integration time " << usec << endl;
    emit integrationTimeChanged(usec);
}

void MockUSB4000::queueSpectrum()
{
    cout << "request to obtain spectrum" << endl;
    if(m_spectrum[0] <= 5)
        m_spectrum.fill(10.);
    else
        m_spectrum.fill(0.);

    emit spectrumChanged(m_spectrum);
}
    
void MockUSB4000::getWavelengthCalibration() 
{
    cout << "request to obtain wavelength calibration" << endl;

    for(int i = 0; i < 4; ++i) {
        m_wlcoef[i] = i;
    }

    emit wavelengthCalibrationUpdated(m_wlcoef);
}

void MockUSB4000::getAmplitudeCalibration() 
{
    cout << "request to obtain amplitude calibration" << endl;

    for(int i = 0; i < 10; ++i) {
        m_wlcoef[i] = i;
    }

    emit amplitudeCalibrationUpdated(m_acoef);
}

#include "moc_mock_usb4000.cpp"

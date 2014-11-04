#ifndef MOCKUSB4000_H
#define MOCKUSB4000_H

#include <QVector>
#include "spectrometer.h"

class MockUSB4000 : public Spectrometer {
    Q_OBJECT

    public:
        explicit MockUSB4000(QObject *owner = 0);
        ~MockUSB4000() override;
    
    signals:
        void spectrumChanged(QVector<float> spectrum);
        void wavelengthCalibrationUpdated(QVector<float> wlcoef);
        void amplitudeCalibrationUpdated(QVector<float> acoef);
        void integrationTimeChanged(unsigned int usec);
    
    public slots:
        void setIntegrationTime(unsigned int usec) override;
        void queueSpectrum() override;    
        void getWavelengthCalibration() override;
        void getAmplitudeCalibration() override;

    private:
        unsigned int m_integration_time;
        QVector<float> m_spectrum;
        QVector<float> m_wlcoef;
        QVector<float> m_acoef;

};
#endif

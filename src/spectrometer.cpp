#include "spectrometer.h"

Spectrometer::Spectrometer(QObject *owner) : 
    QObject(owner) {}

Spectrometer::~Spectrometer() {}

void Spectrometer::setIntegrationTime(unsigned int usec) {}
void Spectrometer::queueSpectrum() {}
void Spectrometer::getWavelengthCalibration() {}
void Spectrometer::getAmplitudeCalibration() {}

// Annoying thing. Have to add 
#include "moc_spectrometer.cpp"
// even though this supposed to be an interface class...

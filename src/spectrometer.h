#ifndef SPECTROMETER_H_XAC
#define SPECTROMETER_H_XAC

#include <QObject>
#include <QVector>

class Spectrometer : public QObject {
    Q_OBJECT

    public:
        explicit Spectrometer(QObject *owner = 0);
        virtual ~Spectrometer();

    signals:
        void spectrumChanged(QVector<float> spectrum);
        void wavelengthCalibrationUpdated(QVector<float> wlcoef);
        void amplitudeCalibrationUpdated(QVector<float> acoef);
        void integrationTimeChanged(unsigned int usec);

    public slots:
        virtual void setIntegrationTime(unsigned int usec);
        virtual void queueSpectrum(); 
        virtual void getWavelengthCalibration();
        virtual void getAmplitudeCalibration();
};
#endif

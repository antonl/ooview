#ifndef OOVIEW_CONTROLLER_H_XAC
#define OOVIEW_CONTROLLER_H_XAC

#include <memory>
#include <QStateMachine>
#include <QThread>
#include <QObject>
#include "spectrometer.h"
#include "ooview.h"

class OOViewController : public QStateMachine {
    Q_OBJECT

    public:
        explicit OOViewController(QObject *parent = 0);
        ~OOViewController() = default;

    private:
        inline void setup_states();
        inline void make_spectrometer();
        inline void setup_ooview();

        Spectrometer m_spec;
        OOView m_ooview;
        QThread m_worker;
};

#endif

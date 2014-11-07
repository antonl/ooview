#include "ooview_controller.h"
#include <QState>

OOViewController::OOViewController(QObject *parent): QStateMachine(parent) {
    setup_states();
    make_spectrometer();
    setup_ooview();
}

void OOViewController::setup_states() {
}

void OOViewController::setup_ooview() {
    m_ooview.show();
}

void OOViewController::make_spectrometer() {
}

void OOViewController::start() {
}

#include "moc_ooview_controller.cpp"

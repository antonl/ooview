#include "ooview_controller.h"
#include <QState>
#include <QPushButton>

OOViewController::OOViewController(QObject *parent): QStateMachine(parent) {
    setup_states();
    make_spectrometer();
    setup_ooview();
}

void OOViewController::setup_states() {
    QState *s1 = new QState();
    QState *s2 = new QState();
    this->addState(s1);
    this->addState(s2);
    this->setInitialState(s1);
    QPushButton *if_button = m_ooview.findChild<QPushButton *>("my_button");
    s1->addTransition(if_button, SIGNAL(clicked()), s2);
    s2->assignProperty(if_button, "text", "in final state");
}

void OOViewController::setup_ooview() {
    m_ooview.show();
}

void OOViewController::make_spectrometer() {
    // Identify available usb spectrometers and create a spectrometer object
}

#include "moc_ooview_controller.cpp"

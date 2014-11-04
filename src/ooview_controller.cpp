#include "ooview_controller.h"
#include <QState>

OOViewController(QObject *parent): QObject(parent) {
    setup_states();
    make_spectrometer();
    setup_ooview();
}

void OOView::setup_states() {
}

#include "moc_ooview_controller.cpp"

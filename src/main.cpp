#include <QApplication>
#include "ooview_controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    OOViewController control;
    control.start();
    return app.exec();
}

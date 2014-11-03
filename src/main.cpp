#include <QApplication>
#include "ooview.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    OOView w;
    w.show();
    return app.exec();
}

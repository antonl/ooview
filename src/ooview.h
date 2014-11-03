#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <memory>
#include "ui_ooview.h"

// Forward declare main window
namespace Ui {
    class OOView;
};

class OOView : public QMainWindow {
    Q_OBJECT

    public:
        explicit OOView(QWidget *parent = 0);

    private:
        Ui::OOView *ui;
};
#endif

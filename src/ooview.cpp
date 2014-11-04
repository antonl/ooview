#include "ooview.h"
#include "ui_ooview.h"

OOView::OOView(QWidget *parent) : QMainWindow(parent), ui(new Ui::OOView) 
{
    ui->setupUi(this);        
}

#include "moc_ooview.cpp"

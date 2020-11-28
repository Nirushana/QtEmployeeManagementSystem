#include "deleteemployee.h"
#include "ui_deleteemployee.h"

deleteemployee::deleteemployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteemployee)
{
    ui->setupUi(this);
}

deleteemployee::~deleteemployee()
{
    delete ui;
}

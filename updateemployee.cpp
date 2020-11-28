#include "updateemployee.h"
#include "ui_updateemployee.h"

updateemployee::updateemployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updateemployee)
{
    ui->setupUi(this);
}

updateemployee::~updateemployee()
{
    delete ui;
}

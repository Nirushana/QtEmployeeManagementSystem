#include "addnewemployee.h"
#include "ui_addnewemployee.h"

addNewEmployee::addNewEmployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addNewEmployee)
{
    ui->setupUi(this);
}

addNewEmployee::~addNewEmployee()
{
    delete ui;
}

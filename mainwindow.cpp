#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addNewBtn_clicked()
{
    empNew = new addNewEmployee(this);
    empNew->show();
}

void MainWindow::on_updateBtn_clicked()
{
    empUpdate = new updateemployee(this);
    empUpdate->show();
}

void MainWindow::on_deleteBtn_clicked()
{
    empDelete = new deleteemployee(this);
    empDelete->show();
}

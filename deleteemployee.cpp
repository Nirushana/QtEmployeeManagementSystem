#include "deleteemployee.h"
#include "ui_deleteemployee.h"
#include "mainwindow.h"
#include <QMessageBox>
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

void deleteemployee::on_updatebtn_clicked(){

}


void deleteemployee::on_deletebtn_clicked()
{
    MainWindow conn;
    QString empId, empName, empDob, empGender, empNumber, empEmail, empAddress1, empAddress2, empDepartment;
    empId = ui->empIdtxt->text();



    if(!conn.connOpen()){

        qDebug()<<"Faild to Open Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    if(qry.exec("Delete from EmployeeData where empId='"+empId+"'"))
    {
       QMessageBox::information(this,tr("Data Deleted from Database"), tr("Data is Deleted Successfully"));
       conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"), qry.lastError().text());
    }
}

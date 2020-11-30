#include "updateemployee.h"
#include "ui_updateemployee.h"
#include "mainwindow.h"
#include <QMessageBox>

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

void updateemployee::on_updatebtn_clicked()
{
    MainWindow conn;
    QString empId, empName, empDob, empGender, empNumber, empEmail, empAddress1, empAddress2, empDepartment;
    empId = ui->empIDtxt->text();
    empName = ui->empNametxt->text();
    empDob = ui->empBDtxt->text();
    empGender = ui->empGendertxt->text();
    empNumber = ui->empNumbertxt->text();
    empEmail = ui->empEmailtxt->text();
    empAddress1 = ui->empAD1txt->text();
    empAddress2 = ui->empAD2txt->text();
    empDepartment = ui->empDPtxt->text();

    if(!conn.connOpen()){

        qDebug()<<"Faild to Open Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    if(qry.exec("update EmployeeData set empName='"+empName+"', empDob='"+empDob+"', empGender='"+empGender+"', empNumber='"+empNumber+"', empEmail='"+empEmail+"', empAddress1='"+empAddress1+"', empAddress2='"+empAddress2+"', empDepartment='"+empDepartment+"' where empId='"+empId+"'"))
    {
       QMessageBox::information(this,tr("Data Upodated to Database"), tr("Data Updated Successfully"));
       conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"), qry.lastError().text());
    }
}

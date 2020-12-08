#include "addnewemployee.h"
#include "ui_addnewemployee.h"
#include "mainwindow.h"
#include <QMessageBox>

addNewEmployee::addNewEmployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addNewEmployee)
{
    ui->setupUi(this);
    MainWindow conn;
        if(!conn.connOpen()){
            ui->status_label->setText("Database Connection Failed");
        }
        else{
            ui->status_label->setText("Database Connected");
        }

        ui->comboBox->addItem("Tech");
        ui->comboBox->addItem("Finance");
        ui->comboBox->addItem("Marketing");
        ui->comboBox->addItem("R&D");

}

addNewEmployee::~addNewEmployee()
{
    delete ui;
}

void addNewEmployee::on_addbtn_clicked()
{
    MainWindow conn;
    QString empId, empName, empDob, empGender, empNumber, empEmail, empAddress1, empAddress2, empDepartment;
    empId = ui->empIDtxt->text();
    empName = ui->empNametxt->text();
    empDob = ui->empBDtxt->text();
    empGender = "";
    empNumber = ui->empNumbertxt->text();
    empEmail = ui->empEmailtxt->text();
    empAddress1 = ui->empAD1txt->text();
    empAddress2 = ui->empAD2txt->text();
    empDepartment = ui->comboBox->currentText();

    if(ui->radioButton->isChecked()){
        empGender = ui->radioButton->text();
    }
    if(ui->radioButton_2->isChecked()){
        empGender = ui->radioButton_2->text();
    }

    if(!conn.connOpen()){

        qDebug()<<"Faild to Open Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    if(qry.exec("insert into EmployeeData(empId, empName, empDob, empGender, empNumber, empEmail, empAddress1, empAddress2, empDepartment) values ('"+empId+"', '"+empName+"', '"+empDob+"', '"+empGender+"', '"+empNumber+"', '"+empEmail+"','"+empAddress1+"', '"+empAddress2+"', '"+empDepartment+"')"))
    {
       QMessageBox::information(this,tr("Data Added to Database"), tr("Data saved Successfully"));
       conn.connClose();
       close();
    }
    else{
        QMessageBox::critical(this,tr("error::"), qry.lastError().text());
        close();
    }

}

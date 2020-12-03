#include "updateemployee.h"
#include "ui_updateemployee.h"
#include "mainwindow.h"
#include <QMessageBox>

updateemployee::updateemployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updateemployee)
{
    ui->setupUi(this);


    ui->comboBox->addItem("Tech");
    ui->comboBox->addItem("Finance");
    ui->comboBox->addItem("Marketing");
    ui->comboBox->addItem("R&D");

    /*Load Data to the table*/
    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.db);

    qry->prepare("select empId from EmployeeData");

    qry->exec();
    model->setQuery(*qry);
    ui->comboBox_2->setModel(model);

    conn.connClose();
    qDebug() << (model->rowCount());
}

updateemployee::~updateemployee()
{
    delete ui;
}

void updateemployee::on_updatebtn_clicked()
{
    MainWindow conn;
    QString empId, empName, empDob, empGender, empNumber, empEmail, empAddress1, empAddress2, empDepartment;
    empId = ui->comboBox_2->currentText();
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

    if(qry.exec("update EmployeeData set empName='"+empName+"', empDob='"+empDob+"', empGender='"+empGender+"', empNumber='"+empNumber+"', empEmail='"+empEmail+"', empAddress1='"+empAddress1+"', empAddress2='"+empAddress2+"', empDepartment='"+empDepartment+"' where empId='"+empId+"'"))
    {
       QMessageBox::information(this,tr("Data Upodated to Database"), tr("Data Updated Successfully"));
       conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"), qry.lastError().text());
    }
}

void updateemployee::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString empID = ui->comboBox_2->currentText();

    MainWindow conn;


    if(!conn.connOpen()){

        qDebug()<<"Faild to Open Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    if(qry.exec("Select * from EmployeeData where empId='"+empID+"'"))
    {
      while(qry.next()){
          ui->empNametxt->setText(qry.value(1).toString());
          ui->empBDtxt->setText(qry.value(2).toString());
          ui->empNumbertxt->setText(qry.value(4).toString());
          ui->empEmailtxt->setText(qry.value(5).toString());
          ui->empAD1txt->setText(qry.value(6).toString());
          ui->empAD2txt->setText(qry.value(7).toString());
          ui->comboBox->setCurrentText(qry.value(8).toString());
      }
       conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"), qry.lastError().text());
    }
}

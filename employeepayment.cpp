#include "employeepayment.h"
#include "ui_employeepayment.h"
#include "mainwindow.h"
#include <QMessageBox>

employeepayment::employeepayment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employeepayment)
{
    ui->setupUi(this);


    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.db);

    qry->prepare("select empId from EmployeeData");

    qry->exec();
    model->setQuery(*qry);
    ui->comboBox->setModel(model);

    conn.connClose();
    qDebug() << (model->rowCount());
}

employeepayment::~employeepayment()
{
    delete ui;
}

void employeepayment::on_updatebtn_clicked()
{
    MainWindow conn;
    QString empId, empSalary, empPayDate, empPayStatus;
    empId = ui->comboBox->currentText();
    empSalary = ui->empSalarytxt->text();
    empPayDate = ui->empPayDatetxt->text();
    empPayStatus = ui->empPayStatustxt->text();


    if(!conn.connOpen()){

        qDebug()<<"Faild to Open Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    if(qry.exec("update EmployeeData set empPayAmount='"+empSalary+"', empPayDay='"+empPayDate+"', empPayStatus='"+empPayStatus+"' where empId='"+empId+"'"))
    {
       QMessageBox::information(this,tr("Data Upodated to Database"), tr("Data Updated Successfully"));
       conn.connClose();
       close();
    }
    else{
        QMessageBox::critical(this,tr("error::"), qry.lastError().text());
        close();
    }
}

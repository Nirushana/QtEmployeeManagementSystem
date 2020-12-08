#include "deleteemployee.h"
#include "ui_deleteemployee.h"
#include "mainwindow.h"
#include <QMessageBox>
deleteemployee::deleteemployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteemployee)
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

deleteemployee::~deleteemployee()
{
    delete ui;
}

void deleteemployee::on_updatebtn_clicked(){

}


void deleteemployee::on_deletebtn_clicked()
{
    MainWindow conn;
    QString empId;
    empId = ui->comboBox->currentText();



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
       close();
    }
    else{
        QMessageBox::critical(this,tr("error::"), qry.lastError().text());
        close();
    }
}

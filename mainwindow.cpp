#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::loadtb()
{

    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.db);

    qry->prepare("select * from EmployeeData");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug() << (model->rowCount());

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("EmpMgSystem.db");   //The path for the database connection.


    if(!connOpen()){
        ui->status_lb->setText("Database Conncetion Failed");
    }
    else{
        ui->status_lb->setText("Database Connected");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addNewBtn_clicked()
{
    empNew = new addNewEmployee(this); //to open new ui form
    empNew->show();
}

void MainWindow::on_updateBtn_clicked()
{
    empUpdate = new updateemployee(this); //to open new ui form
    empUpdate->show();
}

void MainWindow::on_deleteBtn_clicked()
{
    empDelete = new deleteemployee(this); //to open new ui form
    empDelete->show();
}



void MainWindow::on_pushButton_2_clicked()
{

    loadtb();

}

void MainWindow::on_transactionBnt_clicked()
{
    empPayment = new employeepayment(this); //to open new ui form
    empPayment->show();
}

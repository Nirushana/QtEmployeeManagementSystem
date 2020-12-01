#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "addnewemployee.h"
#include "updateemployee.h"
#include "deleteemployee.h"
#include "employeepayment.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    void connClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        /*Database Conncetion*/
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/kavin/OneDrive/Desktop/My Dev/QT Projects/EmployeeManagementSystem/EmpMgSystem.db");   //The path for the database connection.

        /*TO check if the database connection is successfull or not*/
        if(!db.open()){
            qDebug()<<("Database Conncetion Failed");
            return false;
        }
        else{
            qDebug()<<("Database Connected");
            return true;
        }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNewBtn_clicked();

    void on_updateBtn_clicked();

    void on_deleteBtn_clicked();

    void on_pushButton_2_clicked();

    void on_transactionBnt_clicked();

private:
    Ui::MainWindow *ui;
    addNewEmployee *empNew;
    updateemployee *empUpdate;
    deleteemployee *empDelete;
    employeepayment *empPayment;
};
#endif // MAINWINDOW_H

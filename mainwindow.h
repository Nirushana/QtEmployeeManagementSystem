#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "addnewemployee.h"
#include "updateemployee.h"
#include "deleteemployee.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNewBtn_clicked();

    void on_updateBtn_clicked();

    void on_deleteBtn_clicked();

private:
    Ui::MainWindow *ui;
    addNewEmployee *empNew;
    updateemployee *empUpdate;
    deleteemployee *empDelete;
};
#endif // MAINWINDOW_H

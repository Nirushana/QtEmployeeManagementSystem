#ifndef ADDNEWEMPLOYEE_H
#define ADDNEWEMPLOYEE_H

#include <QMainWindow>


namespace Ui {
class addNewEmployee;
}

class addNewEmployee : public QMainWindow
{
    Q_OBJECT

public:

    explicit addNewEmployee(QWidget *parent = nullptr);
    ~addNewEmployee();

private slots:
    void on_addbtn_clicked();

private:
    Ui::addNewEmployee *ui;
};

#endif // ADDNEWEMPLOYEE_H

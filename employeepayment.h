#ifndef EMPLOYEEPAYMENT_H
#define EMPLOYEEPAYMENT_H

#include <QMainWindow>

namespace Ui {
class employeepayment;
}

class employeepayment : public QMainWindow
{
    Q_OBJECT

public:
    explicit employeepayment(QWidget *parent = nullptr);
    ~employeepayment();

private slots:
    void on_updatebtn_clicked();

private:
    Ui::employeepayment *ui;
};

#endif // EMPLOYEEPAYMENT_H

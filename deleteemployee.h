#ifndef DELETEEMPLOYEE_H
#define DELETEEMPLOYEE_H

#include <QMainWindow>

namespace Ui {
class deleteemployee;
}

class deleteemployee : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteemployee(QWidget *parent = nullptr);
    ~deleteemployee();

private slots:
    void on_updatebtn_clicked();

    void on_deletebtn_clicked();

private:
    Ui::deleteemployee *ui;
};

#endif // DELETEEMPLOYEE_H

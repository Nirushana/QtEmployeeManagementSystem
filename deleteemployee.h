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

private:
    Ui::deleteemployee *ui;
};

#endif // DELETEEMPLOYEE_H

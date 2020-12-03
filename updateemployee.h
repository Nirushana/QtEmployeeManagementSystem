#ifndef UPDATEEMPLOYEE_H
#define UPDATEEMPLOYEE_H

#include <QMainWindow>

namespace Ui {
class updateemployee;
}

class updateemployee : public QMainWindow
{
    Q_OBJECT

public:
    explicit updateemployee(QWidget *parent = nullptr);
    ~updateemployee();

private slots:
    void on_updatebtn_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::updateemployee *ui;
};

#endif // UPDATEEMPLOYEE_H

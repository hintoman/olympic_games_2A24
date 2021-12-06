#ifndef ARDUINOO_H
#define ARDUINOO_H

#include <QDialog>
#include "arduino.h"

namespace Ui {
class arduinoo;
}

class arduinoo : public QDialog
{
    Q_OBJECT

public:
     arduinoo(QWidget *parent = nullptr);
    ~arduinoo();

private slots:
    void update_label();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::arduinoo *ui;
    QByteArray data;
    arduino A;
};

#endif // ARDUINOO_H

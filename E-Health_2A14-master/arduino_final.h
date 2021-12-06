#ifndef ARDUINO_FINAL_H
#define ARDUINO_FINAL_H

#include <QDialog>
#include "arduino.h"


namespace Ui {
class Arduino_final;
}

class Arduino_final : public QDialog
{
    Q_OBJECT

public:
    explicit Arduino_final(QWidget *parent = nullptr);
    ~Arduino_final();
private slots :
    void update_label();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Arduino_final *ui;
    QByteArray data;
    arduino A;
};

#endif // ARDUINO_FINAL_H

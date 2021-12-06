#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H
#include "arduino.h"

#include <QMainWindow>

namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private slots:
    void on_pushButton_clicked();
    void update_label();


private:
    Ui::MainWindow1 *ui;
    int alert=0;
    int etat=-1;
    Arduino A1;
    QString code="";
    QByteArray data1;// variable contenant les données reçues


};

#endif // MAINWINDOW1_H

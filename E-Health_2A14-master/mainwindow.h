#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QDebug>
#include<QThread>
#include<QFileInfo>
#include<QMediaPlayer>
#include<QPropertyAnimation>
#include "EMPLOYE.h"
#include"connection.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE





class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
     void sleep(int s) { QThread::sleep(s); }
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase test_bd;
    QMediaPlayer* player;
    QPropertyAnimation* animation ;

};
#endif // MAINWINDOW_H

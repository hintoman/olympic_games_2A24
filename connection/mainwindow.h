#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include <QMainWindow>
#include <mailing.h>
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_trier_activated();
    void on_recherche_button_clicked();
    void sendMail();
    void on_pb_pdf_clicked();
        void mailSent(QString);
    void on_pushButton_Login_clicked();
private:

    Ui::MainWindow *ui;
    employer emp;
    mailing P;
};
#endif // MAINWINDOW_H

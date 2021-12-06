#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "transaction.h"
#include "arduino.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_valider_clicked();

    void on_pushButton_2_clicked();


    void on_stat_clicked();

    void on_trie_clicked();

    void on_prd_clicked();

    void on_prm_clicked();

    void on_calcul_clicked();

    void on_OK_clicked();

    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

    void update_label();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    Transaction Etmp;
    QByteArray data;// variable contenant les données reçues
      int alert=0;
      int etat=-1;
      Arduino A;
      QString code="";




};

#endif // MAINWINDOW_H

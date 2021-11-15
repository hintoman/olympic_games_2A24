#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<athlete.h>
#include<QSqlTableModel>
#include <QPrinter>
#include <QMainWindow>
#include<QPrintDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringListModel *model;
    QSqlTableModel* table;



private slots:
    void on_pb_Ajouter_clicked();
     void AthleteChange(Athlete * A);

    void on_pb_supprimer_clicked();

    void on_pb_Aaffichier_clicked();

    void on_pushButton_clicked();

    void on_tab_athltes_clicked(const QModelIndex &index);

    void on_modifier_clicked();

    void on_tab_athltes_doubleClicked(const QModelIndex &index);

    void on_pb_chercher_clicked();

    void on_modifier_pressed();

    void on_tri_clicked();

    void on_pb_chercher_2_pressed();

    void on_pb_chercher_2_clicked();
    void readBarcodeData();

    void handleBarcode(QString barcode);


    void on_QRcodecom_clicked();

    void on_QRcodecom_pressed();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_addhis_clicked();

    void on_addhis_2_clicked();

private:
    Ui::MainWindow *ui;
    Athlete A;


};

#endif // MAINWINDOW_H

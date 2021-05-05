#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <plainte.h>
#include <amende.h>
#include <QSound>
#include <QTimer>



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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter2_clicked();

    void on_pb_supprimer_1_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_recherche_clicked();




    void on_trie_activated();

    void on_trie_2_activated();

    void on_recherche1_clicked();
    void makePolt();
    void makePol_2();



    void on_pushButton_pd1_pa_clicked();

    void on_pushButton_excel1_pa_clicked();

    void on_pb_calendarWidget_clicked(const QDate &date);

    void on_pushButton_pd1_pa_2_clicked();

    void on_pushButton_excel1_pa_2_clicked();

    void on_pa_pushButton_101_clicked();

    void on_pa_pushButton_102_clicked();

    void on_pa_pushButton_103_clicked();

    void on_pa_pushButton_104_clicked();

    void on_pa_pushButton_4_clicked();

    void on_pa_pushButton_5_clicked();

    void on_pa_pushButton_105_clicked();

    void on_pa_pushButton_106_clicked();


    void clockTimer();


    void on_menu_pushButton_48_clicked();

private:
    Ui::MainWindow *ui;
    Amende A;
    Plainte P;
    QSound *son;
    QTimer *qTimer;

};

#endif // MAINWINDOW_H

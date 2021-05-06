#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <plainte.h>
#include <amende.h>
#include <QSound>
#include <QTimer>
#include <fournisseur.h>
#include <materiel.h>
#include <QDateTime>
#include <QListWidgetItem>



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



    //firas

    void on_pb_ajouter1_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_ajouter2_2_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_modifier1_clicked();

    void on_pb_recuperer_1_clicked();

    void on_pushButton_6_recup_clicked();

    void on_pushButton_7_recup_clicked();


    void on_recherche_2_clicked();
    void sendMail();
        void mailSent(QString);

        void makePolt1();



    void on_trie_3_activated();

    void on_trie_4_activated();

    void on_recherche1_2_clicked();
    void  showTime();

    void on_pushButton_4_fm_clicked();

    void on_pushButton_5_fm_clicked();

    void on_pushButton_4_clicked();

    void on_m_pushButton_retour_clicked();

    void on_pushButton_mailing_f_clicked();

    void on_m_pushButton_statistique_clicked();

    void on_f_pushButton_retour_mailing_clicked();

    void on_m_pushButton_retour_stat_4_clicked();

    void on_menu_pushButton_49_clicked();
    //firas

    void on_pb_imprimer_clicked();

    void on_pb_pdf_clicked();

    void on_pb_pdf_2_clicked();

    void on_pb_imprimer_2_clicked();
    void digit_pressed();
    void on_pushButton_point_released();
    void unary_operation_pressed();
    void on_pushButton_C_released();
    void on_pushButton_equal_released();
    void binary_operation_pressed();
    //firas

private:
    Ui::MainWindow *ui;
    Amende A;
    Plainte P;
    Fournisseur F;
    Materiel M;
    QSound *son;
    QTimer *qTimer;

};

#endif // MAINWINDOW_H

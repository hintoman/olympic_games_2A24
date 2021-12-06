#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include <QMainWindow>
#include <mailing.h>
#include <QAbstractSocket>

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

    void on_pb_pdf_clicked();
    void on_sendmail_clicked();


void on_login_2_clicked();

void on_pushButton_ajouter_E_clicked();

void on_pushButton_supprimer_E_clicked();

void on_tableView_clicked(const QModelIndex &index);

void on_pushButton_modifier_E_clicked();

void on_pushButton_rafraichir_E_clicked();

void on_pushButton_quitter_clicked();

void on_pushButton_rafraichir_clicked();

void on_pushButton_2_quitter_clicked();

void on_pushButton_tri_codee_clicked();

void on_pushButton_tri_nom_clicked();

void on_pushButton_tri_prix_clicked();

void on_pushButton_chercher_type_clicked();

void on_pushButton_chercher_ville_clicked();

void on_pushButton_pdf_clicked();

void makePlot();
QVector<double> Statistique();

void on_pushButton_statistique_clicked();

void on_pushButton_chercher_nom_clicked();


private:
    QStringList files;
    Ui::MainWindow *ui;
    employer emp;
    mailing P;
    QString pass , user ;
        bool res1  , res2  ;

};
#endif // MAINWINDOW_H

#ifndef GESTION_MAHDI_H
#define GESTION_MAHDI_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>

#include "terrain.h"
#include "reclamation.h"
#include "smtp.h"
#include "maps.h"



namespace Ui {
class gestion_mahdi;
}

class gestion_mahdi : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_mahdi(QWidget *parent = nullptr);
    ~gestion_mahdi();

    terrain tmp_terrain;
    reclamation tmp_reclamation;
    QSortFilterProxyModel *proxy_terrain, *proxy_reclamation;

    void show_tables();

    //terrain
    QString get_nom () const ;
    QString get_id_terrain () const ;
    QString get_lieu() const;
    QString get_etat() const ;
    int get_capacite() const;

    void fill_form_terrain(QString);
    void show_table_terrain();
    void clear_form_terrain();

    //reclamation
    QString get_description () const ;
    QString get_id_reclamation () const ;
    QString get_mail () const ;
    QString get_etat_reclamation () const ;

    void fill_form_reclamation(QString);
    void show_table_reclamation();
    void clear_form_reclamation();




private slots:

    //terrain
    void on_actionajout_terrain_triggered();

    void on_actionsuppression_terrain_triggered();

    void on_tableau_terrain_doubleClicked(const QModelIndex &index);

    void on_sel_col_terrain_currentIndexChanged(const QString &arg1);

    void on_rech_terrain_textChanged(const QString &arg1);

    void on_tableau_terrain_clicked(const QModelIndex &index);

    void on_actionmodifier_terrain_triggered();

    //reclamation

    void on_actionajout_reclamation_triggered();

    void on_actionsuppression_reclamation_triggered();

    void on_tableau_reclamation_doubleClicked(const QModelIndex &index);

    void on_sel_col_reclamation_currentIndexChanged(const QString &arg1);

    void on_rech_reclamation_textChanged(const QString &arg1);

    void on_tableau_reclamation_clicked(const QModelIndex &index);

    void on_actionmodifier_reclamation_triggered();



    void on_actioncheck_map_triggered();

    void on_suppression_t_clicked();

    void on_modification_t_clicked();

    void on_ajou_t_clicked();

    void on_suppression_r_clicked();

    void on_modification_r_clicked();

    void on_ajout_r_clicked();


    void sendMail();
    void mailSent(QString);
    void browse();

    void on_pushButton_clicked();

private:
    Ui::gestion_mahdi *ui;
    QStringList files;
    QString selected_terrain="",selected_reclamation="";
    int sel_col_terrain=-1,sel_col_reclamation=-1;
};

#endif // GESTION_MAHDI_H

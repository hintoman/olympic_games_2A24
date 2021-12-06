#ifndef TACHE_H
#define TACHE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
class tache
{
public:
    tache();
    tache(QString,int,QString,QString);
    QString get_type_tache();
    int get_salaire();
    QString get_date_debut();
    QString get_date_fin();
    void set_type_tache(QString);
    void set_salaire(int);
    void set_date_debut(QString);
    void set_date_fin(QString);
    bool ajouter_tache();
    QSqlQueryModel* afficher_tache();
    bool supprimer_tache(QString);
    bool modifier_tache();
    void chercher_tache_salaire(int s);
    void chercher_type(QString t);
    void chercher_date_debut_type_salaire(QString dd,QString t,int s);

    QSqlQueryModel* afficher_tache_salaire();
    QSqlQueryModel* afficher_type();
    QSqlQueryModel* afficher_date_debut_type_salaire();

private:

    int salaire ;
    QString type_tache,date_debut,date_fin;

};

#endif // TACHE_H

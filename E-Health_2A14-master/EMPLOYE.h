#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>


class EMPLOYE
{
public:

    EMPLOYE();
    EMPLOYE(int,QString,QString,QString,QString,QString);
    int get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_mail();
    QString get_DDN();
    QString get_Tache();
    void set_cin(int);
    void set_nom(QString);
    void set_prenom(QString);
    void set_mail(QString);
    void set_DDN(QString);
    void set_Tache(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    void chercher(int c,QString n, QString p);
    void chercher_cin(int c);
    void chercher_nom_prenom(QString n, QString p);

    QSqlQueryModel* afficher_unemploye();
    QSqlQueryModel* afficher_unemploye_cin();
    QSqlQueryModel* afficher_unemploye_nom_prenom();
    QSqlQueryModel * rechercher_2(QString input,QString filtrer);

   // QSqlQueryModel* afficher_employetrier();


private:

    int cin ;
    QString nom,prenom,mail,DDN,Tache;

};

#endif // EMPLOYE_H

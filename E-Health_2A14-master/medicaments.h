#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

class medicament
{
public:
    medicament();
    medicament(QString , int ,int);
    QString get_nom();
    int get_reference();
    int get_num();
    void set_nom(QString);
    void set_reference(int);
    void set_num(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int );
    bool modifier();
    void chercher_nom(QString );
    void chercher_reference(int);
    void chercher_nom_num(int ,QString);
    QSqlQueryModel* afficher_nom();
    QSqlQueryModel* afficher_reference();
    QSqlQueryModel* afficher_nom_num();
private :
    QString nom;
    int reference,num;

};

#endif // MEDICAMENT_H

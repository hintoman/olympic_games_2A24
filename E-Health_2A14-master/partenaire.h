#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include <QString>
#include <iostream>
#include "health.h"
#include "ui_health.h"
#include <QtSql/QSqlQueryModel>

class partenaire
{


private:
    int cin;
    QString nom;
    QString prenom;
    int numtel;
    QString adresse;
    int id;



public:
    partenaire();
    partenaire(int,QString,QString,int,QString,int);
    bool ajouter(Ui::health*ui);
    bool modifier(Ui::health*ui);
    bool supprimer (Ui::health*ui);
    void afficher(Ui::health*ui);
    void affichertable(Ui::health*ui);
    void Tri_partenaire(Ui::health *ui);
    QSqlQueryModel *trierpartenaire();
    QSqlQueryModel *rechercherpartenaire(QString id);
};

#endif // PARTENAIRE_H

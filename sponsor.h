#ifndef SPONSOR_H
#define SPONSOR_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class sponsor
{
public:
    sponsor();
    sponsor (QString,QString,QString,QString,double);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);



    QString id,nom,adresse,type;
    double montant;
};

#endif // SPONSOR_H

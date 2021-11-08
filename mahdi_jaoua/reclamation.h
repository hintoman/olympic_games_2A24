#ifndef RECLAMATION_H
#define RECLAMATION_H


#include <QSqlQuery>
#include <QSqlQueryModel>

class reclamation
{
public:
    reclamation();
    reclamation (QString,QString,QString,QString);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);



    QString id,description,etat,mail;

};

#endif // RECLAMATION_H

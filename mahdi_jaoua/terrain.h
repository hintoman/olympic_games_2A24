#ifndef TERRAIN_H
#define TERRAIN_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class terrain
{
public:
    terrain();
    terrain (QString,QString,QString,QString,int);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);



    QString id,nom,lieu,etat;
    int capacite;
};

#endif // TERRAIN_H

#ifndef PLAINTE_H
#define PLAINTE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class Plainte
{
public:
    Plainte();
    Plainte(int,QString,QString,int,QDate);
    int getid_pl();
    QString gettype();
    QString getnom_accuse();
    int getcin();
    QDate getdate_debut();
    void setid_pl(int);
    void settype(QString);
    void setnom_accuse(QString);
    void setcin(int);
    void setdate_debut(QDate);
    bool ajouter();
    bool modifier(int id_pl,QString nom_accuse, QString type,int cin,QDate date_debut);
    QSqlQueryModel * rechercher(int id_pl);
        QSqlQueryModel * afficher();
        QSqlQueryModel *Trier(QString );
        bool supprimer(int);        

private:
    int id_pl, cin ;
    QString nom_accuse,type;
    QDate date_debut;
};

#endif // PLAINTE_H

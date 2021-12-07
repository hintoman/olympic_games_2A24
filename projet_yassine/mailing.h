#ifndef mailing_H
#define mailing_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class mailing
{
public:
    mailing();
    mailing(int,QString,int,QDate);
    int getid_pl();
    int getsalaire();
    QString getnom_accuse();
    QDate getdate_debut();
    void setid_pl(int);
    void setsalaire(int);
    void setnom_accuse(QString);
    void setdate_debut(QDate);
    bool ajouter();
    bool modifier(int id_pl,QString nom_accuse, int salaire,QDate date_debut);
    QSqlQueryModel * rechercher(int id_pl);
        QSqlQueryModel * afficher();
        QSqlQueryModel *Trier(QString );
        bool supprimer(int);

private:
    int id_pl, salaire ;
    QString nom_accuse;
    QDate date_debut;
};

#endif // mailing_H

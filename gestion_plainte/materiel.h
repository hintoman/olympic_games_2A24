#ifndef MATERIEL_H
#define MATERIEL_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Materiel
{
public:
    Materiel();
    Materiel(int,QString,QString,int);
    int getidm();
    QString getnom();
    QString gettype1();
    int getprix1();
    void setidm(int);
    void setnom(QString);
    void settype1(QString);
    void setprix1(int);
    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int idm,QString nom, QString type1,int prix1 );
        QSqlQueryModel *Trier(QString );
        QSqlQueryModel * rechercher(int idm);



private:
    int idm, prix1 ;
    QString nom,type1;
};

#endif // MATERIEL_H

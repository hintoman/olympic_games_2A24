#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,QString,int);
    int getid();
    QString getnom();
    QString getprenom();
    int gettel();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void settel(int);
    bool ajouter();
    bool modifier(int id,QString nom, QString prenom,int tel );
    QSqlQueryModel * rechercher(int id);
        QSqlQueryModel * afficher();
        QSqlQueryModel *Trier(QString );
        bool supprimer(int);
private:
    int id, tel ;
    QString nom,prenom;
};

#endif // FOURNISSEUR_H

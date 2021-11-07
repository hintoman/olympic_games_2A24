#ifndef ETUDIANTH_H
#define ETUDIANTH_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class employés
{QString nom,adresse_mail;
    int id_emp;
    float salaire;
    int nbr_emp;
public:
    employés();
    employés(int,QString,QString);
    QString getnom(){return nom;}
    int getid_emp(){return id_emp;}
    QString getaddresse_mail(){return adresse_mail;}
    float getsalaire(){return salaire;}

    void setnom(QString n){nom=n;}
    void setid_emp(int id){id_emp=id;}
    void setadresse_mail(QString adr){adresse_mail=adr;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
};

#endif // ETUDIANTH_H

#ifndef PATIENT_H
#define PATIENT_H
#include <string.h>
#include<QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>


class patient
{

    QString nom,prenom,DDN;
    int  contact,num;
public:
    patient(){}
    patient(QString,QString,QString,int,int);
    //getters
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getDDN(){return DDN;}
    int getcontact() {return contact;}
      int getnum() {return num;}
    //setters
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setDDN(QString d){DDN=d;}
    void setcontact(int contact){this->contact=contact;}
    void setnum(int num){this->num=num;}
    //fonction
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier();
    void chercher(int cn);
    void chercher_num(int nu);
    void chercher_nom_prenom(QString n, QString p);
    QSqlQueryModel* afficher_unepatient();
    QSqlQueryModel* afficher_unpatient_num();
    QSqlQueryModel* afficher_unpatient_nom_prenom();

};
#endif // PATIENT_H*/


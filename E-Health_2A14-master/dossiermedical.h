#ifndef DOSSIERMEDICAL_H
#define DOSSIERMEDICAL_H
#include <string.h>
#include<QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class dossiermedical
{
    int num;
    QString fichier,antecedent,comptes;
public:
    dossiermedical(){}
    dossiermedical(int,QString,QString,QString);
    QString getfichier(){return fichier;}
    int getnum(){return num;}
    QString getantecedent(){return antecedent;}
    QString getcomptes(){return comptes;}
     void setfichier(QString f){fichier=f;}
       void setnum(int n){num=n;}
         void setantecedent(QString a){antecedent=a;}
           void setcomptes(QString c){comptes=c;}
     bool ajouter();
       QSqlQueryModel *afficher();
         bool supprimer(int);
          bool modifier();
};

#endif // DOSSIERMEDICAL_H

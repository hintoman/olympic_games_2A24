#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class employer
{
public:
    employer();
    employer(int,QString,int,QString);
    bool ajouter();
    bool supprimer(int id_emp);
    bool modifier(int id_emp);
    QSqlQueryModel* afficher();
    QSqlQueryModel *Trier(QString );
    QSqlQueryModel * rechercher(int id);


private:
    int id_emp;
    QString nom;
    int salaire;
    QString date_entre;

};

#endif // EMPLOYES_H



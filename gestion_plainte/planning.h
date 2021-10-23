#ifndef planning_H
#define planning_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class planning
{
public:
    planning();
    planning(int,QString,QString,int);
    int getidm();
    QString getnom();
    QString gettype1();
    int getprix1();
    void setidm(int);
    void setnom(QString);
    void settype1(QString);
    void setdate(QString);
    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int idm,QString nom, QString type1,QString date );
        QSqlQueryModel *Trier(QString );
        QSqlQueryModel * rechercher(int idm);



private:
    int idm ;
    QString nom,type1,date;
};

#endif // planning_H

#ifndef AMENDE_H
#define AMENDE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Amende
{
public:
    Amende();
    Amende(int,QString,QString,int);
    int getid_am();
    QString getstatus();
    QString gettype();
    int getprix_am();
    void setid_am(int);
    void setstatus(QString);
    void settype(QString);
    void setprix_am(int);
    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int id_am,QString status, QString type,int prix_am );
        QSqlQueryModel *Trier(QString );
        QSqlQueryModel * rechercher(int id_am);



private:
    int id_am, prix_am ;
    QString status,type;
};

#endif // AMENDE_H

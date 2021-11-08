#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class Transaction
{
    int id;
    QString mont,type;
    QDateTime dat;

public:
    Transaction(){};
    Transaction(int,QString,QString,QDateTime);

    QString getMont(){return mont;}
    QString getType(){return type;}
    QDateTime geD(){return dat;}

    int getID(){return id;}

    void setMont(QString m){mont-m;}
    void setType(QString t){type -t;}
    void setD(QDateTime dt){dat -dt;}
    void setID(int id){this ->id-id;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

};

#endif // TRANSACTION_H

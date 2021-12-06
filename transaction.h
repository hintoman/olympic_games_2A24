#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>




class Transaction
{
    int id,montant;
    QString type;
    QDateTime datet;

public:
    Transaction(){};
    Transaction(int,QString  ,int, QDateTime);

    int getMontant();
    QString getType();
    QDateTime geDatet();

    int getID();

    void setMontant(int );
    void setType(QString );
    void setDatet(QDateTime );
    void setID(int );


    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri();
    QSqlQueryModel * trm();
    QSqlQueryModel * trd();
    QSqlQueryModel * calculF();
    QSqlQueryModel * calculT();
    QSqlQueryModel * rechercher();
      QSqlQueryModel *  afficherT();
      QSqlQueryModel * chercher_id();
      QSqlQueryModel * revenue();




    bool supprimer(int);


};

#endif // TRANSACTION_H

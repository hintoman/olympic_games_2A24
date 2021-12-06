#ifndef DON_H
#define DON_H
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>

class don
{
    int id_don;
    int quantite;
    QString emplacement;
    QString date_prelevement;
    QString cin;
public:
    don();
    don(int,int,QString,QString,QString);

    int get_id(){return id_don;}
    int get_quantite(){return quantite;}
    QString get_emplacement(){return emplacement;}
    QString get_dateprelev(){return date_prelevement;}
    QString get_CIN() {return cin;}


    void set_id(int i){id_don=i;}
    void set_quanite(int q){quantite=q;}
    void set_emplacement(QString e){emplacement=e;}
    void set_dateprelev(QString d){date_prelevement=d;}
    void set_cin(QString c) {cin=c;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel *trier(QString,QString);
    QSqlQueryModel *rechercherID(int input);
    QSqlQueryModel *rechercherQuantite(int input);
    QSqlQueryModel *rechercherDate(QString input);

    int stat1();
    int stat2();
    int stat3();
    int stat4();


};

#endif // DON_H

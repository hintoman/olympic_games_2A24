#ifndef DONNEUR_H
#define DONNEUR_H
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDebug>

class donneur
{
    QString cin;
    QString nom;
    QString prenom;
    QString email;
    QString sexe;
    QString groupesanguin;
    QDate dateprelev;
public:
    donneur();
    donneur(QString,QString,QString,QString,QString,QString,QDate);
    QString get_cin(){return cin;}
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_email(){return email;}
    QString get_sexe(){return sexe;}
    QString get_groupesanguin(){return groupesanguin;}


    void set_cin(int c){cin=c;}
    void set_nom(QString n){nom=n;}
    void set_prenom(QString p){prenom=p;}
    void set_mail(QString m){email=m;}
    void set_sexe(QString s){sexe=s;}

    void set_groupesanguin(QString gs){groupesanguin=gs;}


    bool ajouter();
    QSqlQueryModel * afficher();
    QStringList getCINs();
    QString getDatePrel(QString);
    bool supprimer(int);
    QSqlQueryModel *trier(QString,QString);
    QSqlQueryModel *rechercherNom(QString input);
    QSqlQueryModel *rechercherGroupeS(QString input);
    QSqlQueryModel *rechercherDate(QString input);

};
#endif // DONNEUR_H

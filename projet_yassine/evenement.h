#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class evenement
{
public:
    evenement();
    evenement(int,QString,QString,QString,QString,int);
    int get_code();
    QString get_nom();
    QString get_dates();
    QString get_type();
    QString get_ville();
    int get_prix();



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,int);

    QSqlQueryModel * chercher_type(QString);
    QSqlQueryModel * chercher_ville(QString);
    QSqlQueryModel * trier_code();
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_prix();

private:
    QString nom,dates,type,ville;
    int code,prix;
};

#endif // EVENEMENT_H

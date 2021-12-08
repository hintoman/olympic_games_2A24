#include "evenement.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

evenement::evenement()
{
    code=0;
    nom="";
    dates="";
    type="";
    ville="";
    prix=0;
}
evenement::evenement(int code,QString nom,QString dates,QString type,QString ville,int prix)
{
  this->code=code;
  this->nom=nom;
  this->dates=dates;
  this->type=type;
    this->ville=ville;
    this->prix=prix;
}

int evenement::get_code(){return code;}
QString evenement::get_nom(){return nom;}
QString evenement::get_dates(){return dates ;}
QString evenement::get_type(){return type;}
QString evenement::get_ville(){return ville ;}
int evenement::get_prix(){return prix;}



bool evenement::ajouter()
{
QSqlQuery query;

QString res= QString::number(code);

query.prepare("INSERT INTO evenement (code,nom,dates,type,ville,prix) "
                    "VALUES (:code,:nom,:dates,:type,:ville,:prix)");

query.bindValue(":code",res);
query.bindValue(":nom",nom);
query.bindValue(":dates",dates);
query.bindValue(":type",type);
query.bindValue(":ville",ville);
query.bindValue(":prix",prix);

return    query.exec();
}

QSqlQueryModel * evenement::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dates"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));
return model;
}

bool evenement::supprimer(int code)
{
    QSqlQuery query;


    QString res= QString::number(code);

    query.prepare("Delete from evenement where code= :code");
    query.bindValue(":code", res);
    return    query.exec();
}




bool evenement::modifier(int code,QString nom,QString dates,QString type,QString ville,int prix)
{ QSqlQuery query;
    QString res= QString::number(code);

    query.prepare("update evenement set code=:code,nom=:nom,dates=:dates,type=:type,ville=:ville,prix=:prix where code=:code");
    query.bindValue(":code",res);
    query.bindValue(":nom",nom);
    query.bindValue(":dates",dates);
    query.bindValue(":type",type);
    query.bindValue(":ville",ville);
    query.bindValue(":prix",prix);


    return    query.exec();

}

QSqlQueryModel * evenement::chercher_type(QString N )
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM evenement WHERE type ='"+N+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("dates"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

    return model ;
}
QSqlQueryModel * evenement::chercher_ville(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM evenement WHERE ville ='"+N+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dates"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

    return model ;
}
QSqlQueryModel * evenement::trier_code()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM evenement ORDER BY code asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dates"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
QSqlQueryModel * evenement::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM evenement ORDER BY nom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dates"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
QSqlQueryModel * evenement::trier_prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM evenement ORDER BY prix asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dates"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

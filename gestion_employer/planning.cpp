#include "planning.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Materiel::Materiel()
{
idm=0;
prix1=0;
nom=" ";
type1=" ";
}

Materiel::Materiel(int idm ,QString nom ,QString type1, int prix1){
    this->idm=idm;
    this->nom=nom;
    this->type1=type1;
    this->prix1=prix1;
}

int Materiel::getidm(){
return idm;
}
QString Materiel::getnom(){
return nom;
}
QString Materiel::gettype1(){
return type1;
}
void Materiel::setidm(int idm ){
this->idm=idm;
}
void Materiel::setnom(QString nom ){
this->nom=nom;
}
int Materiel::getprix1(){
return prix1;
}

void Materiel::settype1(QString type1){
this->type1=type1;
}
bool Materiel::ajouter(){
    QSqlQuery query;
    QString idm_string= QString::number(idm);
     QString prix_string= QString::number(prix1);
          query.prepare("INSERT INTO materiel (idm, nom, type,prix) "
                        "VALUES (:idm, :nom, :type, :prix)");
          query.bindValue(":idm", idm_string);
          query.bindValue(":nom", nom);
          query.bindValue(":type", type1);
          query.bindValue(":prix", prix_string);
         return query.exec();

                        }

QSqlQueryModel * Materiel::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("select * from materiel");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("idm"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

    return model;

}
bool Materiel::supprimer(int idm){
    QSqlQuery query;
          query.prepare("Delete from materiel where idm=:idm ");
          query.bindValue(0, idm);

         return query.exec();
}

bool Materiel::modifier(int idm,QString nom, QString type1,int prix1 )
{
    QSqlQuery query;
    //QString id= QString::number(idm);

    query.prepare("update materiel set idm=:idm, nom=:nom,type=:type,prix=:prix where idm=:idm");
    query.bindValue(":idm", idm);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type1);
    query.bindValue(":prix",prix1);



    return query.exec();
}
QSqlQueryModel * Materiel::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="idm"){
         model->setQuery("SELECT * FROM materiel ORDER BY idm DESC ");
    }
    else if(choix1=="nom"){
         model->setQuery("SELECT * FROM materiel ORDER BY nom ");
    }
    else if(choix1=="type"){
        model->setQuery("SELECT * FROM materiel ORDER BY type  ");
    }
    else if(choix1=="prix"){
        model->setQuery("SELECT * FROM materiel ORDER BY prix DESC ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idm"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

return model;
}


QSqlQueryModel * Materiel::rechercher(int idm)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from materiel where (id LIKE id='"+QString::number(idm)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idm"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
         return model;
}

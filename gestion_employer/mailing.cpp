#include "mailing.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDateEdit>


Plainte::Plainte()
{
id_pl=0;
cin=0;
nom_accuse="";
type="";
}

Plainte::Plainte(int id_pl ,QString nom_accuse ,QString type, int cin, QDate date_debut){
    this->id_pl=id_pl;
    this->nom_accuse=nom_accuse;
    this->type=type;
    this->cin=cin;
    this->date_debut=date_debut;

}

int Plainte::getid_pl(){
return id_pl;
}
QString Plainte::getnom_accuse(){
return nom_accuse;
}
QString Plainte::gettype(){
return type;
}

QDate Plainte:: getdate_debut(){return date_debut;}

void Plainte::setid_pl(int id_pl ){
this->id_pl=id_pl;
}
void Plainte::setnom_accuse(QString nom_accuse ){
this->nom_accuse=nom_accuse;
}
int Plainte::getcin(){
return cin;
}

void Plainte::settype(QString type){
this->type=type;
}
void Plainte::setdate_debut(QDate date_debut){this->date_debut=date_debut;}

bool Plainte::ajouter(){
    QSqlQuery query;
    QString id_string= QString::number(id_pl);
     QString cin_string= QString::number(cin);
          query.prepare("INSERT INTO plainte (id_pl, nom_accuse, type,cin,date_debut) "
                        "VALUES (:id_pl, :nom_accuse, :type, :cin, :date_debut)");
          query.bindValue(":id_pl", id_string);
          query.bindValue(":nom_accuse", nom_accuse);
          query.bindValue(":type", type);
          query.bindValue(":cin", cin_string);
          query.bindValue(":date_debut", date_debut);

         return query.exec();





                        }

QSqlQueryModel * Plainte::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("select * from plainte");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_pl"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_accuse"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));


    return model;

}
bool Plainte::supprimer(int id_pl){
    QSqlQuery query;
          query.prepare("Delete from plainte where id_pl=:id ");
          query.bindValue(0, id_pl);

         return query.exec();
}


bool Plainte::modifier(int id_pl,QString nom_accuse, QString type,int cin,QDate date_debut)
{
    QSqlQuery query;
    //QString id= QString::number(id);

    query.prepare("update plainte set id_pl=:id_pl, nom_accuse=:nom_accuse,type=:type,cin=:cin,date_debut=:date_debut where id_pl=:id_pl");
    query.bindValue(":id_pl", id_pl);
    query.bindValue(":nom_accuse",nom_accuse);
    query.bindValue(":type",type);
    query.bindValue(":cin",cin);
    query.bindValue(":date_debut",date_debut);




    return query.exec();
}
QSqlQueryModel * Plainte::rechercher(int id_pl)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from PLAINTE where (id_pl LIKE id_pl='"+QString::number(id_pl)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_pl"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_accuse "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));

         return model;
}



QSqlQueryModel * Plainte::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id"){
         model->setQuery("SELECT * FROM plainte ORDER BY id_pl  ");
    }
    else if(choix1=="nom"){
         model->setQuery("SELECT * FROM plainte ORDER BY nom_accuse ");
    }
    else if(choix1=="type"){
        model->setQuery("SELECT * FROM plainte ORDER BY type  ");
    }
    else if(choix1=="cin"){
        model->setQuery("SELECT * FROM plainte ORDER BY cin  ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_pl"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_accuse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));



return model;
}

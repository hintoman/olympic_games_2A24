#include "mailing.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDateEdit>


mailing::mailing()
{
id_pl=0;
salaire=0;
nom_accuse="";
}

mailing::mailing(int id_pl ,QString nom_accuse ,int salaire, QDate date_debut){
    this->id_pl=id_pl;
    this->nom_accuse=nom_accuse;
    this->salaire=salaire;
    this->date_debut=date_debut;

}

int mailing::getid_pl(){
return id_pl;
}
QString mailing::getnom_accuse(){
return nom_accuse;
}
int mailing::getsalaire(){
return salaire;
}

QDate mailing:: getdate_debut(){return date_debut;}

void mailing::setid_pl(int id_pl ){
this->id_pl=id_pl;
}
void mailing::setnom_accuse(QString nom_accuse ){
this->nom_accuse=nom_accuse;
}


void mailing::setsalaire(int salaire){
this->salaire=salaire;
}
void mailing::setdate_debut(QDate date_debut){this->date_debut=date_debut;}

bool mailing::ajouter(){
    QSqlQuery query;
    QString id_string= QString::number(id_pl);

          query.prepare("INSERT INTO gs_employer (id_pl, nom_accuse ,salaire,date_entre) "
                        "VALUES (:id_pl, :nom_accuse, :salaire,  :date_entre)");
          query.bindValue(":id_pl", id_string);
          query.bindValue(":nom_accuse", nom_accuse);
          query.bindValue(":salaire", salaire);
          query.bindValue(":date_debut", date_debut);

         return query.exec();





                        }

QSqlQueryModel * mailing::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("select * from gs_employer");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_pl"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_accuse"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));


    return model;

}
bool mailing::supprimer(int id_pl){
    QSqlQuery query;
          query.prepare("Delete from gs_employer where id_pl=:id ");
          query.bindValue(0, id_pl);

         return query.exec();
}


bool mailing::modifier(int id_pl,QString nom_accuse, int salaire,QDate date_debut)
{
    QSqlQuery query;
    //QString id= QString::number(id);

    query.prepare("update gs_employer set id_pl=:id_pl, nom_accuse=:nom_accuse,type=:type,cin=:cin,date_debut=:date_debut where id_pl=:id_pl");
    query.bindValue(":id_pl", id_pl);
    query.bindValue(":nom_accuse",nom_accuse);

    query.bindValue(":salaire",salaire);
    query.bindValue(":date_debut",date_debut);




    return query.exec();
}
QSqlQueryModel * mailing::rechercher(int id_pl)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from gs_employer where (id_pl LIKE id_pl='"+QString::number(id_pl)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_pl"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_accuse "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));

         return model;
}



QSqlQueryModel * mailing::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id"){
         model->setQuery("SELECT * FROM gs_employer ORDER BY id_pl  ");
    }
    else if(choix1=="nom"){
         model->setQuery("SELECT * FROM gs_employer ORDER BY nom_accuse ");
    }

    else if(choix1=="salaire"){
        model->setQuery("SELECT * FROM gs_employer ORDER BY salaire  ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_pl"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_accuse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));



return model;
}

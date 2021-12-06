#include "patient.h"
#include"connection.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>



patient::patient (QString nom,QString prenom,QString DDN,int contact,int num)
{
    this->nom=nom;
    this->prenom=prenom;
    this->DDN=DDN;
    this->contact=contact;
    this->num=num;
}

bool patient::ajouter()
{
QSqlQuery query;
QString num_string=QString::number(num);
QString contact_string=QString::number(contact);
query.prepare("INSERT INTO patientees (NOM,PRENOM,DDN,CONTACT,NUM) "
              "VALUES (:nom, :prenom,:DDN,:contact,:num)");

query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":DDN",DDN);
query.bindValue(":contact",contact_string);
query.bindValue(":num",num_string);
return query.exec();
}



QSqlQueryModel* patient::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM patientees");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("contact"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));

  return  model;
}



bool patient::supprimer(int num)
{
    QSqlQuery query;
         query.prepare(" Delete from patientees where num=:num");
         query.bindValue(":num", num);

        return query.exec();

}



bool patient::modifier()
{

 QSqlQuery query ;

 query.prepare("update patientees set NOM=:nom, PRENOM=:prenom,DDN=:DDN,CONTACT=:contact,NUM=:num where NOM=:nom");

 query.bindValue(":nom", nom);
 query.bindValue(":prenom", prenom);
 query.bindValue(":DDN", DDN);
 query.bindValue(":contact", contact);
 query.bindValue(":num", num);

 return query.exec();
}

void patient::chercher(int cn)
{

    QSqlQuery query1;
    query1.prepare("select * from patientees where CONTACT=:cn ");
    query1.bindValue(":cn",cn);//trueorfalse

    query1.exec();
    while(query1.next())
    {
    nom = query1.value(0).toString();
    prenom = query1.value(1).toString();
    DDN=query1.value(2).toString();
    contact=query1.value(3).toInt();
    num=query1.value(4).toInt();
    }

}
void patient::chercher_num(int nu)
{
    QSqlQuery query1;
    query1.prepare("select * from patientees where NUM=:nu ");
    query1.bindValue(":nu",nu);
    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        prenom = query1.value(1).toString();
        DDN=query1.value(2).toString();
        contact=query1.value(3).toInt();
        num=query1.value(4).toInt();
    }


}
void patient::chercher_nom_prenom(QString n, QString p)
{
    QSqlQuery query1;
    query1.prepare("select * from patientees where nom=:n and prenom=:p ");
    query1.bindValue(":n",n);
    query1.bindValue(":p",p);
    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        prenom = query1.value(1).toString();
        DDN=query1.value(2).toString();
        contact=query1.value(3).toInt();
        num=query1.value(4).toInt();
    }
}
QSqlQueryModel* patient::afficher_unepatient()

{
  QSqlQueryModel* model=new QSqlQueryModel();


  QString cn;
cn= QString::number(contact);

   model->setQuery("SELECT* FROM patientees where contact='"+cn+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("contact"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));

   return  model;
}
QSqlQueryModel* patient::afficher_unpatient_num()
{
  QSqlQueryModel* model=new QSqlQueryModel();


    QString nums;
  nums= QString::number(num);

   model->setQuery("SELECT* FROM patientees where num='"+nums+"'  ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("contact"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));


   return  model;
}
QSqlQueryModel* patient::afficher_unpatient_nom_prenom()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM patientees where NOM='"+nom+"' and PRENOM='"+prenom+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("contact"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));


   return  model;
}



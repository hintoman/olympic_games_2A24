#include "machine.h"
#include"connection.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>




machine::machine()
{
    nom="";
    reference=0;
    num=0;
}
machine::machine(QString nom,int reference ,int num  )
{
    this->nom=nom;
    this->reference=reference ;
    this->num=num;
}
QString machine::get_nom(){return nom;}
int  machine::get_num(){return num ;}
int  machine::get_reference(){return reference;}


bool  machine::ajouter()
{

    QSqlQuery query;
  QString num_string= QString::number(num);
  QString reference_string= QString::number(reference);

         query.prepare("INSERT INTO  machines (Nom,Reference,num ) "
                       "VALUES (:nom,:reference,:num  )");

         query.bindValue(":nom", nom);
         query.bindValue(":num", num);
         query.bindValue(":reference", reference);


        return query.exec();

}
bool machine::supprimer(int reference)
{
    QSqlQuery query;
         query.prepare("DELETE from  machines where Reference=:reference");
         query.bindValue(":reference", reference);
        return query.exec();


}

QSqlQueryModel* machine::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM  machines");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));

  return  model;
}


bool machine::modifier()
{

 QSqlQuery query ;

 query.prepare("update  machines set Nom=:nom, num=:num ,Reference=:reference where Reference=:reference");

 query.bindValue(":num",num);
 query.bindValue(":nom",nom);
 query.bindValue(":reference", reference);


 return query.exec();

}

void machine::chercher_nom_num(int c,QString n)
{

    QSqlQuery query1;
    query1.prepare("select * from  machines where num=? and Nom=?");
    //query1.bindValue(":c",c);
    //query1.bindValue(":n",n);
    query1.addBindValue(c);
    query1.addBindValue(n);
    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        reference= query1.value(1).toInt();
        num=query1.value(2).toInt();
    }

}
void machine::chercher_reference(int c)
{
    QSqlQuery query1;
    query1.prepare("select * from  machines where Reference=:c ");
    query1.bindValue(":c",c);
    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        reference= query1.value(1).toInt();
        num=query1.value(2).toInt();

    }


}
void machine::chercher_nom(QString n)
{
    QSqlQuery query1;
    query1.prepare("select * from  machines where Nom=:n");
    query1.bindValue(":n",n);

    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        reference= query1.value(1).toInt();
        num=query1.value(2).toInt();


    }


}

QSqlQueryModel* machine::afficher_nom()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM  machines where Nom='"+nom+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));

   return  model;
}
QSqlQueryModel* machine::afficher_reference()
{
  QSqlQueryModel* model=new QSqlQueryModel();

    QString ref;
  ref= QString::number(reference);

   model->setQuery("SELECT* FROM  machines where Reference='"+ref+"'  ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));

    return  model;
}


QSqlQueryModel* machine::afficher_nom_num()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  QString nume;
  nume= QString::number(num);
  model->setQuery("SELECT* FROM  machines where Nom='"+nom+"' and num='"+nume+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));



   return  model;
}


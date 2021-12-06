#include "medicaments.h"

medicament::medicament()
{
    nom="";
    reference=0;
    num=0;

}
medicament::medicament(QString nom,int reference ,int num  )
{
    this->nom=nom;
    this->reference=reference ;
    this->num=num;
}
QString medicament::get_nom(){return nom;}
int  medicament::get_num(){return num ;}
int  medicament::get_reference(){return reference;}


bool  medicament::ajouter()
{

    QSqlQuery query;
  QString num_string= QString::number(num);
  QString reference_string= QString::number(reference);

         query.prepare("INSERT INTO MEDICAMENTS (Nom,Reference,num ) "
                       "VALUES (:nom,:reference,:num  )");

         query.bindValue(":nom", nom);
         query.bindValue(":num", num);
         query.bindValue(":reference", reference);


        return query.exec();

}
bool medicament::supprimer(int reference)
{
    QSqlQuery query;
         query.prepare("DELETE from MEDICAMENTS where Reference= :reference");
         query.bindValue(":reference", reference);
        return query.exec();


}

QSqlQueryModel* medicament::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM MEDICAMENTS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));

  return  model;
}


bool medicament::modifier()
{

 QSqlQuery query ;

 query.prepare("update MEDICAMENTS set Nom=:nom, num=:num ,Reference=:reference where Reference=:reference");

 query.bindValue(":num",num);
 query.bindValue(":nom",nom);
 query.bindValue(":reference", reference);


 return query.exec();

}

void medicament::chercher_nom_num(int c,QString n)
{

    QSqlQuery query1;
    query1.prepare("select * from MEDICAMENTS where num=:c and Nom=:n");
    query1.bindValue(":c",c);
    query1.bindValue(":n",n);

    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        reference= query1.value(1).toInt();
        num=query1.value(2).toInt();
    }

}
void medicament::chercher_reference(int c)
{
    QSqlQuery query1;
    query1.prepare("select * from MEDICAMENTS where Reference=:c ");
    query1.bindValue(":c",c);
    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        reference= query1.value(1).toInt();
        num=query1.value(2).toInt();

    }


}
void medicament::chercher_nom(QString n)
{
    QSqlQuery query1;
    query1.prepare("select * from MEDICAMENTS where Nom=:n");
    query1.bindValue(":n",n);

    query1.exec();
    while(query1.next())
    {
        nom = query1.value(0).toString();
        reference= query1.value(1).toInt();
        num=query1.value(2).toInt();


    }


}

QSqlQueryModel* medicament::afficher_nom()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM MEDICAMENTS where Nom='"+nom+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));

   return  model;
}
QSqlQueryModel* medicament::afficher_reference()
{
  QSqlQueryModel* model=new QSqlQueryModel();

    QString ref;
  ref= QString::number(reference);

   model->setQuery("SELECT* FROM MEDICAMENTS where Reference='"+ref+"'  ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));

    return  model;
}


QSqlQueryModel* medicament::afficher_nom_num()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  QString nume;
  nume= QString::number(num);
  model->setQuery("SELECT* FROM MEDICAMENTS where Nom='"+nom+"' and num='"+nume+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));



   return  model;
}

#include "dossiermedical.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>

dossiermedical::dossiermedical(int num,QString fichier,QString antecedent,QString comptes)
{
    this->num=num;
    this->fichier=fichier;
    this->antecedent=antecedent;
    this->comptes=comptes;

}


bool dossiermedical::ajouter()
{

QSqlQuery query;
QString num_string=QString::number(num);

query.prepare("INSERT INTO dossier (NUM,FICHIER,ANTECEDENT,COMPTES)"
              "VALUES (:num, :fichier,:antecedent,:comptes)");

query.bindValue(":num",num_string);
query.bindValue(":fichier",fichier);
query.bindValue(":antecedent",antecedent);
query.bindValue(":comptes",comptes);
return query.exec();
}

QSqlQueryModel* dossiermedical::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM dossier");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("fichier"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("antecedent"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("comptes"));
;

  return  model;
}
bool dossiermedical::supprimer(int num)
{
    QSqlQuery query;
         query.prepare(" Delete from dossier where num=:num");
         query.bindValue(":num", num);

        return query.exec();


}
bool dossiermedical::modifier()
{

 QSqlQuery query ;

 query.prepare("update DOSSIER set NUM=:num, FICHIER=:fichier,ANTECEDENT=:antecedent,COMPTES=:comptes where FICHIER=:fichier");

 query.bindValue(":num", num);
 query.bindValue(":fichier", fichier);
 query.bindValue(":antecedent", antecedent);
 query.bindValue(":comptes", comptes);


 return query.exec();
}


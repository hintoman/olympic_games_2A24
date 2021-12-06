//ze have classe /methodes:ajout,supp,modi,afficha
#include "sponsor.h"

sponsor::sponsor()
{

}

sponsor::sponsor(QString s1,QString s2,QString s3,QString s4, double x){

    id=s1;
    nom=s2;
    adresse=s3;
    type=s4;
    montant=x;

}


bool sponsor::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO sponsors (ID,NOM,ADRESSE,TYPE,MONTANT) VALUES (:id,:nom,:adresse,:type,:montant)");

    query.bindValue(":id", id);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":type",type);
    query.bindValue(":montant",montant);

    return    query.exec();

}

bool sponsor::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE sponsors SET  TYPE=:type, NOM=:nom, ADRESSE=:adresse, MONTANT=:montant"
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":type",type);
    query.bindValue(":montant",montant);


    return    query.exec();

}

 QSqlQueryModel * sponsor::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM sponsors");

     return modal;

 }
  bool sponsor::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from sponsors where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }

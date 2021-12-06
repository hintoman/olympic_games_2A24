#include "terrain.h"

terrain::terrain()
{

}

terrain::terrain(QString s1,QString s2,QString s3,QString s4, int x){

    id=s1;
    nom=s2;
    lieu=s3;
    etat=s4;
    capacite=x;

}


bool terrain::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO terrain (ID,NOM,lieu,etat,capacite) VALUES (:id,:nom,:lieu,:etat,:capacite)");

    query.bindValue(":id", id);
    query.bindValue(":nom",nom);
    query.bindValue(":lieu",lieu);
    query.bindValue(":etat",etat);
    query.bindValue(":capacite",capacite);

    return    query.exec();

}

bool terrain::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE terrain SET  lieu=:lieu, NOM=:nom, etat=:etat, capacite=:capacite"
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":nom",nom);
    query.bindValue(":lieu",lieu);
    query.bindValue(":etat",etat);
    query.bindValue(":capacite",capacite);


    return    query.exec();

}

 QSqlQueryModel * terrain::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM terrain");

     return modal;

 }
  bool terrain::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from terrain where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }

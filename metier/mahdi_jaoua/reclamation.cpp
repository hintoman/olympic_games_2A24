#include "reclamation.h"

reclamation::reclamation()
{

}

reclamation::reclamation(QString s1,QString s2,QString s3, QString s4){

    id=s1;
    description=s2;
    mail=s3;
    etat=s4;

}


bool reclamation::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO reclamation (ID,description,mail,etat) VALUES (:id,:description,:mail,:etat)");

    query.bindValue(":id", id);
    query.bindValue(":description",description);
    query.bindValue(":mail", mail);
    query.bindValue(":etat",etat);

    return    query.exec();

}

bool reclamation::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE reclamation SET  description=:description, mail=:mail, etat=:etat where ID= :id");
    query.bindValue(":id", selected);
query.bindValue(":description",description);
query.bindValue(":mail", mail);
query.bindValue(":etat",etat);

    return    query.exec();

}

 QSqlQueryModel * reclamation::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM reclamation");

     return modal;

 }
  bool reclamation::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from reclamation where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }

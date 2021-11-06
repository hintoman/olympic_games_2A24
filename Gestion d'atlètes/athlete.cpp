#include "athlete.h"
#include<QString>
#include<QObject>
#include<QSqlQuery>
#include<QDebug>
#include<QRegularExpression>
Athlete::Athlete()
{
 id=0;age="" ;num_tel=0; nom="";prenom="";fliere="";Email="";
}
Athlete::Athlete(int id ,int num_tel,QString age, QString nom, QString prenom,QString fliere,QString Email)
{this->id=id;this->age=age;this->num_tel=num_tel;this->nom=nom;this->prenom=prenom;this->fliere=fliere;this->Email=Email;}

int Athlete::getid(){return id;}
void Athlete::setid(int id){this->id=id;}
 QString Athlete::getage(){return age;}
 void Athlete::setage(QString age){this->age=age;}
 QString Athlete::getnom(){return nom;}
 void Athlete::setnom(QString nom){this->nom=nom;}
 QString Athlete::getprenom(){return prenom;}
 void Athlete::setprenom(QString prenom){this->prenom=prenom;}
 QString Athlete::getEmail(){return Email;}
 void Athlete::setEmail(QString Email){this->Email=Email;}
 QString Athlete::getfliere(){return fliere;}
 void Athlete::setfliere(QString fliere){this->fliere=fliere;}
 bool Athlete::Email_validation(QString email)
 {
     bool retorno = true;

     qDebug() << email;

     QRegularExpression regex("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");

     if(!regex.match(email).hasMatch())
     {
         retorno = false;
     }

     return retorno;
 }

 bool Athlete::Ajouter()
 {
     QSqlQuery query;
     QString id_string = QString::number(id);
      QString num_tel_string = QString::number(num_tel);
           query.prepare("INSERT INTO GS_ATHÈTES (ID,NOM,PRENOM,AGE, FILIERE,EMAIL,TELEPHONE) "
                         "VALUES (:0,:1, :2 , :3 , :4, :5, :6)");
           query.bindValue(":0", id_string);
           query.bindValue(":6", num_tel_string);
           query.bindValue(":3", age);
           query.bindValue(":1", nom);
           query.bindValue(":2", prenom);
           query.bindValue(":4", fliere);
           query.bindValue(":5", Email);

           return query.exec();


}

 QSqlQueryModel* Athlete::affichier()
 {
     QSqlQueryModel* model=new QSqlQueryModel ;

         model->setQuery("SELECT* FROM GS_ATHÈTES");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identiant"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero telephone"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de naissance "));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("filiere"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));




             return model;
 }
 bool Athlete::supprimer(int)
 {
     QSqlQuery query;
     query.prepare("Delete from GS_ATHÈTES where id =:id" );
     query.bindValue(0, id);



     return query.exec();




 }



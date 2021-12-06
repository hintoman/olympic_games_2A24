#include "athlete.h"
#include<QString>
#include "gestion_montasar.h"
#include "ui_mainwindow.h"
#include<QObject>
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include <QListView>
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
 QSqlQueryModel * Athlete::triid()

 {
     QSqlQueryModel* model=new QSqlQueryModel ;

         model->setQuery("SELECT*  FROM GS_ATHÈTES ORDER BY ID ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identiant"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero telephone"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de naissance "));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("filiere"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
             return model;
 }
 QSqlQueryModel * Athlete::trinom()

 {
     QSqlQueryModel* model=new QSqlQueryModel ;

         model->setQuery("SELECT*  FROM GS_ATHÈTES ORDER BY NOM ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identiant"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero telephone"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de naissance "));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("filiere"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
             return model;
 }
 QSqlQueryModel * Athlete::tridate()

 {
     QSqlQueryModel* model=new QSqlQueryModel ;

         model->setQuery("SELECT*  FROM GS_ATHÈTES ORDER BY AGE");
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

 bool Athlete::modifier()
 {



         QSqlQuery query;
         QString id_string = QString::number(id);
          QString num_tel_string = QString::number(num_tel);
         query.prepare("UPDATE GS_ATHÈTES SET ID=:id, NOM=:nom,PRENOM=:prenom,AGE=:age,FILIERE=:fliere,EMAIL=:Email,TELEPHONE=:telephone where ID =:id");
         query.bindValue(":id",id_string);
         query.bindValue(":nom",nom);
          query.bindValue(":prenom",prenom);
          query.bindValue(":age",age);
          query.bindValue(":fliere",fliere);
         query.bindValue(":telephone",num_tel_string);
         query.bindValue(":Email",Email);


         return query.exec();


 }


/*Athlete* Athlete::getAthleteById(int id) {

     Athlete * m = new Athlete();

     QString cmd = "select ID, NOM, PRENOM,TELEPHONE from GS_ATHÈTES where id = :id;";
     QSqlQuery query;
     query.prepare(cmd);
     query.bindValue(":id", id);
     query.exec();

     if (query.next()){
         qDebug()<< query.value(0) << query.value(1)<< query.value(2)<<query.value(3)<<query.value(4)<<query.value(5)<<query.value(6);
         m->id = query.value(0).toInt();
         m->nom = query.value(1).toString();
         m->prenom = query.value(2).toString();
         m->age = query.value(3).toInt();
         m->fliere = query.value(4).toString();
          m->Email = query.value(5).toString();
           m->num_tel = query.value(6).toInt();
     }
     return m;
 }

 Athlete * Athlete::currentSelectedAthlete = NULL;
 Athlete* Athlete::setCurrentSelectedAthlete(Athlete *m){
         Athlete::currentSelectedAthlete = m;


 }
 QList<Athlete *> Athlete::FindAll(){
     QString cmd = "select * from GS_ATHÈTES;";
     QSqlQuery query;
     query.prepare(cmd);
     query.exec();
     QList<Athlete *> list;
     while (query.next()){
         Athlete * m = new Athlete();
         m->id = query.value("ID").toInt();
         m->nom = query.value("NOM").toString();
         m->prenom = query.value("prenom").toString();
         m->age = query.value("AGE").toInt();
         m->fliere = query.value("FILIERE").toString();
          m->Email = query.value("EMAIL").toString();
           m->num_tel = query.value("TELEPHONE").toInt();



         list << m;
     }
     return list;
 }*/
 QSqlQueryModel* Athlete::chercher(QString cls )
  {




     {QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from GS_ATHÈTES WHERE ID LIKE '"%cls%"' OR NOM LIKE '"%cls%"' OR TELEPHONE LIKE  '"%cls%"' OR EMAIL LIKE '"%cls%"' ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identiant"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero telephone"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de naissance "));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("filiere"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

     return model;
     }}





  ////////////////////////



 /*ModeleTableSql::ModeleTableSql()
 {
 }

 void ModeleTableSql::setOrderByClause(QString orderByClause)
 {
     m_orderClause=orderByClause;
 }

 QString ModeleTableSql::orderByClause() const
 {
     return m_orderClause;
 }**/




 /*QSqlTableModel* Athlete::modifier(){


  Ui::MainWindow *ui;

     const int row = ui->tableWidget->rowCount();
     ui->tableWidget->insertRow(row);
     ui->tableWidget->setItem(row,0, new QTableWidgetItem(id));
     ui->tableWidget->setItem(row,1, new QTableWidgetItem(nom ));
     ui->tableWidget->setItem(row,2, new QTableWidgetItem(prenom));
     ui->tableWidget->setItem(row,3, new QTableWidgetItem(age));
     ui->tableWidget->setItem(row,4, new QTableWidgetItem(fliere ));
     ui->tableWidget->setItem(row,5, new QTableWidgetItem(Email));
     ui->tableWidget->setItem(row,6, new QTableWidgetItem(num_tel));
     return row.exec;

 }*/
 QString Athlete:: printPDF()
 {

     QString text="             ** Les Athletes  **       \n \n " ;
         QSqlQuery query ;
         QString i,x,z,y,e,r,t;


          query.exec("select * from GS_ATHÈTES ");
          while (query.next())
          {
             i=query.value(0).toInt();
              x=query.value(1).toString();
              z=query.value(2).toString();
              y=query.value(3).toInt();
              e=query.value(4).toString();
              r=query.value(5).toString();
              t=query.value(6).toInt();
            text += "\n id: "+i+"\n - nom : "+ x+"\n  - -prenom : "+ z+"\n age: "+y+"\n filiere :"+e+"\n Email:"+r+"\nTelephone:"+t+"\n_____________\n ";



         }

                 return text ;
 }




#include "tache.h"

tache::tache()
{
    salaire=0;
    type_tache="";
    date_debut="";
    date_fin="";

}
tache::tache(QString type_tache,int salaire ,QString date_debut,QString date_fin)
{
    this->type_tache=type_tache;
    this->salaire=salaire;
    this->date_debut=date_debut;
    this->date_fin=date_fin;
}
int tache::get_salaire(){return salaire;}
QString tache::get_type_tache(){return type_tache;}
QString tache::get_date_debut(){return date_debut;}
QString tache::get_date_fin(){return date_fin;}
void tache::set_salaire(int){this->salaire=salaire;}
void tache::set_type_tache(QString){this->type_tache=type_tache;}
void tache::set_date_debut(QString){this->date_debut=date_debut;}
void tache::set_date_fin(QString){this->date_fin=date_fin;}
bool tache::ajouter_tache()
{

    QSqlQuery query;
  QString salaire_string= QString::number(salaire);
         query.prepare("INSERT INTO tache (type_tache,salaire, date_debut,date_fin) "
                       "VALUES (:type_tache, :salaire, :date_debut, :date_fin )");
         query.bindValue(":type_tache",type_tache);
         query.bindValue(":salaire", salaire_string);
         query.bindValue(":date_debut", date_debut);
         query.bindValue(":date_fin", date_fin);


        return query.exec();

}
bool tache::supprimer_tache(QString typee)
{

    QSqlQuery query;
         query.prepare("DELETE from tache where type_tache= :type_tache");
         query.bindValue(":type_tache", typee);
        return query.exec();
}
QSqlQueryModel* tache::afficher_tache()
{
    QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM tache");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("type_tache"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));

    return  model;
}
bool tache::modifier_tache()
{
    QSqlQuery query ;
    QString salaire_string= QString::number(salaire);

    query.prepare("update  tache set  type_tache=:type_tache, salaire=:salaire, date_debut=:date_debut, date_fin=:date_fin where type_tache=:type_tache  ");

    query.bindValue(":type_tache",type_tache);
    query.bindValue(":salaire", salaire);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);

    return query.exec();
}
void tache::chercher_date_debut_type_salaire(QString dd, QString t, int s)
{
    QSqlQuery query1;
    query1.prepare("select * from tache where date_debut=:dd and type_tache=:t and salaire=:s ");
    query1.bindValue(":dd",dd);
    query1.bindValue(":t",t);
    query1.bindValue(":s",s);
    query1.exec();
    while(query1.next())
    {
    type_tache = query1.value(0).toString();
    salaire=query1.value(1).toInt();
    date_debut = query1.value(2).toString();
    date_fin= query1.value(3).toString();

    }
}
void tache::chercher_tache_salaire(int s)
{
    QSqlQuery query1;
    query1.prepare("select * from tache where salaire=:s ");
    query1.bindValue(":s",s);
    query1.exec();
    while(query1.next())
    {
        type_tache = query1.value(0).toString();
        salaire=query1.value(1).toInt();
        date_debut = query1.value(2).toString();
        date_fin= query1.value(3).toString();
    }
}
void tache::chercher_type(QString t)
{
    QSqlQuery query1;
    query1.prepare("select * from tache where type_tache=:t");
    query1.bindValue(":t",t);
    query1.exec();
    while(query1.next())
    {
        type_tache = query1.value(0).toString();
        salaire=query1.value(1).toInt();
        date_debut = query1.value(2).toString();
        date_fin= query1.value(3).toString();
    }

}
QSqlQueryModel* tache::afficher_date_debut_type_salaire()
{
    QSqlQueryModel* model=new QSqlQueryModel();


      QString salaires;
    salaires= QString::number(salaire);

     model->setQuery("SELECT* FROM tache where salaire='"+salaires+"' and date_debut='"+date_debut+"' and type_tache='"+type_tache+"' ");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("type_tache"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));


     return  model;
}
QSqlQueryModel* tache::afficher_tache_salaire()
{
QSqlQueryModel* model=new QSqlQueryModel();


  QString salaires;
salaires= QString::number(salaire);

 model->setQuery("SELECT* FROM tache where salaire='"+salaires+"'  ");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("type_tache"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));

 return  model;
}
QSqlQueryModel* tache::afficher_type()
{

    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM tache where type_tache='"+type_tache+"'  ");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("type_tache"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));

     return  model;
}

/*QSqlQueryModel* EMPLOYE::afficher_employetrier()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   QSqlQuery query;
   query.prepare("SELECT * FROM employe order by cin ");

   query.exec();
   model->setQuery(query);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tache"));
   return  model;
}*/






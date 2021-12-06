#include "EMPLOYE.h"

EMPLOYE::EMPLOYE()
{
    cin=0;
    prenom="";
    nom="";
    mail="";
    DDN="";
    Tache="";
}
EMPLOYE::EMPLOYE(int cin ,QString nom ,QString prenom , QString mail , QString DDN , QString Tache  )
{
    this->cin=cin ;
    this->nom=nom;
    this->prenom=prenom ;
    this->mail=mail;
    this->DDN=DDN ;
    this->Tache=Tache ;

}

int  EMPLOYE::get_cin(){return cin ;}
QString EMPLOYE::get_nom(){return prenom ;}
QString EMPLOYE::get_prenom(){return nom ;}
QString EMPLOYE::get_mail(){return mail;}
QString EMPLOYE::get_DDN(){return DDN ;}
QString EMPLOYE::get_Tache(){return Tache ;}
void EMPLOYE::set_cin(int){this->cin=cin;}
void EMPLOYE::set_nom(QString){this->nom=nom;}
void EMPLOYE::set_prenom(QString){this->prenom=prenom;}
void EMPLOYE::set_mail(QString){this->mail=mail;}
void EMPLOYE::set_DDN(QString){this->DDN=DDN;}
void EMPLOYE::set_Tache(QString){this->Tache=Tache;}

bool  EMPLOYE::ajouter()
{

    QSqlQuery query;
  QString cin_string= QString::number(cin);
         query.prepare("INSERT INTO employe (cin, nom, prenom,mail,DDN,Tache) "
                       "VALUES (:cin, :nom, :prenom , :mail ,:DDN ,:Tache)");
         query.bindValue(":cin",cin_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":mail", mail);
         query.bindValue(":DDN", DDN);
         query.bindValue(":Tache", Tache);

        return query.exec();

}
bool EMPLOYE::supprimer(int cinn)
{
    QSqlQuery query;
         query.prepare("DELETE from employe where cin= :cin");
         query.bindValue(":cin", cinn);
        return query.exec();


}

QSqlQueryModel* EMPLOYE::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM employe");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tache"));

  return  model;
}


bool EMPLOYE::modifier()
{

 QSqlQuery query ;
 QString cin_string= QString::number(cin);

 query.prepare("update  employe set  cin=:cin , nom=:nom, prenom=:prenom,mail=:mail,DDN=:DDN,Tache=:Tache where cin=:cin ");

 query.bindValue(":cin",cin);
 query.bindValue(":nom", nom);
 query.bindValue(":prenom", prenom);
 query.bindValue(":mail", mail);
 query.bindValue(":DDN", DDN);
 query.bindValue(":Tache", Tache);

 return query.exec();

}

void EMPLOYE::chercher(int c,QString n,QString p)
{

    QSqlQuery query1;
    query1.prepare("select * from employe where cin=:c and nom=:n and prenom=:p ");
    query1.bindValue(":c",c);
    query1.bindValue(":n",n);
    query1.bindValue(":p",p);
    query1.exec();
    while(query1.next())
    {
    cin=query1.value(0).toInt();
    nom = query1.value(1).toString();
    prenom = query1.value(2).toString();
    mail = query1.value(3).toString();
    DDN=query1.value(4).toString();
    Tache=query1.value(5).toString();
    }

}
void EMPLOYE::chercher_cin(int c)
{
    QSqlQuery query1;
    query1.prepare("select * from employe where cin=:c ");
    query1.bindValue(":c",c);
    query1.exec();
    while(query1.next())
    {
    cin=query1.value(0).toInt();
    nom = query1.value(1).toString();
    prenom = query1.value(2).toString();
    mail = query1.value(3).toString();
    DDN=query1.value(4).toString();
    Tache=query1.value(5).toString();
    }


}
void EMPLOYE::chercher_nom_prenom(QString n, QString p)
{
    QSqlQuery query1;
    query1.prepare("select * from employe where nom=:n and prenom=:p ");
    query1.bindValue(":n",n);
    query1.bindValue(":p",p);
    query1.exec();
    while(query1.next())
    {
    cin=query1.value(0).toInt();
    nom = query1.value(1).toString();
    prenom = query1.value(2).toString();
    mail = query1.value(3).toString();
    DDN=query1.value(4).toString();
    Tache=query1.value(5).toString();
    }


}

QSqlQueryModel* EMPLOYE::afficher_unemploye()
{
  QSqlQueryModel* model=new QSqlQueryModel();


    QString cins;
  cins= QString::number(cin);

   model->setQuery("SELECT* FROM employe where cin='"+cins+"' and nom='"+nom+"' and prenom='"+prenom+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tache"));


   return  model;
}
QSqlQueryModel* EMPLOYE::afficher_unemploye_cin()
{
  QSqlQueryModel* model=new QSqlQueryModel();


    QString cins;
  cins= QString::number(cin);

   model->setQuery("SELECT* FROM employe where cin='"+cins+"'  ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tache"));


   return  model;
}
QSqlQueryModel* EMPLOYE::afficher_unemploye_nom_prenom()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM employe where nom='"+nom+"' and prenom='"+prenom+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DDN"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tache"));


   return  model;
}
QSqlQueryModel* EMPLOYE::rechercher_2(QString input, QString filtrer)
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT *FROM employe WHERE "+filtrer+" LIKE '%' || :inputValue || '%'");
    query.bindValue(":inputValue",input);
    query.exec();
    modal->setQuery(query);
    return modal;

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






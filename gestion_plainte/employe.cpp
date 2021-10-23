#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDateEdit>


Fournisseur::Fournisseur()
{
id=0;
tel=0;
nom="";
prenom="";
}

Fournisseur::Fournisseur(int id ,QString nom ,QString prenom, int tel){
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
}

int Fournisseur::getid(){
return id;
}
QString Fournisseur::getnom(){
return nom;
}
QString Fournisseur::getprenom(){
return prenom;
}
void Fournisseur::setid(int id ){
this->id=id;
}
void Fournisseur::setnom(QString nom ){
this->nom=nom;
}
int Fournisseur::gettel(){
return tel;
}

void Fournisseur::setprenom(QString prenom){
this->prenom=prenom;
}
bool Fournisseur::ajouter(){
    QSqlQuery query;
    QString id_string= QString::number(id);
     QString tel_string= QString::number(tel);
          query.prepare("INSERT INTO fourniseur (id, nom, prenom,tel) "
                        "VALUES (:id, :nom, :prenom, :tel)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":tel", id_string);
         return query.exec();

                        }

QSqlQueryModel * Fournisseur::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("select * from fourniseur");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));

    return model;

}
bool Fournisseur::supprimer(int id){
    QSqlQuery query;
          query.prepare("Delete from fourniseur where id=:id ");
          query.bindValue(0, id);

         return query.exec();
}


bool Fournisseur::modifier(int id,QString nom, QString prenom,int tel )
{
    QSqlQuery query;
    //QString id= QString::number(id);

    query.prepare("update fourniseur set id=:id, nom=:nom,prenom=:prenom,tel=:tel where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);



    return query.exec();
}
QSqlQueryModel * Fournisseur::rechercher(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from fourniseur where (id LIKE id='"+QString::number(id)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
         return model;
}



QSqlQueryModel * Fournisseur::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id"){
         model->setQuery("SELECT * FROM fourniseur ORDER BY id DESC ");
    }
    else if(choix1=="nom"){
         model->setQuery("SELECT * FROM fourniseur ORDER BY nom ");
    }
    else if(choix1=="prenom"){
        model->setQuery("SELECT * FROM fourniseur ORDER BY prenom  ");
    }
    else if(choix1=="tel"){
        model->setQuery("SELECT * FROM fourniseur ORDER BY tel DESC ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));

return model;
}

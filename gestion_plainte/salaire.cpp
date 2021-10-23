#include "salaire.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Amende::Amende()
{
id_am=0;
prix_am=0;
status=" ";
type=" ";
}

Amende::Amende(int id_am ,QString status ,QString type, int prix_am){
    this->id_am=id_am;
    this->status=status;
    this->type=type;
    this->prix_am=prix_am;
}

int Amende::getid_am(){
return id_am;
}
QString Amende::getstatus(){
return status;
}
QString Amende::gettype(){
return type;
}
void Amende::setid_am(int id_am ){
this->id_am=id_am;
}
void Amende::setstatus(QString status ){
this->status=status;
}
int Amende::getprix_am(){
return prix_am;
}

void Amende::settype(QString type){
this->type=type;
}
bool Amende::ajouter(){
    QSqlQuery query;
    QString id_string= QString::number(id_am);
     QString prix_string= QString::number(prix_am);
          query.prepare("INSERT INTO amendes (id_am, status, type,prix_am) "
                        "VALUES (:id_am, :status, :type, :prix_am)");
          query.bindValue(":id_am", id_string);
          query.bindValue(":status", status);
          query.bindValue(":type", type);
          query.bindValue(":prix_am", prix_string);
         return query.exec();

                        }

QSqlQueryModel * Amende::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("select * from amendes");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_am"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_am"));

    return model;

}
bool Amende::supprimer(int id_am){
    QSqlQuery query;
          query.prepare("Delete from amendes where id_am=:id_am ");
          query.bindValue(0, id_am);

         return query.exec();
}

bool Amende::modifier(int id_am,QString status, QString type,int prix_am )
{
    QSqlQuery query;
    //QString id= QString::number(id_am);

    query.prepare("update amendes set id_am=:id_am, status=:status,type=:type,prix_am=:prix_am where id_am=:id_am");
    query.bindValue(":id_am", id_am);
    query.bindValue(":status",status);
    query.bindValue(":type",type);
    query.bindValue(":prix_am",prix_am);



    return query.exec();
}
QSqlQueryModel * Amende::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id_am"){
         model->setQuery("SELECT * FROM amendes ORDER BY id_am  ");
    }
    else if(choix1=="status"){
         model->setQuery("SELECT * FROM amendes ORDER BY status ");
    }
    else if(choix1=="type"){
        model->setQuery("SELECT * FROM amendes ORDER BY type  ");
    }
    else if(choix1=="prix_am"){
        model->setQuery("SELECT * FROM amendes ORDER BY prix_am  ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_am"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_am"));

return model;
}


QSqlQueryModel * Amende::rechercher(int id_am)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from amendes where (id LIKE id_am='"+QString::number(id_am)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_am"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("status "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_am"));
         return model;
}

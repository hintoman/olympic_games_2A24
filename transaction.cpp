#include "transaction.h"

Transaction::Transaction(int id,QString type ,int montant,QDateTime datet)
{
this->id = id;
    this->montant = montant;
    this->type = type;
    this->datet = datet;



}

void Transaction :: setID(int id){this->id = id;}
void Transaction :: setMontant(int montant){this->montant = montant;}
void Transaction :: setType(QString type){this->type = type;}
void Transaction :: setDatet(QDateTime datet){this->datet = datet;}

int Transaction :: getMontant(){return  montant;}
QString Transaction :: getType(){return type;}

QDateTime Transaction::geDatet(){return datet;}

int Transaction::getID(){return id;}

bool Transaction :: ajouter(){

    QSqlQuery query;
    QString res = QString :: number(id);
    QString ris = QString :: number(montant);


    query.prepare("insert into transaction(id,montant,type,datet)" "values(:ID,:MONTANT,:TYPE,:DATET)");
query.bindValue(":ID",res);
query.bindValue(":MONTANT",ris);
query.bindValue(":TYPE",type);
query.bindValue(":DATET",datet);


return query.exec();
}
QSqlQueryModel * Transaction:: afficher(){

    QSqlQueryModel* model = new QSqlQueryModel ();

    model-> setQuery("select * from transaction");
    model-> setHeaderData(0,Qt:: Horizontal,QObject::tr("id"));
    model-> setHeaderData(1,Qt:: Horizontal,QObject::tr("type"));
    model-> setHeaderData(2,Qt:: Horizontal,QObject::tr("montant"));
    model-> setHeaderData(3,Qt:: Horizontal,QObject::tr("datet"));

    return model;
}

bool Transaction :: supprimer(int id){

    QSqlQuery query;
    QString res = QString :: number(id);
    query.prepare("Delete from database transaction where id =:id");
    query.bindValue(":ID",res);

    return query.exec();


}
QSqlQueryModel * Transaction:: tri(){
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from transaction ORDER BY type asc ");
       model-> setHeaderData(0,Qt:: Horizontal,QObject::tr("id"));
       model-> setHeaderData(1,Qt:: Horizontal,QObject::tr("type"));
       model-> setHeaderData(2,Qt:: Horizontal,QObject::tr("montant"));
       model-> setHeaderData(3,Qt:: Horizontal,QObject::tr("datet"));


           return model;
}
QSqlQueryModel * Transaction:: trm(){
    QSqlQueryModel * model= new QSqlQueryModel();

                            model->setQuery("select * from transaction ORDER BY montant asc ");
                            model-> setHeaderData(0,Qt:: Horizontal,QObject::tr("id"));
                            model-> setHeaderData(1,Qt:: Horizontal,QObject::tr("type"));
                            model-> setHeaderData(2,Qt:: Horizontal,QObject::tr("montant"));
                            model-> setHeaderData(3,Qt:: Horizontal,QObject::tr("datet"));


                                          return model;}
QSqlQueryModel * Transaction::trd(){
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from transaction ORDER BY datet asc ");
       model-> setHeaderData(0,Qt:: Horizontal,QObject::tr("id"));
       model-> setHeaderData(1,Qt:: Horizontal,QObject::tr("type"));
       model-> setHeaderData(2,Qt:: Horizontal,QObject::tr("montant"));
       model-> setHeaderData(3,Qt:: Horizontal,QObject::tr("datet"));


           return model;}


QSqlQueryModel * Transaction:: calculF(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select datet SUM(montant) as recette FROM * transaction GROUP BY datet");

return model ;}


QSqlQueryModel * Transaction :: calculT(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from transaction sum  montant where type =:type");



return model ;

}





 QSqlQueryModel * Transaction::chercher_id()
 {
     QSqlQueryModel* model = new QSqlQueryModel ();

     model-> setQuery("select * from transaction where type = 'depense'");
     model-> setHeaderData(0,Qt:: Horizontal,QObject::tr("id"));
     model-> setHeaderData(1,Qt:: Horizontal,QObject::tr("type"));
     model-> setHeaderData(2,Qt:: Horizontal,QObject::tr("montant"));
     model-> setHeaderData(3,Qt:: Horizontal,QObject::tr("datet"));

     return model;



 }

 QSqlQueryModel *Transaction:: revenue(){
     QSqlQueryModel* model = new QSqlQueryModel ();

     model-> setQuery("select * from transaction where type = 'revenue'");
     model-> setHeaderData(0,Qt:: Horizontal,QObject::tr("id"));
     model-> setHeaderData(1,Qt:: Horizontal,QObject::tr("type"));
     model-> setHeaderData(2,Qt:: Horizontal,QObject::tr("montant"));
     model-> setHeaderData(3,Qt:: Horizontal,QObject::tr("datet"));

     return model;

 }









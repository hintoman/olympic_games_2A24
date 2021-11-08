#include "transaction.h"

Transaction::Transaction(int id,QString mont,QString type ,QDateTime dat)
{
this->id = id;
    this->mont = mont;
    this->type = type;
    this->dat = dat;

}
bool Transaction :: ajouter(){

    QSqlQuery query;
    QString res = QString :: number(id);


    query.prepare("insert into etudiant(id , type,montant,dat)" "values(:id,:type,:montant,:date)");
query.bindValue(":id",res);
query.bindValue(":type",type);
query.bindValue(":montant",mont);
query.bindValue(":date",dat);


return query.exec();
}
QSqlQueryModel * Transaction:: afficher(){

    QSqlQueryModel* model = new QSqlQueryModel ();

    model-> setQuery("select * from transaction");
    model-> setHeaderData(0,Qt:: Horizontal,QObject::tr("id"));
    model-> setHeaderData(1,Qt:: Horizontal,QObject::tr("type"));
    model-> setHeaderData(2,Qt:: Horizontal,QObject::tr("mont"));
    model-> setHeaderData(3,Qt:: Horizontal,QObject::tr("date"));

    return model;
}

bool Transaction :: supprimer(int id){

    QSqlQuery query;
    QString res = QString :: number(id);
    query.prepare("Delete from database id=:id");
    query.bindValue(":id",res);

    return query.exec();


}

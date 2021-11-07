#include "employés.h"

employés::employés(int id,QString nom,QString adresse)
{
    this->id_emp=id;
    this->nom=nom;
    this->adresse_mail=adresse;
}
bool employés::ajouter()
{
QSqlQuery query;
QString res = QString::number(id_emp);
query.prepare("insert into employe(id,nom,adresse_mail)""values(:id_emp,:nom,:adresse_mail)");
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":adresse_mail",adresse_mail);
return query.exec();
}

bool employés::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from employés where id= :id");
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * employés::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employés");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse_mail"));
return model;}

bool employés::modifier(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Update agence set ID = :id , ADRESSE = :adresse mail , nom =nom , NBR_EMP = :nbr_emp , salaire = :salaire  where ID = :id ");
query.bindValue(":id", res);
query.bindValue(":adresse", adresse_mail);
query.bindValue(":nom", nom);
query.bindValue(":nbr_emp", nbr_emp);
query.bindValue(":salaire", salaire);
return    query.exec();
}

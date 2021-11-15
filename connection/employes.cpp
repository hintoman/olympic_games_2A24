#include "employes.h"

employer::employer()
{

}
employer::employer(int id,QString nom,int salaire,QString date_rep)
{
    this->id_emp=id;
    this->nom=nom;
    this->salaire=salaire;
    this->date_entre=date_rep;
}
bool employer::ajouter()
{
    QString p=QString::number(salaire);
    QSqlQuery q;//requete SQL peut s'executer mel QT
    q.prepare("insert into gs_employer (id_emp,nom,salaire,date_entre) VALUES(:id_emp,:nom,:salaire,:date_entre)");
    q.bindValue(":id_emp",id_emp);
    q.bindValue(":nom",nom);
    q.bindValue(":salaire",salaire);
    q.bindValue(":date_entre",date_entre);
    return q.exec();

}
bool employer::supprimer(int id_emp)
{
    QSqlQuery q;
    q.prepare("delete from gs_employer where id_emp=:id_emp");
    q.bindValue(":id_emp",id_emp);
    return q.exec();
}
bool employer::modifier(int id_emp)
{
    QString p=QString::number(salaire);
    QSqlQuery q;
    q.prepare("update gs_employer set nom=:nom,salaire=:salaire,date_entre=:date_entre where id_emp=:id_emp");
    q.bindValue(":id_emp",id_emp);
    q.bindValue(":nom",nom);
    q.bindValue(":salaire",salaire);
    q.bindValue(":date_entre",date_entre);
    return q.exec();
}
QSqlQueryModel* employer::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from gs_employer");
    return model;
}





QSqlQueryModel * employer::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id_emp"){
         model->setQuery("SELECT * FROM gs_employer ORDER BY id_emp ");
    }
    else if(choix1=="salaire"){
         model->setQuery("SELECT * FROM gs_employer ORDER BY salaire ");
    }
    else if(choix1=="date_entre"){
        model->setQuery("SELECT * FROM gs_employer ORDER BY date  ");
    }



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_entre "));


return model;
}

QSqlQueryModel * employer::rechercher(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from gs_employer where (id_emp LIKE id_emp='"+QString::number(id)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_emp"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_entre"));
         return model;
}


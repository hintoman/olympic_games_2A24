#include "emploi_du_temps.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

emploi::emploi()
{

}
emploi::emploi(int id_res,int id_doc,QString email_doc,QString date_rv,int heure_rv)

{
    this->id_res=id_res;
    this->id_doc=id_doc;
    this->email_doc=email_doc;
      this->date_rv=date_rv;
    this->heure_rv=heure_rv;

}

int emploi::get_id_res(){return  id_res;}
int emploi::get_id_doc(){return  id_doc;}
QString emploi::get_email_doc(){return email_doc;}
QString emploi::get_date_rv(){return date_rv;}
int emploi::get_heure_rv(){return heure_rv;}

bool emploi::ajouter(int id_res,int id_doc,QString email_doc,QString date_rv,int heure_rv)
{
QSqlQuery query;
query.prepare("INSERT INTO emploi (ID_RES, ID_DOC, EMAIL_DOC, DATE_RV,HEURE_RV) "
                    "VALUES (:id_res,:id_doc,:email_doc,:date_rv,:heure_rv)");
query.bindValue(":id_res",id_res);
query.bindValue(":id_doc",id_doc);
query.bindValue(":email_doc",email_doc);
query.bindValue(":date_rv",date_rv);
query.bindValue(":heure_rv",heure_rv);
return    query.exec();
}

bool emploi::supprimer(int id_doc)
{
QSqlQuery query;

query.prepare("Delete from emploi where ID_doc=:id_doc ");
query.bindValue(":id_doc",id_doc);
return    query.exec();
}

bool emploi::modifier(int id_res,int id_doc,QString email_doc,QString date_rv,int heure_rv)
{QSqlQuery edit;
    edit.prepare("Update emploi set id_res=:id_res,id_doc=:id_doc,email_doc=:email_doc,date_rv=:date_rv,heure_rv=:heure_rv,where ID_doc =:id_doc");
    edit.bindValue(":id_res",id_res);
    edit.bindValue(":id_doc",id_doc);
    edit.bindValue(":email_doc",email_doc);
    edit.bindValue(":date_rv",date_rv);
    edit.bindValue(":heure_rv",heure_rv);

    return       edit.exec()  ;
}

QSqlQueryModel * emploi::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * "
                "from emploi");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_res"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_doc"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("email_doc"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_rv"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("heure_rv"));
return model;
}

QSqlQueryModel * emploi::recherche_e(int id_doc)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOI WHERE id_doc LIKE :id_doc order by date_rv ");
    query.bindValue(":id_doc",id_doc);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_res"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_doc"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("email_doc"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_rv"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("heure_rv"));

    return model;
}


QSqlQueryModel * emploi::tri(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
        if(index == 0)
        {
            model->setQuery("select *FROM emploi ORDER BY date_rv ASC");
        }
        else
        {
            model->setQuery("select *FROM  emploi ORDER BY date_rv DESC ");
        }


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_res"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_doc"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("email_doc"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_rv"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("heure_rv"));

        return model;
}












#include "don.h"

don::don()
{

}
don::don (int i,int q, QString e,QString d, QString c):id_don(i),quantite(q),emplacement(e),date_prelevement(d),cin(c)
{

}
bool don::ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id_don);

    query.prepare("INSERT INTO DON (ID_DON, EMPLACEMENT, QUANTITE, DATE_PRELEV, CIN)"
                  "VALUES (:ID_DON, :EMPLACEMENT, :QUANTITE, :DATE_PRELEV, :CIN)");


    query.bindValue(":ID_DON",res);
    query.bindValue(":EMPLACEMENT",emplacement);
    query.bindValue(":QUANTITE",quantite);
    query.bindValue(":DATE_PRELEV",date_prelevement);
    query.bindValue(":CIN",cin);

    return query.exec();
}

QSqlQueryModel * don::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select DON.ID_DON, DON.EMPLACEMENT, DON.QUANTITE, DONNEUR.GROUPE_SANGUIN, DON.DATE_PRELEV, DON.CIN from don join donneur ON DON.CIN = DONNEUR.CIN");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_PRELEV"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}


bool don::supprimer(int ID_DON)
{
    QSqlQuery qry;
    QString id = QString::number(ID_DON);
    qry.prepare("Delete from don where ID_DON = :ID_DON");
    qry.bindValue(":ID_DON",id);
    return qry.exec();
}

QSqlQueryModel *don::trier(QString crit,QString ordre)
{
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * FROM don order by "+crit+" "+ordre);
    qry->exec();
    model->setQuery(*qry);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_PRELEV"));

    return model;
}

QSqlQueryModel *don::rechercherID(int input)
{
    QSqlQuery qry;
    qry.prepare("select * from DON where ID_DON =:ID_DON");
    qry.bindValue(":ID_DON",input);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_PRELEV"));


    return model;
}
QSqlQueryModel *don::rechercherQuantite(int input)
{
    QSqlQuery qry;
    qry.prepare("select * from DON where QUANTITE =:QUANTITE");
    qry.bindValue(":QUANTITE",input);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_PRELEV"));


    return model;
}
QSqlQueryModel *don::rechercherDate(QString input)
{
    QSqlQuery qry;
    qry.prepare("select * from DON where lower(date_prelev) like '"+input+"%'");
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_PRELEV"));


    return model;
}

int don::stat1()
{
    QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("select * from DONNEUR join DON on DONNEUR.CIN = DON.CIN where DONNEUR.GROUPE_SANGUIN ='A+'") ;
        while(requete.next())

        {
                count++ ;
        }

    return(count);


}
int don::stat2()
{
    QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("select * from DONNEUR join DON on DONNEUR.CIN = DON.CIN where DONNEUR.GROUPE_SANGUIN ='AB+'") ;
        while(requete.next())

        {
                count++ ;
        }

    return(count);


}

int don::stat3()
{
    QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("select * from DONNEUR join DON on DONNEUR.CIN = DON.CIN where DONNEUR.GROUPE_SANGUIN ='O+'") ;
        while(requete.next())

        {
                count++ ;
        }

    return(count);


}
int don::stat4()
{
    QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("select * from DONNEUR join DON on DONNEUR.CIN = DON.CIN where DONNEUR.GROUPE_SANGUIN ='B+'") ;
        while(requete.next())

        {
                count++ ;
        }

    return(count);


}

#include "donneur.h"
#include <QStringList>

donneur::donneur()
{

}
donneur::donneur (QString c,QString n, QString p,QString e, QString s,QString gs,QDate dp):cin(c),nom(n),prenom(p),email(e),sexe(s),groupesanguin(gs),dateprelev(dp)
{

}
bool donneur::ajouter()
{
    QSqlQuery query;

    QString res= cin;

    query.prepare("INSERT INTO DONNEUR (CIN, NOM, PRENOM, EMAIL, SEXE, GROUPE_SANGUIN,DATE_PRELEV)"
                  "VALUES (:CIN, :NOM, :PRENOM, :EMAIL, :SEXE, :GROUPE_SANGUIN, :DATE_PRELEV)");


    query.bindValue(":CIN",res);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":EMAIL",email);
    query.bindValue(":SEXE",sexe);
    query.bindValue(":GROUPE_SANGUIN",groupesanguin);
    query.bindValue(":DATE_PRELEV",dateprelev);
    return query.exec();
}

QSqlQueryModel * donneur::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select * from DONNEUR");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Groupesanguin"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Dateprelev"));

    return model;
}

QStringList donneur::getCINs()
{
   QStringList listCIN;
    QSqlQuery query;
       query.prepare("SELECT CIN FROM DONNEUR");
       query.exec();
       while(query.next()) {
          listCIN.append(query.value(0).toString());
       }
    return listCIN;
}

QString donneur::getDatePrel(QString CIN)
{

    QSqlQuery query;
       query.prepare("SELECT DATE_PRELEV FROM DONNEUR WHERE CIN=?");
       query.addBindValue(CIN);
       query.exec();
       while(query.next()) {
          return query.value(0).toString();
       }
    return NULL;
}

bool donneur::supprimer(int cin)
{
    QSqlQuery qry;
    QString mat = QString::number(cin);
    qry.prepare("Delete from donneur where CIN = :CIN");
    qry.bindValue(":CIN",mat);
    return qry.exec();
}

QSqlQueryModel *donneur::trier(QString crit,QString ordre)
{
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * FROM donneur order by "+crit+" "+ordre);
    qDebug() << "QUERY : select * FROM donneur order by " <<crit <<" "<<ordre;
    qry->exec();
    model->setQuery(*qry);

    return model;


}


QSqlQueryModel *donneur::rechercherNom(QString input)
{
    QSqlQuery qry;
    qry.prepare("select * from DONNEUR where NOM =:NOM");
    qry.bindValue(":NOM",input);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Groupesanguin"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Dateprelev"));


    return model;
}

QSqlQueryModel *donneur::rechercherGroupeS(QString input)
{
    QSqlQuery qry;
    qry.prepare("select * from DONNEUR where GROUPE_SANGUIN =:GROUPE_SANGUIN");
    qry.bindValue(":GROUPE_SANGUIN",input);

    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Groupesanguin"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Dateprelev"));


    return model;
}

QSqlQueryModel *donneur::rechercherDate(QString input)
{
    QSqlQuery qry;
    qry.prepare("select * from DONNEUR where lower(date_prelev) like '"+input+"%'");
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Groupesanguin"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Dateprelev"));


    return model;
}


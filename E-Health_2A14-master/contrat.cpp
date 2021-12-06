#include "contrat.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <QMessageBox>
contrat::contrat()
{
    id=0;
    nomp="";
    duree="";
    dater="";
    remise=0;


}
contrat::contrat(int id,QString nomp,QString duree,QString dater,int remise)
{
    this->id=id;
    this->nomp=nomp;
    this->duree=duree;
    this->dater=dater;
    this->remise=remise;

}
bool contrat::ajouter(Ui::health *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into contrat(id, nomp, duree,dater,remise) VALUES (:id, :nomp, :dater,:duree,:remise)");
        q.bindValue(":id",ui->lineEdit_18_gc->text());
        q.bindValue(":nomp",ui->lineEdit_19_gc->text());
        q.bindValue(":dater",ui->lineEdit_20_gc->text());
        q.bindValue(":duree",ui->lineEdit_21_gc->text());
        q.bindValue(":remise",ui->lineEdit_22_gc->text());

        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la contrat a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! 🙁" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la contrat a ete ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool contrat::modifier(Ui::health *ui)
{

    QSqlQuery q;
    q.prepare("update contrat set nomp=:nomp,duree=:duree,dater=:dater,remise=:remise where id=:id" );
    q.bindValue(":id",ui->lineEdit_18_gc->text());
    q.bindValue(":nomp",ui->lineEdit_19_gc->text());
    q.bindValue(":duree",ui->lineEdit_20_gc->text());
    q.bindValue(":dater",ui->lineEdit_21_gc->text());
    q.bindValue(":remise",ui->lineEdit_22_gc->text());
    if(q.exec())
    {
        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la contrat a ete modifie ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! 🙁" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la contrat n'est pas modifiee ");
                    msgBox.exec();
                    return false;
        }
}
}
bool contrat::supprimer(Ui::health *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM contrat WHERE id =:id");
         q.bindValue(":id",ui->lineEdit_16_gc->text());


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("la contrat a ete supprimee ");
                     msgBox.exec();
             return true;
         }
         else

{
             QMessageBox msgBox ;
                     msgBox.setText("la contrat n'est pas supprimee' ");
                     msgBox.exec();
             return false;
}
}

void contrat::afficher(Ui::health *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from contrat WHERE id ='"+ui->tableView_gc->model()->data(ui->tableView_gc->model()->index(ui->tableView_gc->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_18_gc->setText(q.value(1).toString());
    ui->lineEdit_19_gc->setText(q.value(2).toString());
    ui->lineEdit_20_gc->setText(q.value(3).toString());
    ui->lineEdit_21_gc->setText(q.value(4).toString());
    ui->lineEdit_22_gc->setText(q.value(5).toString());

}
void contrat::affichertable(Ui::health *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select id, nomp, duree,dater,remise from contrat");
    q.exec();
    modal->setQuery(q);
    ui->tableView_gc->setModel(modal);
}
void contrat::Tri_Prix(Ui::health *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from contrat order by remise");
    q.exec();
    model->setQuery(q);
    ui->tableView_gc->setModel(model);
}


QSqlQueryModel *contrat::triercontrat()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  id,nomp, duree,dater,remise from contrat order by remise");
   return model ;
}
QSqlQueryModel *contrat :: triercontrat_desc()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT id,nomp,duree,dater,remise from contrat ORDER BY remise desc");
        return model;
    }


QSqlQueryModel *contrat::recherchercontrat(QString id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from contrat where id='"+id+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}


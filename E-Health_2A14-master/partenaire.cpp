#include "partenaire.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <QMessageBox>
partenaire::partenaire()
{
    cin=0;
    nom="";
    prenom="";
    numtel=0;
    adresse="";
    id=0;


}
partenaire::partenaire(int cin,QString nom,QString prenom,int numtel,QString adresse,int id)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->numtel=numtel;
    this->adresse=adresse;
    this->id=id;

}
bool partenaire::ajouter(Ui::health *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into partenaire(cin, nom, prenom,numtel,adresse,id) VALUES (:cin, :nom, :prenom,:numtel,:adresse,:id)");
        q.bindValue(":cin",ui->lineEdit_gc->text());
        q.bindValue(":nom",ui->lineEdit_4_gc->text());
        q.bindValue(":prenom",ui->lineEdit_3_gc->text());
        q.bindValue(":numtel",ui->lineEdit_2_gc->text());
        q.bindValue(":adresse",ui->lineEdit_5_gc->text());
        q.bindValue(":id",ui->lineEdit_6_gc->text());

        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la partenaire a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! 🙁" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la partenaire a ete ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool partenaire::modifier(Ui::health *ui)
{

    QSqlQuery q;
    q.prepare("update partenaire set cin=:cin,nom=:nom,prenom=:prenom,numtel=:numtel,adresse=:adresse where id=:id" );
    q.bindValue(":cin",ui->lineEdit_gc->text());
    q.bindValue(":nom",ui->lineEdit_4_gc->text());
    q.bindValue(":prenom",ui->lineEdit_3_gc->text());
    q.bindValue(":numtel",ui->lineEdit_2_gc->text());
    q.bindValue(":adresse",ui->lineEdit_5_gc->text());
    q.bindValue(":id",ui->lineEdit_6_gc->text());

    if(q.exec())
    {
        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la partenaire a ete modifie ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! 🙁" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la partenaire n'est pas modifiee ");
                    msgBox.exec();
                    return false;
        }
  }
}
bool partenaire::supprimer(Ui::health *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM partenaire WHERE id =:id");
         q.bindValue(":id",ui->lineEdit_7_gc->text());


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("la partenaire a ete supprimee ");
                     msgBox.exec();
             return true;
         }
         else

{
             QMessageBox msgBox ;
                     msgBox.setText("la partenaire n'est pas supprimee' ");
                     msgBox.exec();
             return false;
}
}

void partenaire::afficher(Ui::health *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from partenaire WHERE id ='"+ui->tableView_2_gc->model()->data(ui->tableView_2_gc->model()->index(ui->tableView_2_gc->selectionModel()->currentIndex().row(),5)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_gc->setText(q.value(1).toString());
    ui->lineEdit_4_gc->setText(q.value(2).toString());
    ui->lineEdit_3_gc->setText(q.value(3).toString());
    ui->lineEdit_2_gc->setText(q.value(4).toString());
    ui->lineEdit_5_gc->setText(q.value(5).toString());
    ui->lineEdit_6_gc->setText(q.value(6).toString());


}
void partenaire::affichertable(Ui::health *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select cin, nom, prenom,numtel,adresse,id from partenaire");
    q.exec();
    modal->setQuery(q);
    ui->tableView_2_gc->setModel(modal);
}
void partenaire::Tri_partenaire(Ui::health *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from partenaire order by id");
    q.exec();
    model->setQuery(q);
    ui->tableView_2_gc->setModel(model);
}


QSqlQueryModel *partenaire::trierpartenaire()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  cin,nom, prenom,numtel,adresse,id from partenaire order by id");
   return model ;
}
QSqlQueryModel *partenaire::rechercherpartenaire(QString id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from partenaire where id='"+id+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}


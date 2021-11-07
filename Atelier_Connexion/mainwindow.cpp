#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"athlete.h"
#include<QMessageBox>
#include<QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  ui->le_id->setValidator(new QIntValidator(0,99999999, this));
    ui->tele->setValidator(new QIntValidator(0,99999999, this));
    ui->tab_athltes->setModel(A.affichier());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_Ajouter_clicked()
{   int id=ui->le_id->text().toInt();
    int num_tel=ui->tele->text().toInt();
    QString age=ui->l_date->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fliere=ui->filiere->text();
    QString Email=ui->Email->text();




    Athlete A (id ,num_tel,age,nom,prenom,fliere,Email);

     bool mail=A.Email_validation(Email);
     if(mail)
             {
                 QMessageBox::information(nullptr, QObject::tr("ajout "),
                             QObject::tr("Email validee.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 bool test=A.Ajouter();
                 if(test)
                         {
                             QMessageBox::information(nullptr, QObject::tr("ajout "),
                                         QObject::tr("ajout effectuer.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                                          ui->tab_athltes->setModel(A.affichier());

                     }
                         else
                           {  QMessageBox::critical(nullptr, QObject::tr("ajout"),
                                         QObject::tr("erreur d'ajout.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
                              ui->tab_athltes->setModel(A.affichier());

         }
             else
               {  QMessageBox::critical(nullptr, QObject::tr("ajout"),
                             QObject::tr("Email non valide .\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

     }

}
void MainWindow::on_pb_supprimer_clicked()
{
    Athlete A1; A1.setid(ui->idS->text().toInt());
    bool test=A1.supprimer(A1.getid());
    QMessageBox msgBox;
    if(test){
        msgBox.setText("supprission effectuée");
    ui->tab_athltes->setModel(A.affichier());}
    else
        msgBox.setText("echec");
        msgBox.exec();
}

void MainWindow::on_pb_Aaffichier_clicked()
{
    ui->tab_athltes->setModel(A.affichier());


}

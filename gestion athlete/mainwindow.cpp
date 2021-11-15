#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"athlete.h"
#include<QMessageBox>
#include<QDebug>
#include <QAbstractItemView>
//#include"qr.h"
#include"qrcode.hpp"
#include<QTextStream>
#include<QFile>
#include<QFileDialog>
#include <QList>
#include "historique.h"
#include <QPieSeries>
#include <QtCharts>




using namespace qrcodegen;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  ui->le_id->setValidator(new QIntValidator(0,99999999, this));
    ui->tele->setValidator(new QIntValidator(0,99999999, this));


    ui->tab_athltes->setModel(A.affichier());

   /* ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels({"ID","NOM","PRENOM","AGE", "FILIERE","EMAIL","TELEPHONE"});
    ui->tableWidget->setSelectionBehavior(QTableView::SelectRows);*/
    ui->tab_athltes->setModel(A.affichier());





}
void MainWindow::AthleteChange(Athlete * A){
    qDebug() << "Athlete Selection Change Detected";

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

   /*  const int row = ui->tableWidget->rowCount();
     ui->tableWidget->insertRow(row);
     ui->tableWidget->setItem(row,0, new QTableWidgetItem(id));
     ui->tableWidget->setItem(row,1, new QTableWidgetItem(nom ));
     ui->tableWidget->setItem(row,2, new QTableWidgetItem(prenom));
     ui->tableWidget->setItem(row,3, new QTableWidgetItem(age));
     ui->tableWidget->setItem(row,4, new QTableWidgetItem(fliere ));
     ui->tableWidget->setItem(row,5, new QTableWidgetItem(Email));
     ui->tableWidget->setItem(row,6, new QTableWidgetItem(num_tel));
     */





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

void MainWindow::on_modifier_clicked()
{
  int id=ui->le_id->text().toInt();
       int num_tel=ui->tele->text().toInt();
       QString age=ui->l_date->text();
       QString nom=ui->le_nom->text();
       QString prenom=ui->le_prenom->text();
       QString fliere=ui->filiere->text();
       QString Email=ui->Email->text();
       Athlete A (id ,num_tel,age,nom,prenom,fliere,Email);
       bool test=A.modifier();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("succes"),
                       QObject::tr("modif.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_athltes->setModel(A.affichier());


       }
       else
           QMessageBox::critical(nullptr, QObject::tr("erur"),
                       QObject::tr("moodif failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



       }




void MainWindow::on_tab_athltes_doubleClicked(const QModelIndex &index)
{

  /*  QItemSelectionModel *select = ui->tab_athltes->selectionModel();
    if (!select->hasSelection()){
         return;
    }


    int id=select->selectedRows().at(0).data().toInt();
    Athlete * A = Athlete::getAthleteById(id);
    Athlete::setCurrentSelectedAthlete(A);



    ui->le_nom->setText(A->nom);
    ui->le_prenom->setText(A->prenom);
    ui->Email->setText(A->Email);
    ui->filiere->setText(A->fliere);

 //   ui->tele->setText(m->num_tel);*/











  int id=ui->tab_athltes->model()->data(ui->tab_athltes->model()->index(ui->tab_athltes->currentIndex().row(),0)).toInt();
    QString res= QString::number(id);
    ui->le_id->setText(res);
    QString nom=ui->tab_athltes->model()->data(ui->tab_athltes->model()->index(ui->tab_athltes->currentIndex().row(),1)).toString();
     ui->le_nom->setText(nom);
     QString prenom=ui->tab_athltes->model()->data(ui->tab_athltes->model()->index(ui->tab_athltes->currentIndex().row(),2)).toString();
     ui->le_prenom->setText(prenom);
      QString Email=ui->tab_athltes->model()->data(ui->tab_athltes->model()->index(ui->tab_athltes->currentIndex().row(),5)).toString();
       ui->Email->setText(Email);
       QString filiere=ui->tab_athltes->model()->data(ui->tab_athltes->model()->index(ui->tab_athltes->currentIndex().row(),4)).toString();
       ui->filiere->setText(filiere);
       int num_tel=ui->tab_athltes->model()->data(ui->tab_athltes->model()->index(ui->tab_athltes->currentIndex().row(),6)).toInt();
       QString res1= QString::number(num_tel);
       ui->tele->setText(res1);


}










void MainWindow::on_modifier_pressed()
{
    int id=ui->le_id->text().toInt();
         int num_tel=ui->tele->text().toInt();
         QString age=ui->l_date->text();
         QString nom=ui->le_nom->text();
         QString prenom=ui->le_prenom->text();
         QString fliere=ui->filiere->text();
         QString Email=ui->Email->text();
         Athlete A (id ,num_tel,age,nom,prenom,fliere,Email);
         bool test=A.modifier();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("succes"),
                         QObject::tr("modif.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_athltes->setModel(A.affichier());


         }
         else
             QMessageBox::critical(nullptr, QObject::tr("erur"),
                         QObject::tr("moodif failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_tri_clicked()
{
    if(ui->radid->isChecked())
    {ui->tab_athltes->setModel(A.triid());
}else if (ui->radnom->isChecked())
    {ui->tab_athltes->setModel(A.trinom());
    }else if (ui->raddate->isChecked())
    {ui->tab_athltes->setModel(A.tridate());
    }
}

void MainWindow::on_pb_chercher_2_pressed()
{
 //   QString  cls=ui->idS->text();
  //   ui->tab_athltes->setModel(A.chercher(ui->idS->text()));






    //////////////////////////////////////////////////
    /*  Athlete A;

         int x;
              x=A.chercher(no);
    if (x==1)
              {
                      QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                  QObject::tr("nom trouveé.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

              }
                      else
              {
                      QMessageBox::critical(nullptr, QObject::tr("erreur"),
                                  QObject::tr("nom introuvable.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);*/

}

void MainWindow::on_pb_chercher_2_clicked()
{
    QString no =ui->idS->text();
    ui->tab_athltes->setModel(A.chercher(ui->idS->text()));
}
void MainWindow::on_QRcodecom_clicked()
{

           //if (Athlete::currentSelectedAthlete == nullptr) return;
       //    if (Athlete::currentSelectedAthlete == NULL) return;

                QString rawQr = "ID:%1 Nom:%2 prenom:%3 age:%4";

                using namespace std ;
            //  Athlete A1 =* Athlete::currentSelectedAthlete ;
               rawQr = rawQr.arg(A.id).arg(A.nom).arg(A.age);
                QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);


                QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);

                for (int y = 0; y < qr.getSize(); y++) {
                    for (int x = 0; x < qr.getSize(); x++) {
                        int color = qr.getModule(x, y);  // 0 for white, 1 for black

                        // You need to modify this part
                        if(color==0)
                            im.setPixel(x, y,qRgb(254, 254, 254));
                        else
                            im.setPixel(x, y,qRgb(0, 0, 0));
                    }
                }
                im=im.scaled(200,200);
                ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::on_QRcodecom_pressed()
{
    //  if (Athlete::currentSelectedAthlete == nullptr) return;
   //   if (Athlete::currentSelectedAthlete == NULL) return;

  QString rawQr = "ID:%1 Nom:%2 prenom:%3 age:%4";

       //   using namespace std ;
         //Athlete A1 =* Athlete::currentSelectedAthlete ;
         rawQr = rawQr.arg(A.id).arg(A.nom).arg(A.age);
          QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);


          QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);

          for (int y = 0; y < qr.getSize(); y++) {
              for (int x = 0; x < qr.getSize(); x++) {
                  int color = qr.getModule(x, y);  // 0 for white, 1 for black

                  // You need to modify this part
                  if(color==0)
                      im.setPixel(x, y,qRgb(254, 254, 254));
                  else
                      im.setPixel(x, y,qRgb(0, 0, 0));
              }
          }
          im=im.scaled(200,200);
          ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filiter ="All File(*,*);; Text File(*.txt);;XML File(*.xml)";
    QString file_name = QFileDialog::getOpenFileName(this,"open a file ","c://");
  QFile file (file_name) ;
  if(!file.open(QFile::WriteOnly | QFile::Text)){
       QMessageBox::warning(this,"title","File not open");
       QTextStream out(&file);
       QString text = ui->plainTextEdit_2->toPlainText() ;
       out<<text;
       file.flush();
       file.close();
  }

}


void MainWindow::on_pushButton_clicked()
{
    QFile file ("C:/Users/Monta/Desktop/Atelier_Connexion") ;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
         QMessageBox::warning(this,"title","File not open");}
         QTextStream in(&file);
         QString text = in.readAll()  ;
         ui->plainTextEdit_2->setPlainText(text);

         file.close();
    }


void MainWindow::on_pushButton_3_clicked()
{

    Athlete A;
    QString text=A.printPDF();
    ui->impc1->setText(text);

    QPrinter printer ;
    printer.setPrinterName("imprim");
    QPrintDialog dialog (&printer,this);
    if(dialog.exec()==QDialog::Rejected) return ;
    ui->impc1->print(&printer);}

void MainWindow::on_addhis_clicked()
{
    int nbrpg=ui->nbrpg->text().toInt();
    int nbrpp=ui->nbrpp->text().toInt();
    int nbrmd=ui->nbrmd->text().toInt();
    int nbra=ui->nbra->text().toInt();
    int nbrb=ui->nbrb->text().toInt();
    historique H(nbrpg,nbrpp,nbrmd,nbra,nbrb);
    bool test = H.ajouterhis();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("succes"),
                    QObject::tr("ajouter avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }
    else
        QMessageBox::critical(nullptr, QObject::tr("erreur"),
                    QObject::tr("erreur ajout.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_addhis_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from histo where nbrpg <5 ");
                         float age=model->rowCount();
                         model->setQuery("select * from histo where nbrpg between 5 and 10 ");
                         float agee=model->rowCount();
                         model->setQuery("select * from histo where nbrpg >10 ");
                         float ageee=model->rowCount();
                         float total=age+agee+ageee;
                         QString a=QString("moins des 5 parties gagnes "+QString::number((age*100)/total,'f',2)+"%" );
                         QString b=QString("entre 5 et 10 parties gagnes"+QString::number((agee*100)/total,'f',2)+"%" );
                         QString c=QString("plus que 10 parties gagnes"+QString::number((ageee*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,age);
                         series->append(b,agee);
                         series->append(c,ageee);
                 if (age!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( agee!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(ageee!=0)
                 {
                          // Add labels to rest of slices
                          QPieSlice *slice2 = series->slices().at(2);
                          //slice1->setExploded();
                          slice2->setLabelVisible();
                 }
                         // Create the chart widget
                         QChart *chart = new QChart();
                         // Add data to chart with title and hide legend
                         chart->addSeries(series);
                         chart->setTitle("Pourcentage Par Partie gagnes : nbr des atletes "+ QString::number(total));
                         chart->legend()->hide();
                         // Used to display the chart
                         QChartView *chartView = new QChartView(chart);
                         chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->resize(1000,500);
                         chartView->show();
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                         model->setQuery("select * from histo where nbrpp <5 ");
                         float ee=model->rowCount();
                         model->setQuery("select * from histo where nbrpp between 5 and 10 ");
                         float eee=model->rowCount();
                         model->setQuery("select * from histo where nbrpp >10 ");
                         float eeee=model->rowCount();
                         float totaal=ee+eee+eeee;
                         QString aa=QString("moins des 5 parties perdu "+QString::number((ee*100)/totaal,'f',2)+"%" );
                         QString bb=QString("entre 5 et 10 parties perdu"+QString::number((eee*100)/totaal,'f',2)+"%" );
                         QString cc=QString("plus que 10 parties perdu"+QString::number((eeee*100)/totaal,'f',2)+"%" );
                         QPieSeries *seriess = new QPieSeries();
                         seriess->append(aa,ee);
                         seriess->append(bb,eee);
                         seriess->append(cc,eeee);
                 if (ee!=0)
                 {QPieSlice *slice0 = seriess->slices().at(0);
                  slice0->setLabelVisible();
                  slice0->setPen(QPen());}
                 if ( eee!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice11 = seriess->slices().at(1);
                          //slice1->setExploded();
                          slice11->setLabelVisible();
                 }
                 if(eeee!=0)
                 {
                          // Add labels to rest of slices
                          QPieSlice *slice22 = seriess->slices().at(2);
                          //slice1->setExploded();
                          slice22->setLabelVisible();
                 }
                         // Create the chart widget
                         QChart *charrt = new QChart();
                         // Add data to chart with title and hide legend
                         charrt->addSeries(seriess);
                         charrt->setTitle("Pourcentage Par parties perdu :Nombre Des Atletes "+ QString::number(totaal));
                         charrt->legend()->hide();
                         // Used to display the chart
                         QChartView *charrtView = new QChartView(charrt);
                         charrtView->setRenderHint(QPainter::Antialiasing);
                         charrtView->resize(1000,500);
                         charrtView->show();
}

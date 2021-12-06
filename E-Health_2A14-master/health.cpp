#include <QTimer>
#include<QDateTime>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "health.h"
#include "ui_health.h"
#include "emploi_du_temps.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
#include "patient.h"
#include "dossiermedical.h"
#include "reservation.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
//#include "statistique.h"
#include<QString>
#include<QThread>
#include <QMessageBox>
#include "EMPLOYE.h"
#include "tache.h"
#include "mainwindow.h"
#include "ui_health.h"

#include "ui_mainwindow.h"
#include<QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDebug>
#include "contrat.h"
#include "qcustomplot.h"
#include "partenaire.h"
#include "tableprinter.h"
#include "medicaments.h"
#include "machine.h"
#include "widget.h"
#include "DuMesengerConnectionDialog.h"
#include <QTime>
#include <QTimer>
#include <QDateTime>


using namespace DuarteCorporation;
donneur dn;

health::health(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::health)
{
    ui->setupUi(this);
    //************************temps***************

    //Timer
        QTimer *timer_p=new QTimer(this);
        connect(timer_p, SIGNAL(timeout()), this,SLOT(showTime()));
        timer_p->start(1000);

    //DAate systeme
        QDateTime Date_p=QDateTime::currentDateTime();
        QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
        ui->date->setText(Date_txt);


   //**********************************************************
   int ret =A.connect_arduino();//lancer la connection to arduino
    switch (ret) {

    case(0):qDebug()<<"arduino is available and connect to : "<<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available and not  connect to : "<<A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available ";
        break;
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(detction_de_chaleur()));
    //*****************************************************************
    EMPLOYE e;
    ui->tableView_em->setModel(e.afficher());
    ui->tableView_em_2->setModel(t.afficher_tache());
    patient p;
    ui->tab_patient_2->setModel(p.afficher());
    dossiermedical d;
    ui->table_dossier->setModel(d.afficher());
    medicament m;
    ui->tableView->setModel(m.afficher());
    machine a;
     ui->tableView_3->setModel(a.afficher());
    //l'animation pour "Bienvenue"
    animation= new QPropertyAnimation(ui->label_7, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->label_7->geometry());
    animation->setEndValue(QRect(300,100,400,400));
    animation->start();
    //l'animation pour "choisir votre choix SVP"
    /*animation= new QPropertyAnimation(ui->label_11, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->label_11->geometry());
    animation->setEndValue(QRect(150,200,350,150));
    animation->start();*/
    MainWindow M ;

//*****************************************

    //controle de saisie des tables donneur et don
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z ' ']+"),this);
    ui->cINLineEdit_2->setValidator(new QIntValidator(10000000,999999999,this));
    ui->cINLineEdit_2->setMaxLength(8);
    ui->referenceLineEdit_2->setValidator(new QIntValidator (10000000,999999999,this));
    ui->referenceLineEdit_2->setMaxLength(8);
    ui->quantiteLineEdit_2->setValidator(new QIntValidator(10000,99999,this));
    ui->nomLineEdit_2->setValidator(validator_String);
    ui->prenomLineEdit_2->setValidator(validator_String);
    QValidator *validator_Mail=new QRegExpValidator(QRegExp("[A-Za-z '@ ' '.']+"),this);
    ui->eMailLineEdit_2->setValidator(validator_Mail);


    ui->tableViewDonneur_2->setModel(tmpdonneur.afficher());
    ui->tableViewDonneur_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewDonneur_2->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableViewDon_2->setModel(tmpdon.afficher());
    ui->tableViewDon_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewDon_2->setSelectionMode(QAbstractItemView::SingleSelection);

    model = new QSqlTableModel;
    model->select();
   // ui->tableView->setModel(tmpcontrat.affichertable());
    model = new QSqlTableModel;
    model->select();
    ui->id_r->setMaxLength(4);
    ui->nom_pat->setMaxLength(8);
    ui->prenom_pat->setMaxLength(8);
    ui->date_r->setMaxLength(10);
    ui->sex_e->setMaxLength(1);
    ui->id_res->setMaxLength(4);
    ui->id_doc->setMaxLength(4);
    ui->date_rv->setMaxLength(10);
    ui->heure_rv->setMaxLength(2);







    reproductor = new QMediaPlayer(this);

   connect(ui->pushButton_playsong, &QPushButton::clicked, reproductor, &QMediaPlayer::play);
   connect(ui->pushButton_pausesong, &QPushButton::clicked, reproductor, &QMediaPlayer::pause);
   connect(ui->pushButton_stopsong, &QPushButton::clicked, reproductor, &QMediaPlayer::stop);








}

health::~health()
{
    delete ui;
}

void health::on_pushButton_ajouter_clicked()
{
    int cin=ui->lineEditCin->text().toInt();
    QString nom=ui->lineEditNom->text();
    QString prenom=ui->lineEditPrenom->text();
    QString mail=ui->lineEditMail->text();
    QString DDN =ui->dateEdit->text() ;
    QString Tache =ui->comboBox_Tache->currentText();
    QString cinc=QString::number(cin);
if(cinc.size()==8)
{
 EMPLOYE e (cin,nom,prenom,mail,DDN,Tache);
 bool test=e.ajouter();
 QMessageBox msgBox;
 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView_em->setModel(e.afficher());
   }
 else
    msgBox.setText("Echec d'ajout");
 msgBox.exec();
}
else{
    QMessageBox msgBox;
    msgBox.setText("Entrer 8 chiffres pour le CIN SVP");
    msgBox.exec();}
}


void health::on_pushButton_mod_clicked()
{
        int cin = ui->lineEditCin_2->text().toInt() ;
        QString nom= ui->lineEditNom_2->text();
        QString prenom=ui->lineEditPrenom_2->text();
        QString mail=ui->lineEditMail_2->text();
        QString DDN=ui->dateEdit_2->text() ;
        QString Tache=ui->comboBox_Tache2->currentText() ;

       EMPLOYE e (cin,nom,prenom,mail,DDN,Tache);
       bool test=e.modifier();
        QMessageBox msgBox;
        if(test)
          {  msgBox.setText("Modifier avec succes.");
            ui->tableView_em->setModel(e.afficher());
        }
        else
            msgBox.setText("Echec de modification");
          msgBox.exec();



}


void health::on_pushButton_sup_clicked()
{

   int x =ui->lineEditCin_2->text().toInt();
    bool test=ee.supprimer(x);
    QMessageBox msgBox;

    if(test)
       {
    msgBox.setText("Suppression avec succes.");
    ui->tableView_em->setModel(ee.afficher());//refreche

    }
    else
       { msgBox.setText("Echec de suppression");
        msgBox.exec();
       }

}



void health::on_tableView_em_activated(const QModelIndex &index)
{   EMPLOYE ee;
    QString val = ui->tableView_em->model()->data(index).toString();
    int x = ui->tableView_em->model()->data(index).toString().toInt();

    QString cin_string= QString::number(ee.get_cin());

    QSqlQuery query;
     query.prepare("select * from employe where cin =:x or nom =:val or prenom=:val or mail=:val or DDN=:val or Tache=:val  ");
     query.bindValue(":val", val);
     query.bindValue(":x",x);

    if (query.exec())
    {
        while (query.next())
        {
            ui->lineEditCin_2->setText(query.value(0).toString());
            ui->lineEditNom_2->setText(query.value(1).toString());
            ui->lineEditPrenom_2->setText(query.value(2).toString());
            ui->lineEditMail_2->setText(query.value(3).toString());
            ui->dateEdit_2->setDate(query.value(4).toDate());
            ui->comboBox_Tache2->setCurrentText(query.value(5).toString());
        }
    }
    else
    {
        QMessageBox::critical(this ,tr("error::"),query.lastError().text());
    }

}



void health::on_pushButton_2_clicked()
{
    widget w1;
    w1.exec();

}


void health::on_pushButton_refreche_clicked()
{
    EMPLOYE e ;
    ui->tableView_em->setModel(e.afficher());

}

void health::on_comboBox_trier_activated(const QString &arg1)
{
    EMPLOYE ee;
   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * qry = new QSqlQuery();
   if (arg1=="cin et nom et prenom")
   {
    qry->prepare("Select * from employe order by cin,nom,prenom ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_em->setModel(modal);
    ui->tableView_em->show();
   }
  else if (arg1=="nom")
   {
    qry->prepare("Select * from employe order by nom");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_em->setModel(modal);
    ui->tableView_em->show();
   }

   else if (arg1=="prenom")
   {
    qry->prepare("Select * from employe order by prenom desc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_em->setModel(modal);
    ui->tableView_em->show();
   }

}

void health::on_comboBox_chercher_activated(const QString &arg1)
{
    EMPLOYE ee;
    if(arg1=="cin et nom et prenom ")
    {
    ee.chercher(ui->lineEditCin_2->text().toInt(),ui->lineEditNom_2->text(),ui->lineEditPrenom_2->text());
    ui->tableView_em->setModel(ee.afficher_unemploye());
    }
    else if (arg1=="cin")
    {
        ee.chercher_cin(ui->lineEditCin_2->text().toInt());
        ui->tableView_em->setModel(ee.afficher_unemploye_cin());

    }
    else if (arg1=="nom et prenom")
    {
        ee.chercher_nom_prenom(ui->lineEditNom_2->text(),ui->lineEditPrenom_2->text());
        ui->tableView_em->setModel(ee.afficher_unemploye_nom_prenom());

    }
}

void health::on_pushButton_pdf_clicked()
{

        QString strStream;
        QTextStream out(&strStream);

         const int rowCount = ui->tableView_em->model()->rowCount();
         const int columnCount = ui->tableView_em->model()->columnCount();
        out <<  "<html>\n"
        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des employes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_em->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_em->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_em->isColumnHidden(column)) {
                                 QString data = ui->tableView_em->model()->data(ui->tableView_em->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);


}

void health::on_pushButton_imprimer_clicked()
{
        QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}


//*********************************************************************************************************************
//*********************************************************************************************************************
//*********************************************************************************************************************

void health::on_pushButton_refreche_2_clicked()
{
    tache t;
        ui->tableView_em_2->setModel(t.afficher_tache());
}

void health::on_pushButton_ajouter_Tache_clicked()
{
    QString type_tache=ui->comboBox_type_tache->currentText();
    int salaire=ui->lineEdit_salaire->text().toInt();
    QString date_debut=ui->dateEdit_debut->text();
    QString date_fin=ui->dateEdit_fin->text();
    tache t(type_tache,salaire,date_debut,date_fin);
    bool test=t.ajouter_tache();
    QMessageBox msgBox;
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("AJOUTER"),
                    QObject::tr("AJOUT SUCCES.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_em_2->setModel(t.afficher_tache());
    }
    else {QMessageBox::information(nullptr, QObject::tr("AJOUTER"),
                                   QObject::tr("ECHEC D'AJOUT.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}

}
void health::on_pushButton_mod_2_clicked()
{
    QString type_tache=ui->comboBox_type_tache_2->currentText();
    int salaire=ui->lineEdit_salaire_2->text().toInt();
    QString date_debut=ui->dateEdit_debut_2->text();
    QString date_fin=ui->dateEdit_fin_2->text();
    tache t(type_tache,salaire,date_debut,date_fin);
    bool test=t.modifier_tache();
    QMessageBox msgBox;
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("AJOUTER"),
                    QObject::tr("MODIFICATION SUCCES.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_em_2->setModel(t.afficher_tache());
    }
    else {QMessageBox::information(nullptr, QObject::tr("AJOUTER"),
                                   QObject::tr("ECHEC MODIFICATION.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}

}

void health::on_pushButton_sup_2_clicked()
{
    QString x=ui->comboBox_type_tache_2->currentText();
    bool test=t.supprimer_tache(x);
    QMessageBox msgBox;

    if(test)
       {
    msgBox.setText("Suppression avec succes.");
    ui->tableView_em_2->setModel(t.afficher_tache());//refreche

    }
    else
       { msgBox.setText("Echec de suppression");
        msgBox.exec();}
}
void health::on_tableView_em_2_activated(const QModelIndex &index)
{
    tache t;
    QString val = ui->tableView_em_2->model()->data(index).toString();
    QString salaire_string= QString::number(t.get_salaire());
    QSqlQuery query;
    query.prepare(("select * from tache where type_tache=:val or salaire=:val or date_debut=:val or date_fin=:val  "));
    query.bindValue(":val", val);
    if (query.exec())
    {
        while (query.next())
        {
            ui->comboBox_type_tache_2->setCurrentText(query.value(0).toString());
            ui->lineEdit_salaire_2->setText(query.value(1).toString());
            ui->dateEdit_debut_2->setDate(query.value(2).toDate());
            ui->dateEdit_fin_2->setDate(query.value(3).toDate());
        }
    }
    else
    {
        QMessageBox::critical(this ,tr("error::"),query.lastError().text());
    }
}
void health::on_comboBox_trier_2_activated(const QString &arg1)
{
    tache t;
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    if (arg1=="DATE_DEBUT")
    {
        qry->prepare("Select * from tache order by date_debut ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_em_2->setModel(modal);
        ui->tableView_em_2->show();
    }
    else if (arg1=="DATE_FIN")
    {
        qry->prepare("Select * from tache order by date_fin ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_em_2->setModel(modal);
        ui->tableView_em_2->show();
    }
    else if (arg1=="SALAIRE ET DATE_DEBUT ET DATE_FIN")
    {
        qry->prepare("Select * from tache order by salaire,date_debut,date_fin ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_em_2->setModel(modal);
        ui->tableView_em_2->show();
    }
}
void health::on_comboBox_chercher_2_activated(const QString &arg1)
{
    tache t ;
    if (arg1=="salaire")
    {
        t.chercher_tache_salaire(ui->lineEdit_salaire_2->text().toInt());
        ui->tableView_em_2->setModel(t.afficher_tache_salaire());
    }
    else if (arg1=="date_debut_type_salaire")
    {
        t.chercher_date_debut_type_salaire(ui->dateEdit_debut_2->text(),ui->comboBox_type_tache_2->currentText(),ui->lineEdit_salaire_2->text().toInt());
        ui->tableView_em_2->setModel(t.afficher_date_debut_type_salaire());
    }
    else if(arg1=="type")
    {
        t.chercher_type(ui->comboBox_type_tache_2->currentText());
        ui->tableView_em_2->setModel(t.afficher_type());
    }


}


void health::on_pushButton_pdf_2_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

     const int rowCount = ui->tableView_em_2->model()->rowCount();
     const int columnCount = ui->tableView_em_2->model()->columnCount();
    out <<  "<html>\n"
    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des Tache </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView_em_2->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView_em_2->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView_em_2->isColumnHidden(column)) {
                             QString data = ui->tableView_em_2->model()->data(ui->tableView_em_2->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);
}

void health::on_pushButton_imprimer_2_clicked()
{
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}

void health::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{EMPLOYE ee;
    QString inputValue,filtrerChecked;
            inputValue=ui->lineEdit->text();
            ui->tableView_em->setModel(ee.rechercher_2(inputValue,"nom"));
}

void health::on_pushButton_statis_clicked()
{
    health::makePlot_Salaire();

}
QVector<double> health::Statistique_Salaire()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT salaire FROM tache WHERE salaire<=10");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT salaire FROM tache WHERE 10<salaire and salaire<=20");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT salaire FROM tache WHERE 20<salaire and salaire<=30");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT salaire FROM tache WHERE 30<salaire and salaire<=40");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT salaire FROM tache WHERE 40<salaire ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void health::makePlot_Salaire()
{
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot2->xAxis, ui->customPlot2->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, health::Statistique_Salaire());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot2->replot();


    // move bars above graphs and grid below bars:
    ui->customPlot2->addLayer("abovemain", ui->customPlot2->layer("main"), QCustomPlot::limAbove);
    ui->customPlot2->addLayer("belowmain", ui->customPlot2->layer("main"), QCustomPlot::limBelow);
    ui->customPlot2->xAxis->grid()->setLayer("belowmain");
    ui->customPlot2->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"0-10"<<"10-20"<<"20-30"<<"30-40"<<"40-50";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot2->xAxis->setTicker(textTicker);
    ui->customPlot2->xAxis->setSubTicks(false);
    ui->customPlot2->xAxis->setTickLength(0,4);
    ui->customPlot2->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot2->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot2->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot2->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot2->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot2->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot2->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot2->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot2->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot2->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot2->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot2->axisRect()->setBackground(axisRectGradient);

    ui->customPlot2->rescaleAxes();
    ui->customPlot2->xAxis->setRange(0, 7);
    ui->customPlot2->yAxis->setRange(0, 10);


}
void health::detction_de_chaleur()
{
    data=A.read_from_arduino();
    if (data=="1")
    {
        QMessageBox::information(nullptr, QObject::tr("CHALEUR DETECTER"),
                    QObject::tr("UNE CHALEUR A ETE DETECTER .\n"
                                "SVP VOIR ARDUINO ."), QMessageBox::Cancel);
    }
    if (data=="4")

        ui->label_38->setText("LAMPE ALLUMER");//afficher on si les données reçues par arduino est 1

    else if(data=="5")

        ui->label_38->setText("LAMPE ETEINDRE");
}



void health::on_pushButton_alll_clicked()
{
    A.write_to_arduino("4");

}

void health::on_pushButton_desaL_clicked()
{
    A.write_to_arduino("5");

}

void health::on_pushButton_9_clicked()
{

    int num=ui->Enum->text().toInt();
    QString nom=ui->Enom->text();
    QString prenom=ui->Eprenom->text();
   QString DDN=ui->dateEdit->text();
    int contact=ui->Econtact->text().toInt();

patient p(nom,prenom,DDN,contact,num);


bool test=p.ajouter();

        if (test)
     {
            QMessageBox::information(this, "AJOUTE!", "Vous avez ajouté un nouveau patient");
             ui->tab_patient_2->setModel(p.afficher());
}
        else
            QMessageBox::critical(this, "ERREUR", "echec d'ajout");

}


void health::on_pushButton_MODIFIER_clicked()
{
    QString nom= ui->lineEditNom_3->text();
    QString prenom=ui->lineEditPrenom_3->text();
    QString DDN=ui->lineEditDDN_2->text() ;
    int contact=ui->lineEditCONTACT_2->text().toInt();
    int num=ui->lineEditNUM_2->text().toInt();

     patient p(nom,prenom,DDN,contact,num);
     bool test=p.modifier();
     QMessageBox msgBox;
    if(test)
      {  msgBox.setText("Modifier avec succes.");
         ui->tab_patient_2->setModel(p.afficher());
      }
    else
       { msgBox.setText("Echec de modification");
        msgBox.exec();}
}
void health::on_tab_patient_2_activated(const QModelIndex &index)
{
    patient P;
    QMessageBox msgBox;

        QString val = ui->tab_patient_2->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from PATIENTEES where NOM =:val or PRENOM =:val or DDN=:val  ");
        query.bindValue(":val", val);

        if (query.exec())
        {
            while (query.next())
            {
                ui->lineEditNom_3->setText(query.value(0).toString());
                ui->lineEditPrenom_3->setText(query.value(1).toString());
                ui->lineEditDDN_2->setDate(query.value(2).toDate());
                ui->lineEditCONTACT_2->setText(query.value(3).toString());
                ui->lineEditNUM_2->setText(query.value(4).toString());
            }
        }
        else
        {
            msgBox.setText("erreur.");
        }
}

void health::on_pushButton_supp_clicked()
{
    patient p;
    int x=ui->lineEdit_2->text().toInt();
    bool test=p.supprimer(x);
    QMessageBox msgBox;

    if(test)
       {
        msgBox.setText("Suppression avec succes.");
        ui->tab_patient_2->setModel(p.afficher());
        }
    else
       { msgBox.setText("Echec de suppression");
        msgBox.exec();}

}

void health::on_REFRESH_clicked()
{
    patient p;
 ui->tab_patient_2->setModel(p.afficher());
}

void health::on_comboBox_trier_3_activated(const QString &arg1)
{
    patient p ;

       QSqlQueryModel * modal = new QSqlQueryModel();
       QSqlQuery * qry = new QSqlQuery();
       if (arg1=="DDN et nom et prenom ")
       {
        qry->prepare("Select * from patientees order by DDN ,NOM,PRENOM");
        qry->exec();
        modal->setQuery(*qry);
        ui->tab_patient_2->setModel(modal);
        ui->tab_patient_2->show();
       }
      else if (arg1=="DDN")
       {
        qry->prepare("Select * from patientees order by DDN");
        qry->exec();
        modal->setQuery(*qry);
        ui->tab_patient_2->setModel(modal);
        ui->tab_patient_2->show();
       }

       else if (arg1=="Num")
       {
        qry->prepare("Select * from patientees order by NUM  ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tab_patient_2->setModel(modal);
        ui->tab_patient_2->show();
       }
}

void health::on_comboBox_activated(const QString &arg1)
{
    patient p;
        if(arg1=="contact")
        {
        p.chercher(ui->lineEditCONTACT_2->text().toInt());
        ui->tab_patient_2->setModel(p.afficher_unepatient());
        }
        else if (arg1=="Num")
        {
           p.chercher_num(ui->lineEditNUM_2->text().toInt());
            ui->tab_patient_2->setModel(p.afficher_unpatient_num());

        }
        else if (arg1=="nom et prenom")
        {
            p.chercher_nom_prenom(ui->lineEditNom_3->text(),ui->lineEditPrenom_3->text());
            ui->tab_patient_2->setModel(p.afficher_unpatient_nom_prenom());

        }
}

void health::on_ajouter_2_clicked()
{
       int num=ui->linenum_3->text().toInt();
       QString fichier = ui->linecor_3->text();//QFileDialog::getOpenFileName(this, "Ouvrir un fichier"," C://");
       QString antecedent=ui->lineantec_3->text();
       QString comptes=ui->linecomptes_3->text();
       dossiermedical d(num,fichier,antecedent,comptes);
           bool test=d.ajouter();

                   if (test)
                {
                         QMessageBox::information(this, "AJOUTE!", "Vous avez ajouté un dossier");
                       ui->table_dossier->setModel(d.afficher());
                   }
                   else
                       QMessageBox::critical(this, "ERREUR", "echec d'ajout");

           }



void health::on_pushButton_supprimer_2_clicked()
{
    dossiermedical d;
    int x=ui->lineEdit_supp_3->text().toInt();
    bool test=d.supprimer(x);


    if(test)
       {
       QMessageBox::information(this, "supprimé!", "Vous avez supprimé un dossier");
        ui->table_dossier->setModel(d.afficher());
        }
    else  QMessageBox::critical(this, "ERREUR", "echec d'ajout");


}


void health::on_table_dossier_activated(const QModelIndex &index)
{
    dossiermedical d;
    QMessageBox msgBox;

        QString val = ui->table_dossier->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from dossier where fichier =:val or antecedent =:val or comptes=:val  ");
        query.bindValue(":val", val);

        if (query.exec())
        {
            while (query.next())
            {
                ui->linenum_4->setText(query.value(0).toString());
                ui->linecor_4->setText(query.value(1).toString());
                ui->lineantec_4->setText(query.value(2).toString());
                ui->linecomptes_4->setText(query.value(3).toString());
            }
        }
        else
        {
            msgBox.setText("erreur.");
        }
}

void health::on_pushButton_mod_4_clicked()
{
    int num=ui->linenum_4->text().toInt();

    QString fichier= ui->linecor_4->text();
    QString antecedent=ui->lineantec_4->text();
    QString comptes=ui->linecomptes_4->text() ;


     dossiermedical d(num,fichier,antecedent,comptes);
     bool test=d.modifier();
    if(test)
      {    QMessageBox::information(this, "modifié!", "Vous avez modifié un dossier");
        ui->table_dossier->setModel(d.afficher());
        }
    else  QMessageBox::critical(this, "ERREUR", "echec de modification");
}

int health::somme()
{
 //radiologue
    int a=0;
bool b=ui->radio_2->isChecked();
bool b1=ui->radio1_2->isChecked();
bool b2=ui->radio2_2->isChecked();
bool b3=ui->radio3_2->isChecked();
bool b4=ui->radio4_2->isChecked();
bool b5=ui->radio5_2->isChecked();

bool c=ui->allergo1_2->isChecked();
bool c1=ui->allergo2_2->isChecked();
int c2=ui->allergo3_2->text().toInt();
int c3=ui->allergo4_2->text().toInt();

bool d=ui->cardio1_2->isChecked();
bool d1=ui->cardio2_2->isChecked();
bool d2=ui->cardio3_2->isChecked();
bool d3=ui->cardio4_2->isChecked();
int d4=ui->cardio5_2->text().toInt();
int d5=ui->cardio6_2->text().toInt();

bool e=ui->derma1_2->isChecked();
bool e1=ui->derma2_2->isChecked();
bool e2=ui->derma3_2->isChecked();
bool e3=ui->derma4_2->isChecked();
int e4=ui->derma5_2->text().toInt();
int e5=ui->derma6_2->text().toInt();

bool f=ui->cheru1_2->isChecked();
bool f1=ui->cheru2_2->isChecked();
bool f2=ui->cheru3_2->isChecked();
bool f3=ui->cheru4_2->isChecked();
int f4=ui->cheru5_2->text().toInt();
int f5=ui->cheru6_2->text().toInt();

bool g=ui->oph1_2->isChecked();
bool g1=ui->oph2_2->isChecked();
bool g2=ui->oph3_2->isChecked();
bool g3=ui->oph4_2->isChecked();
int g4=ui->oph5_2->text().toInt();
int g5=ui->oph6_2->text().toInt();

bool h=ui->uro1_2->isChecked();
bool h1=ui->uro2_2->isChecked();
bool h2=ui->uro3_2->isChecked();
bool h3=ui->uro4_2->isChecked();
int h4=ui->uro5_2->text().toInt();
int h5=ui->uro6_2->text().toInt();

bool j=ui->psy1_2->isChecked();
bool j1=ui->psy2_2->isChecked();

bool tab[30]={c,c1,b,b1,b2,b3,b4,b5,d,d1,d2,d3,e,e1,e2,e3,f,f1,f2,f3,g,g1,g2,g3,h,h1,h2,h3,j,j1};

for (int i(0);i<30 ;i++)
{ if (tab[i]==true)
         a++;
}
a=a+c2+c3+d4+d5+e4+e5+f4+f5+e4+e5+g4+g5+h4+h5;
return a;

}

void health::on_facturation_2_clicked()
{
int a=somme()*60;
QString a_string=QString::number(a);
//a_string=a"dt";
QMessageBox msgBox;

if (a==0)
{msgBox.setText("RIEN A PAYER !");
    msgBox.exec();}
else
{//msgBox.setText(a_string);
   // msgBox.exec();
ui->textEdit_2->setText(a_string);}

}


void health::on_imprimer_2_clicked()
{

        QPrinter printerr;
        QPrintDialog printDialog(&printerr, this);
        if (printDialog.exec() == QDialog::Accepted)
        ui->textEdit_2->print(&printerr);

}
























/*****************gestion de machine *********************/



void health::on_pushButton_ajout_clicked()
{
    QString nom=ui->lineEdit_nom->text();
    int reference=ui->lineEdit_reference->text().toInt();
    int num=ui->lineEdit_nombre->text().toInt();

 medicament e (nom,reference,num);
 bool test=e.ajouter();
 QMessageBox msgBox;

 if(test)
   {       QMessageBox::information(nullptr, QObject::tr("ajout"),
                                    QObject::tr("ajout succes.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tableView->setModel(e.afficher());

                }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                                    QObject::tr("echec d'ajout.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void health::on_pushButton_mod_3_clicked()
{
   QString nom= ui->lineEdit_nom_2->text();
    int reference=ui->lineEdit_reference_2->text().toInt();
    int  num= ui->lineEdit_nombre_2->text().toInt() ;

   medicament m (nom,reference,num);
   bool test=m.modifier();
    QMessageBox msgBox;
    if(test)
      {  msgBox.setText("Modifier avec succes.");
        ui->tableView->setModel(m.afficher());
    }
    else
       { msgBox.setText("Echec de modification");
        msgBox.exec();
}
}

void health::on_pushButton_supp_2_clicked()
{
    int x =ui->lineEdit_reference_2->text().toInt();
     bool test=m.supprimer(x);
     QMessageBox msgBox;

     if(test)
        {
     msgBox.setText("Suppression avec succes.");
     ui->tableView->setModel(m.afficher());//refreche

     }
     else
         msgBox.setText("Echec de suppression");
         msgBox.exec();
}
void health::on_tableView_activated(const QModelIndex &index)
{
    medicament m;
       QString val = ui->tableView->model()->data(index).toString();
       QString num_string= QString::number(m.get_num());
       QString reference_string= QString::number(m.get_reference());


       QSqlQuery query;
        query.prepare("select * from MEDICAMENTS where nom=:val or reference=:val or num=:val  ");
        query.bindValue(":val", val);

       if (query.exec())
       {
           while (query.next())
           {
               ui->lineEdit_nom_2->setText(query.value(0).toString());
               ui->lineEdit_reference_2->setText(query.value(1).toString());
               ui->lineEdit_nombre_2->setText(query.value(2).toString());

           }
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("erreur"),
                       QObject::tr("erreur.\n"
                                   "erreur."), QMessageBox::Cancel);       }
}

void health::on_pushButton_R_clicked()
{
  medicament m;
  ui->tableView->setModel(m.afficher());
}


void health::on_comboBox_trier_4_activated(const QString &arg1)
{
    medicament m;
   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * qry = new QSqlQuery();
   if (arg1=="Num")
   {
    qry->prepare("Select * from MEDICAMENTS  order by num ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
  else if (arg1=="Reference")
   {
    qry->prepare("Select * from MEDICAMENTS order by Reference desc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }

   else if (arg1=="Reference et Nom et Num")
   {
    qry->prepare("Select * from MEDICAMENTS  order by Nom ,num, Reference ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
}

void health::on_comboBox_reche_activated(const QString &arg1)
{
        medicament m;
    if(arg1=="Reference")
    {
    m.chercher_reference(ui->lineEdit_reference_2->text().toInt());
    ui->tableView->setModel(m.afficher_reference());
    }
    else if (arg1=="Nom")
    {
        m.chercher_nom(ui->lineEdit_nom_2->text());
        ui->tableView->setModel(m.afficher_nom());

    }
    else if (arg1=="Nom et Num")
    {
        m.chercher_nom_num(ui->lineEdit_nombre_2->text().toInt(),ui->lineEdit_nom_2->text());
        ui->tableView->setModel(m.afficher_nom_num());

    }
}











void health::on_pushButton_ajouter2_clicked()
{

    QString nom=ui->lineEdit_nom_7->text();
    int reference=ui->lineEdit_ref_7->text().toInt();
    int num=ui->lineEdit_num->text().toInt();

 machine e (nom,reference,num);
 bool test=e.ajouter();
 QMessageBox msgBox;

 if(test)
   {       QMessageBox::information(nullptr, QObject::tr("ajout"),
                                    QObject::tr("ajout succes.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tableView_3->setModel(e.afficher());

                }

                    else
                        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                                    QObject::tr("echec d'ajout.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void health::on_pushButton_mod_9_clicked()
{
    QString nom= ui->lineEdit_nom_5->text();
     int reference=ui->lineEdit_reference_6->text().toInt();
     int  num= ui->lineEdit_nombre_6->text().toInt() ;

     machine e (nom,reference,num);
    bool test=e.modifier();
     QMessageBox msgBox;
     if(test)
       {  msgBox.setText("Modifier avec succes.");
         ui->tableView_3->setModel(e.afficher());
     }
     else
        { msgBox.setText("Echec de modification");
         msgBox.exec();
 }
 }



void health::on_pushButton_supp_5_clicked()
{
    machine e;

    int x =ui->lineEdit_reference_6->text().toInt();
     bool test=e.supprimer(x);
     QMessageBox msgBox;

     if(test)
        {
     msgBox.setText("Suppression avec succes.");
     ui->tableView_3->setModel(e.afficher());//refreche

     }
     else
     {
         msgBox.setText("Echec de suppression");
         msgBox.exec();
     }
}


void health::on_tableView_3_activated(const QModelIndex &index)
{
    machine e;
       QString val = ui->tableView_3->model()->data(index).toString();
       QString num_string= QString::number(e.get_num());
       QString reference_string= QString::number(e.get_reference());


       QSqlQuery query;
        query.prepare("select * from machines where nom=:val or reference=:val or num=:val  ");
        query.bindValue(":val", val);

       if (query.exec())
       {
           while (query.next())
           {
               ui->lineEdit_nom_5->setText(query.value(0).toString());
               ui->lineEdit_reference_6->setText(query.value(1).toString());
               ui->lineEdit_nombre_6->setText(query.value(2).toString());

           }
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("erreur"),
                       QObject::tr("erreur.\n"
                                   "erreur."), QMessageBox::Cancel);
       }

}

void health::on_pushButton_refreche_5_clicked()
{
    machine e;
    ui->tableView_3->setModel(e.afficher());
}

void health::on_comboBox_trier_9_activated(const QString &arg1)
{
    machine e;
   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * qry = new QSqlQuery();
   if (arg1=="Num")
   {
    qry->prepare("Select * from machines order by num ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_3->setModel(modal);
    ui->tableView_3->show();
   }
  else if (arg1=="Reference")
   {
    qry->prepare("Select * from machines order by Reference desc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_3->setModel(modal);
    ui->tableView_3->show();
   }

   else if (arg1=="Reference et Nom et Num")
   {
    qry->prepare("Select * from machines  order by Nom ,num, Reference ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_3->setModel(modal);
    ui->tableView_3->show();
   }


}
void health:: on_comboBox_reche_3_activated(const QString &arg1)
{
            machine e;
                if(arg1=="Reference")
                {
                e.chercher_reference(ui->lineEdit_reference_6->text().toInt());
                ui->tableView_3->setModel(e.afficher_reference());
                }

                else if (arg1=="Nom")
                {
                    e.chercher_nom(ui->lineEdit_nom_5->text());
                    ui->tableView_3->setModel(e.afficher_nom());

                }
                else if (arg1=="Nom et Num")
                {
                    e.chercher_nom_num(ui->lineEdit_nombre_6->text().toInt(),ui->lineEdit_nom_5->text());
                    ui->tableView_3->setModel(e.afficher_nom_num());
                  }
}

/************************* Gestion des donneurs et des dons *****************************/


void health::on_pushButton_AjouterDonneur_2_clicked()
{
    QString cin = ui->cINLineEdit_2->text();
        QString nom= ui->nomLineEdit_2->text();
        QString prenom= ui->prenomLineEdit_2->text();
        QString email= ui->eMailLineEdit_2->text();
        QString sexe = ui->sexeComboBox_2->currentText();
        QString groupesanguin= ui->groupSanguinComboBox_2->currentText();
        QDate dateprelev= ui->dateDePrelevementDateEdit_2->date();



        donneur donneur(cin,nom,prenom,email,sexe,groupesanguin,dateprelev);

        bool test=donneur.ajouter();

        if (test)
            ui->tableViewDonneur_2->setModel(tmpdonneur.afficher());

}

void health::on_pushButton_ModifierDonneur_2_clicked()
{
    if (ui->pushButton_ModifierDonneur_2->isChecked())
        {
            ui->pushButton_ModifierDonneur_2->setDisabled(true);
            ui->pushButton_ModifierDonneur_2->setText("Modifiable");
            QSqlTableModel *tableModel= new QSqlTableModel();
            tableModel->setTable("DONNEUR");
            tableModel->select();
            ui->tableViewDonneur_2->setModel(tableModel);
            ui->pushButton_ModifierDonneur_2->setDisabled(false);
        }
        else
        {
            ui->pushButton_ModifierDonneur_2->setText("Modifier");
            ui->comboBox_CIN->clear();
            ui->comboBox_CIN->addItems(dn.getCINs());
            ui->tableViewDonneur_2->setModel(tmpdonneur.afficher());
        }
}

void health::on_pushButton_SupprimerDonneur_2_clicked()
{
    QItemSelectionModel *select = ui->tableViewDonneur_2->selectionModel();
    QMessageBox msgbox;
    int cin =select->selectedRows(0).value(0).data().toInt();
    msgbox.setWindowTitle("supprimer");
    msgbox.setText("voulez_vous supprimer cette réclamation?");
    msgbox.setStandardButtons(QMessageBox ::Yes);
    msgbox.addButton(QMessageBox::No);
    if(msgbox.exec()==QMessageBox::Yes)
    {

        if(tmpdonneur.supprimer(cin))
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
            ui->comboBox_CIN->clear();
            ui->comboBox_CIN->addItems(dn.getCINs());
            ui->tableViewDonneur_2->setModel(tmpdonneur.afficher());
            //ui->statusbar->showMessage("Donneur supprimé");
        }

}
}

void health::on_pushButton_ImprimerDonneur_2_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableViewDonneur_2->model()->rowCount();
    const int columnCount = ui->tableViewDonneur_2->model()->columnCount();

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg("Title")
          <<  "</head>\n"
              "<body bgcolor=#ffffff link=#5000A0>\n"
              "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableViewDonneur_2->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableViewDonneur_2->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableViewDonneur_2->isColumnHidden(column)) {
                QString data = ui->tableViewDonneur_2->model()->data(ui->tableViewDonneur_2->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;
}

void health::on_pushButton_RechercherDonneur_2_clicked()
{
    QString input=ui->lineEditRdonneur_2->text();
    if (ui->checkBox_nom_2->isChecked() && !ui->checkBox_type_2->isChecked() && !ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.rechercherNom(input));
    else if (!ui->checkBox_nom_2->isChecked() && ui->checkBox_type_2->isChecked() && !ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.rechercherGroupeS(input));
    else if (!ui->checkBox_nom_2->isChecked() && !ui->checkBox_type_2->isChecked() && ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.rechercherDate(input));
}

void health::on_pushButton_TrierDonneur_2_clicked()
{
    if (ui->checkBox_nom_2->isChecked() && !ui->checkBox_type_2->isChecked() && !ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.trier("NOM",ui->comboBox_3->currentText()));
    else if (!ui->checkBox_nom_2->isChecked() && ui->checkBox_type_2->isChecked() && !ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.trier("GROUPE_SANGUIN",ui->comboBox_3->currentText()));
    else if (!ui->checkBox_nom_2->isChecked() && !ui->checkBox_type_2->isChecked() && ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.trier("DATE_PRELEV",ui->comboBox_3->currentText()));
    else if (ui->checkBox_nom_2->isChecked() && ui->checkBox_type_2->isChecked() && !ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.trier("NOM,GROUPE_SANGUIN",ui->comboBox_3->currentText()));
    else if (ui->checkBox_nom_2->isChecked() && !ui->checkBox_type_2->isChecked() && ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.trier("NOM,DATE_PRELEV",ui->comboBox_3->currentText()));
    else if (!ui->checkBox_nom_2->isChecked() && ui->checkBox_type_2->isChecked() && ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.trier("GROUPE_SANGUIN,DATE_PRELEV",ui->comboBox_3->currentText()));
    else if (ui->checkBox_nom_2->isChecked() && ui->checkBox_type_2->isChecked() && ui->checkBox_date_2->isChecked())
        ui->tableViewDonneur_2->setModel(tmpdonneur.trier("NOM,GROUPE_SANGUIN,DATE_PRELEV",ui->comboBox_3->currentText()));
}

void health::on_pushButton_statistique_2_clicked()
{
    float s;
    don d;
    s=d.stat1();
    ui->lab_stat1_2->setNum(s);
    float s1;
    s1=d.stat2();
    ui->lab_stat2_2->setNum(s1);
    float s2;
    s2=d.stat3();
    ui->lab_stat3_2->setNum(s2);
    float s3;
    s3=d.stat4();
    ui->lab_stat4_2->setNum(s3);

    if(s==0 || s1==0 || s2==0 || s3==0) {
        A.write_to_arduino("1");
    } else {
         A.write_to_arduino("0");
    }

}


void health::on_pushButtonAjouterDon_2_clicked()
{
    donneur dn;
    int id=ui->referenceLineEdit_2->text().toInt();
    int quantite = ui->quantiteLineEdit_2->text().toInt();
    QString date_prelev= dn.getDatePrel(ui->comboBox_CIN->currentText());
    QString emplacement=ui->emplacementLineEdit_2->text();
    QString cin = ui->comboBox_CIN->currentText();

    don don(id,quantite,emplacement,date_prelev,cin);

    bool test=don.ajouter();

    if (test)
    {
        ui->tableViewDon_2->setModel(tmpdon.afficher());
        // ui->statusbar->showMessage("Don ajouté");
    }
}

void health::on_pushButtonModifierDon_2_clicked()
{
    if (ui->pushButtonModifierDon_2->isChecked())
    {
        ui->pushButtonModifierDon_2->setDisabled(true);
        ui->pushButtonModifierDon_2->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("DON");
        tableModel->select();
        ui->tableViewDon_2->setModel(tableModel);
        ui->pushButtonModifierDon_2->setDisabled(false);
    }
    else
    {
        ui->pushButtonModifierDon_2->setText("Modifier");
        ui->tableViewDon_2->setModel(tmpdon.afficher());

    }

}

void health::on_pushButtonSupprimerDon_2_clicked()
{
    QItemSelectionModel *select = ui->tableViewDon_2->selectionModel();

    int id =select->selectedRows(0).value(0).data().toInt();

    if(tmpdon.supprimer(id))
    {
        ui->tableViewDon_2->setModel(tmpdon.afficher());
       // ui->statusbar->showMessage("Don supprimé");
    }

}

void health::on_pushButtonImprimerDon_2_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableViewDon_2->model()->rowCount();
    const int columnCount = ui->tableViewDon_2->model()->columnCount();

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg("Title")
          <<  "</head>\n"
              "<body bgcolor=#ffffff link=#5000A0>\n"
              "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableViewDon_2->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableViewDon_2->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableViewDon_2->isColumnHidden(column)) {
                QString data = ui->tableViewDon_2->model()->data(ui->tableViewDon_2->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;
}

void health::on_pushButtonRechercheDon_2_clicked()
{
    QString recherche=ui->lineEditRechercheDon_2->text();
    if (ui->checkBoxRefDon_2->isChecked() && !ui->checkBoxQuantiteDon_2->isChecked() && !ui->checkBoxDateDon_2->isChecked())
    {
        int rechercheint=ui->lineEditRechercheDon_2->text().toInt();
        ui->tableViewDon_2->setModel(tmpdon.rechercherID(rechercheint));
    }
    else if (!ui->checkBoxRefDon_2->isChecked() && ui->checkBoxQuantiteDon_2->isChecked() && !ui->checkBoxDateDon_2->isChecked())
    {
        int rechercheint=ui->lineEditRechercheDon_2->text().toInt();
        ui->tableViewDon_2->setModel(tmpdon.rechercherQuantite(rechercheint));
    }
    else if (!ui->checkBoxRefDon_2->isChecked() && !ui->checkBoxQuantiteDon_2->isChecked() && ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.rechercherDate(recherche));
}

void health::on_pushButtonTrierDon_2_clicked()
{
    if (ui->checkBoxRefDon_2->isChecked() && !ui->checkBoxQuantiteDon_2->isChecked() && !ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.trier("ID_DON",ui->comboBoxDon_2->currentText()));
    else if (!ui->checkBoxRefDon_2->isChecked() && ui->checkBoxQuantiteDon_2->isChecked() && !ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.trier("QUANTITE",ui->comboBoxDon_2->currentText()));
    else if (!ui->checkBoxRefDon_2->isChecked() && !ui->checkBoxQuantiteDon_2->isChecked() && ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.trier("DATE_PRELEV",ui->comboBoxDon_2->currentText()));
    else if (ui->checkBoxRefDon_2->isChecked() && ui->checkBoxQuantiteDon_2->isChecked() && !ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.trier("ID_DON,QUANTITE",ui->comboBoxDon_2->currentText()));
    else if (ui->checkBoxRefDon_2->isChecked() && !ui->checkBoxQuantiteDon_2->isChecked() && ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.trier("ID_DON,DATE_PRELEV",ui->comboBoxDon_2->currentText()));
    else if (!ui->checkBoxRefDon_2->isChecked() && ui->checkBoxQuantiteDon_2->isChecked() && ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.trier("QUANTITE,DATE_PRELEV",ui->comboBoxDon_2->currentText()));
    else if (ui->checkBoxRefDon_2->isChecked() && ui->checkBoxQuantiteDon_2->isChecked() && ui->checkBoxDateDon_2->isChecked())
        ui->tableViewDon_2->setModel(tmpdon.trier("ID_DON,QUANTITE,DATE_PRELEV",ui->comboBoxDon_2->currentText()));
}

/*********************************************************************/

void health::afficher()
{   Connection c;
QSqlQueryModel* modal = new QSqlQueryModel();
QSqlQuery* qry=new QSqlQuery(c.get_db());
qry->prepare("SELECT* from contrat");
qry->exec();
modal->setQuery(*qry);
ui->tableView_gc->setModel(modal);
}
void health::on_pushButton_gc_clicked()
{

ui->stackedWidget->setCurrentIndex(1);
ui->tableView_gc->setSelectionBehavior(QAbstractItemView::SelectRows);
contrat c;
c.affichertable(ui);
}

void health::on_pushButton_2_gc_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView_2_gc->setSelectionBehavior(QAbstractItemView::SelectRows);
    partenaire c;
    c.affichertable(ui);
}

void health::on_pushButton_14_gc_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void health::on_pushButton_15_gc_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void health::on_pushButton_7_gc_clicked()
{
    ui->tableView_gc->setSelectionBehavior(QAbstractItemView::SelectRows);
    contrat c;
    c.ajouter(ui);
    c.affichertable(ui);
}

void health::on_tableView_gc_clicked(const QModelIndex &index)
{
    ui->lineEdit_18_gc->setText(ui->tableView_gc->model()->data(ui->tableView_gc->model()->index(ui->tableView_gc->selectionModel()->currentIndex().row(),0)).toString());
            ui->lineEdit_19_gc->setText(ui->tableView_gc->model()->data(ui->tableView_gc->model()->index(ui->tableView_gc->selectionModel()->currentIndex().row(),1)).toString());
            ui->lineEdit_20_gc->setText(ui->tableView_gc->model()->data(ui->tableView_gc->model()->index(ui->tableView_gc->selectionModel()->currentIndex().row(),2)).toString());
            ui->lineEdit_21_gc->setText(ui->tableView_gc->model()->data(ui->tableView_gc->model()->index(ui->tableView_gc->selectionModel()->currentIndex().row(),3)).toString());
            ui->lineEdit_22_gc->setText(ui->tableView_gc->model()->data(ui->tableView_gc->model()->index(ui->tableView_gc->selectionModel()->currentIndex().row(),4)).toString());
}

void health::on_pushButton_8_gc_clicked()
{
    contrat c;
    c.modifier(ui);
    c.affichertable(ui);
}

void health::on_pushButton_9_gc_clicked()
{
    contrat c;
c.supprimer(ui);
c.affichertable(ui);
}

void health::on_pushButton_16_gc_clicked()
{
    QString valeur =ui->lineEdit_9_gc->text();
    contrat *e= new contrat();
    ui->tableView_gc->setModel(e->recherchercontrat(valeur));
}

void health::on_pushButton_6_gc_clicked()
{
    contrat *e = new contrat();
    ui->tableView_gc->setModel(e->triercontrat());
}

void health::on_pushButton_18_gc_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}
QVector<double> health::Statistique_remise()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT remise FROM contrat WHERE remise<=10");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT remise FROM contrat WHERE 10<remise and remise<=20");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT remise FROM contrat WHERE 20<remise and remise<=30");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT remise FROM contrat WHERE 30<remise and remise<=40");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT remise FROM contrat WHERE 40<remise ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void health::makePlot_remise()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, health::Statistique_remise());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();


    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"0-10"<<"10-20"<<"20-30"<<"30-40"<<"40-50";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);


}

void health::on_pushButton_17_gc_clicked()
{
    health::makePlot_remise();
}

void health::on_pushButton_19_gc_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void health::on_pushButton_3_gc_clicked()
{
    ui->tableView_2_gc->setSelectionBehavior(QAbstractItemView::SelectRows);
    partenaire c;
    c.ajouter(ui);
    c.affichertable(ui);
}

void health::on_tableView_2_gc_clicked(const QModelIndex &index)
{
    ui->lineEdit_gc->setText(ui->tableView_2_gc->model()->data(ui->tableView_2_gc->model()->index(ui->tableView_2_gc->selectionModel()->currentIndex().row(),0)).toString());
            ui->lineEdit_4_gc->setText(ui->tableView_2_gc->model()->data(ui->tableView_2_gc->model()->index(ui->tableView_2_gc->selectionModel()->currentIndex().row(),1)).toString());
            ui->lineEdit_3_gc->setText(ui->tableView_2_gc->model()->data(ui->tableView_2_gc->model()->index(ui->tableView_2_gc->selectionModel()->currentIndex().row(),2)).toString());
            ui->lineEdit_2_gc->setText(ui->tableView_2_gc->model()->data(ui->tableView_2_gc->model()->index(ui->tableView_2_gc->selectionModel()->currentIndex().row(),3)).toString());
            ui->lineEdit_5_gc->setText(ui->tableView_2_gc->model()->data(ui->tableView_2_gc->model()->index(ui->tableView_2_gc->selectionModel()->currentIndex().row(),4)).toString());
            ui->lineEdit_6_gc->setText(ui->tableView_2_gc->model()->data(ui->tableView_2_gc->model()->index(ui->tableView_2_gc->selectionModel()->currentIndex().row(),5)).toString());


}

void health::on_pushButton_4_gc_clicked()
{
    partenaire c;
    c.modifier(ui);
    c.affichertable(ui);
}

void health::on_pushButton_11_gc_clicked()
{
    partenaire c;
c.supprimer(ui);
c.affichertable(ui);
}

void health::on_pushButton_10_gc_clicked()
{

    QString valeur =ui->lineEdit_17_gc->text();
    partenaire *e= new partenaire();
    ui->tableView_2_gc->setModel(e->rechercherpartenaire(valeur));
}

void health::on_pushButton_12_gc_clicked()
{
    partenaire *e = new partenaire();
    ui->tableView_2_gc->setModel(e->trierpartenaire());
}

void health::on_pushButton_5_gc_clicked()
{        contrat *e = new contrat();
         ui->tableView_gc->setModel(e->triercontrat_desc());//refresh .
    }

// ----------------- example of inharitance from PagePrepare ---------------------

class PrintBorder : public PagePrepare
{
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter)
{ // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}

// --------------------------------------------------------------------------------



void health::uglyPrint2(QPrinter *printer) {

    // ---------------- death-to-designers example Event------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 0 <<10 <<5;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "id" << "nomp" << "duree" << "dater"<< "remise" ;

    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE contrat");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tableView_gc->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}




void health::on_pushButton_20_gc_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint2(QPrinter*)));
    dialog.exec();
}

void health::on_comboBox_resou_activated(const QString &arg1)
{
    if(arg1=="Gérer les Employés")
    {
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(arg1=="Gérer Les Taches ")
    {
        ui->stackedWidget_2->setCurrentIndex(2);
    }
}

void health::on_comboBox_pat_activated(const QString &arg1)
{
    if(arg1=="Gérer les patients")
    {
        ui->stackedWidget_2->setCurrentIndex(4);
    }
    else if(arg1=="Gérer les dossiers médicales")
    {
        ui->stackedWidget_2->setCurrentIndex(5);
    }
    else if(arg1=="Facturation")
    {
        ui->stackedWidget_2->setCurrentIndex(6);
    }
}

void health::on_comboBox_mach_activated(const QString &arg1)
{
    if(arg1=="Gérer les machines")
    {
        ui->stackedWidget_2->setCurrentIndex(8);
    }
    else if(arg1=="Gérer les médicaments")
    {
        ui->stackedWidget_2->setCurrentIndex(7);
    }
}

void health::on_comboBox_rend_activated(const QString &arg1)
{
    if(arg1=="Gérer les réservations")
    {
        ui->stackedWidget_2->setCurrentIndex(13);
          ui->stackedWidget_9->setCurrentIndex(4);
    }
    else if(arg1=="Gérer les emploi du temps")
    {
        ui->stackedWidget_2->setCurrentIndex(14);
        ui->stackedWidget_8->setCurrentIndex(4);
    }
}

void health::on_comboBox_contrat_activated(const QString &arg1)
{
    if(arg1=="Gérer les Partenaires  et les contrats")
    {
        ui->stackedWidget_2->setCurrentIndex(9);
    }

}

void health::on_comboBox_dons_activated(const QString &arg1)
{
    if(arg1=="Gérerles Donneurs et les Dons ")
    {
        ui->stackedWidget_2->setCurrentIndex(3);
    }
}

void health::on_comboBox_arduino_activated(const QString &arg1)
{
    if(arg1=="Arduino ")
    {
        ui->stackedWidget_2->setCurrentIndex(10);

    }
}




void health::on_pushButton_ret1_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret8_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret9_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret10_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}

void health::on_pushButton_ret11_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_ret15_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);

}
void health::on_pushButton_ret200_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);

}
void health::on_pushButton_ret202_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}
void health::on_pushButton_son_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(15);

}

void health::on_pushButton_salaire_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(12);

}


void health::on_pushButton_calculer_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(11);

}
void health::on_pushButton_reservation_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(13);
      ui->stackedWidget_9->setCurrentIndex(4);

}

void health::on_pushButton_emploi_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(14);
    ui->stackedWidget_8->setCurrentIndex(4);


}
void health::on_calculBouton_clicked()
{
    float nbr2, calculNbr;
    nbr2 = ui->resultLine->text().toFloat();
    if(action == diviser) {
        if(nbr2 != 0) {
            calculNbr = premierNombre / nbr2;
        } else {
            calculNbr = 0;
            QMessageBox::critical(this, "Calculatrice - sKy", "Math Error! (x/0)");
        }
    } else if (action == additionner) {
        calculNbr = premierNombre + nbr2;
    } else if (action == multiplier) {
        calculNbr = premierNombre * nbr2;
    } else if (action == soustraire) {
        calculNbr = premierNombre - nbr2;
    }
    ui->resultLine->setText(QString::number(calculNbr));
    ansNombre = QString::number(calculNbr);
    premierNombre = 0;
}

void health::on_diviserBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre = ui->resultLine->text().toFloat();
        action = diviser;
        ui->resultLine->setText("0");
    }
}

void health::on_additionnerBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre =ui->resultLine->text().toFloat();
        action = additionner;
        ui->resultLine->setText("0");
    }
}

void health::on_multiplierBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre = ui->resultLine->text().toFloat();
        action = multiplier;
        ui->resultLine->setText("0");
    }
}

void health::on_soustraireBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre = ui->resultLine->text().toFloat();
        action = soustraire;
        ui->resultLine->setText("0");
    }
}

void health::on_number0_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("0");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("0");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "0");
    }
}

void health::on_number1_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("1");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("1");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "1");
    }
}

void health::on_number2_clicked()
{
     if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("2");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("2");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "2");
    }
}

void health::on_number3_clicked()
{
     if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("3");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("3");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "3");
    }
}

void health::on_number4_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("4");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
       ui->resultLine->setText("4");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "4");
    }
}

void health::on_number5_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("5");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("5");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "5");
    }
}

void health::on_number6_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("6");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("6");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "6");
    }
}

void health::on_number7_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("7");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("7");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "7");
    }
}

void health::on_number8_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("8");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("8");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "8");
    }
}

void health::on_number9_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("9");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("9");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "9");
    }
}

void health::on_clearBouton_clicked()
{
    ui->resultLine->setText("0");
    premierNombre = 0;
}

void health::on_ansBouton_clicked()
{
    if(ansNombre != 0) {
        ui->resultLine->setText(ansNombre);
    }
}

void health::on_virguleBouton_clicked()
{
    ui->resultLine->setText(ui->resultLine->text() + ".");
}



void health::on_ajouter_emp_clicked()
{    int id_res = ui->id_res->text().toInt();
      int id_doc = ui->id_res->text().toInt();
    QString email_doc = ui->email_doc->text();
      QString date_rv = ui->date_rv->text();
        int heure_rv = ui->heure_rv->text().toInt();

    emploi e (id_res,id_doc,email_doc,date_rv,heure_rv);
     int i,test1=0;
     for (i=0;i<date_rv.length();i++)
                  {
           if( date_rv[i]=="/")
           {
                test1=1;

           }
                  }
      if(test1==1)
             {

      bool test=e.ajouter(id_res,id_doc,email_doc,date_rv,heure_rv);
      if(test)
    {ui->tabemploi_2->setModel(tmpemp.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un emploi du temps"),
                      QObject::tr("Emploi du temps ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      ui->stackedWidget_8->setCurrentIndex(1);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi du temps"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }
      else
                QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi du temps"),
                            QObject::tr("Date incorrect !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void health::on_supprimer_emploi_clicked()
{
    int id = ui->reference_sup_e->text().toInt();
    bool test=tmpemp.supprimer(id);
    if(test)
    { const int DeltaPos = 10;

        QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
        animation->setDuration(500);


           /* Animation mainwindow*/
            int oldX = pos().x();
            animation->setEasingCurve(QEasingCurve(static_cast<QEasingCurve::Type>(10)));
            animation->setKeyValueAt(0.0, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.1, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.2, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.3, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.4, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.5, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.6, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.7, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.8, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.9, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(1.0, QPoint(oldX, pos().y()));


        animation->start(QAbstractAnimation::DeleteWhenStopped);
        ui->tabemploi_2->setModel(tmpemp.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer l'emploi"),
                    QObject::tr("EMPLOI supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget_8->setCurrentIndex(1);



}
}

void health::on_modifier_emp_clicked()
{
    int id_res = ui->id_res->text().toInt();
         int id_doc = ui->id_res->text().toInt();
       QString email_doc = ui->email_doc->text();
         QString date_rv = ui->date_rv->text();
           int heure_rv = ui->heure_rv->text().toInt();
    emploi E;
    bool test=false;
    { if((heure_rv<0)||(heure_rv))
            test=true;}
     if(test)E.modifier(id_res,id_doc,email_doc,date_rv,heure_rv);
    if(test)
  {ui->tabemploi_2->setModel(tmpemp.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un emploi du temps"),
                    QObject::tr("EMPLOI modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un emploi du temps"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
}

void health::on_chercher_emploi_clicked()
{
    int id = ui->chercher_id->text().toInt();
            ui->afficher_emp->setModel(tmpemp.recherche_e(id));
}

void health::on_imprimer_emploi_clicked()
{
    /*QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->afficher_emp->model()->rowCount();
            const int columnCount = ui->afficher_emp->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - COMmANDE LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> *****LISTE DES EMPLOI DU TEMPS ***** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->afficher_emp->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->afficher_emp->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->afficher_emp->isColumnHidden(column)) {
                        QString data =ui->afficher_emp->model()->data(ui->afficher_emp->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *baba = new QPrintDialog(&printer, NULL);
            if (baba->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;*/
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tabemploi_2->model()->rowCount();
            const int columnCount =ui->tabemploi_2->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("emploi du temps")
                    <<  "</head>\n"
                    "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                        "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='100' height='100'>\n"
                        "<h1>Liste des emploi du temps</h1>"



                        "<table border=1 cellspacing=0 cellpadding=2>\n";


            // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabemploi_2->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabemploi_2->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tabemploi_2->isColumnHidden(column)) {
                               QString data = ui->tabemploi_2->model()->data(ui->tabemploi_2->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                       "</body>\n"
                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;

                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {
                       document->print(&printer);

}
}

void health::on_trier_emploi_cr_clicked()
{
    ui->tabemploi_2->setModel(tmpemp.tri(1));
}

void health::on_trier_emploi_decr_clicked()
{
      ui->tabemploi_2->setModel(tmpemp.tri(0));
}

void health::on_ajouter_res_clicked()
{
       int id_r = ui->id_r->text().toInt();
       QString nom_pat = ui->nom_pat->text();
       QString prenom_pat = ui->prenom_pat->text();
       QString email_pat = ui->email_pat->text();
       QString date_r = ui->date_r->text();
       QString sex_e = ui->sex_e->text();


       reservation e (id_r,nom_pat,prenom_pat,email_pat,date_r,sex_e);
       int i,test1=0;



               for (i=0;i<date_r.length();i++)
               {
        if( date_r[i]=="/")
        {
             test1=1;

        }
               }
               if(nom_pat.contains(QRegExp("^[A-Za-z ]+$")))
               {
               if(prenom_pat.contains(QRegExp("^[A-Za-z ]+$")))
               {
       if(test1==1)
       {

         bool test=e.ajouter(id_r,nom_pat,prenom_pat,email_pat,date_r,sex_e);

         if(test)
       {ui->tabreservation_2->setModel(tmpres.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                         QObject::tr("reservation ajouté.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
       ui->stackedWidget_9->setCurrentIndex(1);


       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi du temps"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi du temps"),
                       QObject::tr("Date incorrect !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi du temps"),
                               QObject::tr("Prenom incorrect !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi du temps"),
                               QObject::tr("nom incorrect !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}


void health::on_supprimer_res_clicked()
{
    int id = ui->reference_sup_e_2->text().toInt();
    bool test=tmpres.supprimer(id);
    if(test)
    {
        const int DeltaPos = 10;

                   QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
                   animation->setDuration(500);


                      /* Animation mainwindow*/
                       int oldX = pos().x();
                       animation->setEasingCurve(QEasingCurve(static_cast<QEasingCurve::Type>(10)));
                       animation->setKeyValueAt(0.0, QPoint(oldX - DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.1, QPoint(oldX + DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.2, QPoint(oldX - DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.3, QPoint(oldX + DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.4, QPoint(oldX - DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.5, QPoint(oldX + DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.6, QPoint(oldX - DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.7, QPoint(oldX + DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.8, QPoint(oldX - DeltaPos, pos().y()));
                       animation->setKeyValueAt(0.9, QPoint(oldX + DeltaPos, pos().y()));
                       animation->setKeyValueAt(1.0, QPoint(oldX, pos().y()));


                   animation->start(QAbstractAnimation::DeleteWhenStopped);
        ui->tabreservation_2->setModel(tmpres.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer Reservation "),
                    QObject::tr("Reservation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget_9->setCurrentIndex(1);


}
}

void health::on_modifier_res_clicked()
{
    int id_r = ui->id_r->text().toInt();
    QString nom_pat = ui->nom_pat->text();
    QString prenom_pat = ui->prenom_pat->text();
    QString email_pat = ui->email_pat->text();
    QString date_r = ui->date_r->text();
    QString sex_e = ui->sex_e->text();
    reservation E;

      bool test= E.modifier(id_r,nom_pat,prenom_pat,email_pat,date_r,sex_e);
    if(test)
  {ui->tabreservation_2->setModel(tmpres.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                    QObject::tr("RESERVATION modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  ui->stackedWidget_9->setCurrentIndex(1);


}


    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
}



void health::on_chercher_employe_clicked()
{
    int id = ui->chercher_e->text().toInt();
            ui->afficher_trie->setModel(tmpres.recherche_e(id));
}

void health::on_imprimer_res_clicked()
{
    /*QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->afficher_trie->model()->rowCount();
            const int columnCount = ui->afficher_trie->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - COMmANDE LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> *****LISTE DES RESERVATIONS ***** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->afficher_trie->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->afficher_trie->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->afficher_trie->isColumnHidden(column)) {
                        QString data =ui->afficher_trie->model()->data(ui->afficher_trie->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *baba = new QPrintDialog(&printer, NULL);
            if (baba->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;*/
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tabreservation_2->model()->rowCount();
            const int columnCount =ui->tabreservation_2->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("reservation")
                    <<  "</head>\n"
                    "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                        "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='100' height='100'>\n"
                        "<h1>Liste des reservation</h1>"



                        "<table border=1 cellspacing=0 cellpadding=2>\n";


            // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabreservation_2->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabreservation_2->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tabreservation_2->isColumnHidden(column)) {
                               QString data = ui->tabreservation_2->model()->data(ui->tabreservation_2->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                       "</body>\n"
                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;

                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {
                       document->print(&printer);

}}

void health::on_tri_asc_res_clicked()
{
      ui->tabreservation_2->setModel(tmpres.tri(1));
}

void health::on_tri_desc_res_clicked()
{
    ui->tabreservation_2->setModel(tmpres.tri(0));
}

/*void health::on_statistiques_res_clicked()
{
    Statistique *a=new Statistique();
    a->show();
}

*/





void health::on_pushButton_4_clicked()
{
    ui->stackedWidget_9->setCurrentIndex(0);

}

void health::on_pushButton_5_clicked()
{
    ui->tabreservation_2->setModel(tmpres.afficher());
    ui->stackedWidget_9->setCurrentIndex(1);

}

void health::on_pushButton_6_clicked()
{
    ui->stackedWidget_9->setCurrentIndex(2);

}

void health::on_pushButton_7_clicked()
{
    ui->stackedWidget_9->setCurrentIndex(3);

}

void health::on_pushButton_12_clicked()
{
    ui->stackedWidget_9->setCurrentIndex(4);

}

void health::on_pushButton_15_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);

}

void health::on_pushButton_16_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
    ui->tabemploi_2->setModel(tmpemp.afficher());
}

void health::on_pushButton_17_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(2);
}

void health::on_pushButton_18_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(3);
}

void health::on_pushButton_20_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(4);
}

void health::on_pushButton_21_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}

void health::on_pushButton_22_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);


}



/*void health::on_statistiques_res_clicked()
{
Statistique *a=new Statistique();
    a->show();
}*/

void health::on_pushButton_pdf_4_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

         const int rowCount = ui->tableView->model()->rowCount();
         const int columnCount = ui->tableView->model()->columnCount();
        out <<  "<html>\n"
        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>liste d'Abonnement </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView->isColumnHidden(column)) {
                                 QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}

void health::on_pushButton_imprimer_4_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void health::on_pushButton_pdf_3_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

         const int rowCount = ui->tableView_3->model()->rowCount();
         const int columnCount = ui->tableView_3->model()->columnCount();
        out <<  "<html>\n"
        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>liste d'Abonnement </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_3->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_3->isColumnHidden(column)) {
                                 QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}


void health::on_pushButton_imprimer_3_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void health::on_pushButton_opensong_clicked()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this,"Selectionner de l'archive ",".mp3");
      reproductor->setMedia(QUrl::fromLocalFile(nombreArchivo));
}

void health::on_verticalSlidersong_actionTriggered(int position)
{
    reproductor->setVolume(position);

}


void health::showTime()
{
    ui->time->setText(QTime::currentTime().toString("hh:mm:ss"));

}

void health::on_pushButton_3_clicked()
{
 QMediaPlayer* player=new QMediaPlayer;
 QVideoWidget* vw=new QVideoWidget;
 player->setVideoOutput(vw);
 player->setMedia(QUrl::fromLocalFile("C:/Users/Synda/OneDrive/Bureau/video.mp4"));
 vw->setGeometry(500,500,300,400);
 vw->show();
 player->play();
}

void health::on_envoi_mail_clicked()
{
    QItemSelectionModel *select = ui->tableViewDonneur_2->selectionModel();

    QString email =select->selectedRows(3).value(0).data().toString();

    Smtp* smtp = new Smtp("beyaghalia.necib@esprit.tn","192SFT2560", "smtp.gmail.com", 465);

    smtp->sendMail("beyaghalia.necib@esprit.tn", email, "Reception du don","Bonjour, ceci est un mail automatique pour vous informer que nous avons reçu votre don, Nous vous remercions infiniment pour votre générosité pour aider les autres! Bien a vous.");
}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mailing.h"
#include "salaire.h"
#include <QApplication>
#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include <QInputDialog>
#include "QSqlRecord"
#include "QSqlQuery"
#include <QSqlDatabase>
#include <QSqlError>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include<QFile>
#include <QPrinter>
#include <QDate>
#include "employe.h"
#include "planning.h"
#include "smtp.h"
#include <QTimer>
#include <QDateTime>
#include <QListWidgetItem>
#include "QSqlRecord"

double firstNum;
bool userIsTypingSecondNum = false;






QString id_pl="";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makePolt();
    makePol_2();


     ui->le_id->setValidator(new QIntValidator(0, 99999, this));
     ui->tab_plainte_2->setModel(P.afficher());
     ui->le_idm->setValidator(new QIntValidator(0, 99999, this));
     ui->tab_amende_2->setModel(A.afficher());

     son=new QSound(":/img/img/ClickOn1.wav");
     qTimer=new QTimer(this);
     connect(qTimer,SIGNAL(timeout()),this,SLOT(clockTimer()));
     qTimer->start(100);


     //firas
     ui->le_id_2->setValidator(new QIntValidator(0, 99999, this));
     ui->tab_fourniseur_2->setModel(F.afficher());
     ui->le_idm_2->setValidator(new QIntValidator(0, 99999, this));
     ui->tab_materiel_2->setModel(M.afficher());
     makePolt1();

     connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
       connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
       //wa9et
       QTimer::singleShot(10 * 1000, this, SLOT(showInformation()));

       //Time
       QTimer *timer=new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
       timer->start();

       connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt1,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt2,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt3,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt4,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt5,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt6,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt7,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt8,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButt9,SIGNAL(released()),this,SLOT(digit_pressed()));
       connect(ui->pushButton_signal,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
       connect(ui->pushButton_porcentage,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
       connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
       connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
       connect(ui->pushButton_division,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
       connect(ui->pushButton_times,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

       ui->pushButton_plus->setCheckable(true);
       ui->pushButton_minus->setCheckable(true);
       ui->pushButton_division->setCheckable(true);
       ui->pushButton_times->setCheckable(true);

       //firas

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{   son->play();
    int i=0;
    int  id_pl=ui->le_id->text().toInt();
    QString nom_accuse=ui->le_nom->text();
    QString type=ui->le_type1->text();
    int  cin=ui->le_cin->text().toInt();
    QDate date_debut=ui->pb_dateEdit->date();

    QString cin1 = QString::number(cin);
    QString id_pl1 = QString::number(id_pl);


    bool test=true;

    if (!id_pl1.isEmpty()  && !nom_accuse.isEmpty()  && !type.isEmpty() && !cin1.isEmpty() ){


           if(test==true){
       Plainte P(id_pl,nom_accuse,type,cin,date_debut);
      test=P.ajouter(); }
      }
    else
    {
        test=false;
    }

    if(test){
        while (i<101) {
                   ui->progressBar100->setValue(i);
                   QTimer timer;
                   //        timer.setSingleShot(true);
                   timer.setInterval(10);
                   QEventLoop loop;
                   connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                   timer.start();
                   loop.exec();
                   i++;
               }
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("GESTION Plainte ","Plainte Ajoutée",QSystemTrayIcon::Information,15000);
          ui->tab_plainte_2->setModel(P.afficher());
          ui->progressBar100->setValue(0);

    }
    else{
        while (i<101) {
                   ui->progressBar100->setValue(i);
                   QTimer timer;
                   //        timer.setSingleShot(true);
                   timer.setInterval(10);
                   QEventLoop loop;
                   connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                   timer.start();
                   loop.exec();
                   i++;
               }
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("Erreur ","Plainte  Non Ajoutée",QSystemTrayIcon::Information,15000);
                        ui->progressBar100->setValue(0);

    }
}

void MainWindow::on_pb_supprimer_clicked()
{ son->play();
  int i=0;
Plainte P1;
P1.setid_pl(ui->le_id_supp->text().toInt());
bool test=P1.supprimer(P1.getid_pl());


if(test){ while (i<101) {
        ui->progressBar100->setValue(i);
        QTimer timer;
        //        timer.setSingleShot(true);
        timer.setInterval(10);
        QEventLoop loop;
        connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
        timer.start();
        loop.exec();
        i++;
    }
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("icone.png"));

                    notifyIcon->showMessage("GESTION Plainte ","Plainte Supprimée",QSystemTrayIcon::Information,15000);
    ui->tab_plainte_2->setModel(P.afficher());
    ui->progressBar100->setValue(0);

}
else{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("icone.png"));

                    notifyIcon->showMessage("Erreur ","Plainte Non Supprimée",QSystemTrayIcon::Information,15000);
}
}

void MainWindow::on_pb_ajouter2_clicked()
{   son->play();
    int i=0;
    int  id_am=ui->le_idm->text().toInt();
    QString status=ui->le_status->text();
    QString type=ui->le_type->text();
    int  prix_am=ui->le_prix->text().toInt();

 QString id_am1 = QString::number(id_am);
    QString prix_am1 = QString::number(prix_am);
    bool test=true;

    if (!id_am1.isEmpty()  && !status.isEmpty()  && !type.isEmpty() && !prix_am1.isEmpty() ){


           if(test==true){

         Amende A(id_am,status,type,prix_am);

       bool test=A.ajouter();
       }
      }
    else
    {
        test=false;
    }
    if(test){ while (i<101) {
            ui->progressBar101->setValue(i);
            QTimer timer;
            //        timer.setSingleShot(true);
            timer.setInterval(10);
            QEventLoop loop;
            connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
            timer.start();
            loop.exec();
            i++;}



          ui->tab_amende_2->setModel(A.afficher());
          ui->progressBar101->setValue(0);
          QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                          notifyIcon->show();
                          notifyIcon->setIcon(QIcon("icone.png"));

                          notifyIcon->showMessage("GESTION Amende ","Amende Ajouté",QSystemTrayIcon::Information,15000);
    }
    else{
        while (i<101) {
                   ui->progressBar101->setValue(i);
                   QTimer timer;
                   //        timer.setSingleShot(true);
                   timer.setInterval(10);
                   QEventLoop loop;
                   connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                   timer.start();
                   loop.exec();
                   i++;}


        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("Erreur ","Amende Non Ajouté",QSystemTrayIcon::Information,15000);
                        ui->progressBar101->setValue(0);

    }

}

void MainWindow::on_pb_supprimer_1_clicked()
{   son->play();
    int i=0;
    Amende A1;
    A1.setid_am(ui->le_idm_supp->text().toInt());
    bool test=A1.supprimer(A1.getid_am());
    if(test){ while (i<101) {
            ui->progressBar101->setValue(i);
            QTimer timer;
            //        timer.setSingleShot(true);
            timer.setInterval(10);
            QEventLoop loop;
            connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
            timer.start();
            loop.exec();
            i++;
        }
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("GESTION Amende ","Amende Supprimée",QSystemTrayIcon::Information,15000);
        ui->tab_amende_2->setModel(A.afficher());
        ui->progressBar101->setValue(0);

    }
    else{

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("Erreur ","Amende Non Supprimée",QSystemTrayIcon::Information,15000);
    }
}

void MainWindow::on_pb_modifier_clicked()
{   son->play();
    int row=ui->tab_plainte_2->selectionModel()->currentIndex().row();
    QString id_pl=ui->tab_plainte_2->model()->index(row,0).data().toString(); //row = ligne / 0 : colonne
    QString nom_accuse=ui->tab_plainte_2->model()->index(row,1).data().toString();
    QString type=ui->tab_plainte_2->model()->index(row,2).data().toString();

    QString cin=ui->tab_plainte_2->model()->index(row,3).data().toString();
    QDate date_debut=ui->tab_plainte_2->model()->index(row,4).data().toDate();


    if(row==-1)
    {
        QMessageBox ::information(nullptr,QObject::tr("modifier un plainte"),
                                          QObject::tr("aucune selection.\n"
                                              "click ok to exit"),QMessageBox::Ok);
    }
    else
    {
        ui->le_id->setText(id_pl);
        ui->le_nom->setText(nom_accuse);
        ui->le_type1->setText(type);
      ui->le_cin->setText(cin);
      ui->pb_dateEdit->setDate(date_debut);
    }
}

void MainWindow::on_pushButton_clicked()
{   son->play();
    int i=0;
    int id_pl = ui->le_id->text().toInt();
    QString nom_accuse = ui->le_nom->text();
    QString type= ui->le_type1->text();
    int cin= ui->le_cin->text().toInt();
    QDate date_debut=ui->pb_dateEdit->date();


    Plainte P(id_pl,nom_accuse,type,cin,date_debut);
    bool test =P.modifier(id_pl,nom_accuse,type,cin,date_debut);

    if(test)
    {
        while (i<101) {
                   ui->progressBar101->setValue(i);
                   QTimer timer;
                   //        timer.setSingleShot(true);
                   timer.setInterval(10);
                   QEventLoop loop;
                   connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                   timer.start();
                   loop.exec();
                   i++;
               }
        ui->tab_plainte_2->setModel(P.afficher());
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("GESTION Plainte ","Plainte Modifiée",QSystemTrayIcon::Information,15000);
                ui->progressBar101->setValue(0);


    }
    else
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("Erreur ","Plainte Non Modifiée",QSystemTrayIcon::Information,15000);

    }
}

void MainWindow::on_pushButton_2_clicked()
{   son->play();
    int row=ui->tab_amende_2->selectionModel()->currentIndex().row();
    QString id_am=ui->tab_amende_2->model()->index(row,0).data().toString(); //row = ligne / 0 : colonne
    QString status=ui->tab_amende_2->model()->index(row,1).data().toString();
    QString type=ui->tab_amende_2->model()->index(row,2).data().toString();

    QString prix_am=ui->tab_amende_2->model()->index(row,3).data().toString();

    if(row==-1)
    {
        QMessageBox ::information(nullptr,QObject::tr("modifier amende"),
                                          QObject::tr("aucune selection.\n"
                                              "click ok to exit"),QMessageBox::Ok);
    }
    else
    {
        ui->le_idm->setText(id_am);
        ui->le_type->setText(type);
        ui->le_status->setText(status);
      ui->le_prix->setText(prix_am);
    }
}

void MainWindow::on_pushButton_3_clicked()
{   son->play();
    int i=0;
    int id_am = ui->le_idm->text().toInt();
    QString status = ui->le_status->text();
    QString type= ui->le_type->text();
    int prix_am= ui->le_prix->text().toInt();

    Amende A(id_am,status,type,prix_am);
    bool test =A.modifier(id_am,status,type,prix_am);

    if(test)
    {   while (i<101) {
            ui->progressBar101->setValue(i);
            QTimer timer;
            //        timer.setSingleShot(true);
            timer.setInterval(10);
            QEventLoop loop;
            connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
            timer.start();
            loop.exec();
            i++;
        }
        ui->tab_amende_2->setModel(A.afficher());
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("GESTION Amende ","Amende Modifiée",QSystemTrayIcon::Information,15000);
        ui->progressBar101->setValue(0);


    }
    else
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("Erreur ","Amende Non Modifiée",QSystemTrayIcon::Information,15000);
}

}

void MainWindow::on_recherche_clicked()
{   son->play();
    QSqlQueryModel *modal=new QSqlQueryModel();
                    QSqlQuery request;
                   QString type=ui->rechercher->currentText();
                   QString val=ui->le_recherche->text();
                   val="%"+val+"%";
                   if (type=="id"){
                       request.prepare("SELECT * FROM PLAINTE WHERE id_pl LIKE :val ");
                   }else if (type=="nom"){
                       request.prepare("SELECT * FROM PLAINTE WHERE nom_accuse LIKE:val");
                   }else if (type=="cin"){
                       request.prepare("SELECT * FROM PLAINTE WHERE cin LIKE :val");
                   }else if (type=="type"){
                       request.prepare("SELECT * FROM PLAINTE WHERE type LIKE :val");
                   }
                   request.bindValue(":val",val);
                   request.exec();
                   modal->setQuery(request);
                   ui->tab_plainte_2->setModel(modal);

}




void MainWindow::on_trie_activated()
{   son->play();
    Plainte P;
    QString choix= ui->trie->currentText();
    ui->tab_plainte_2->setModel(P.Trier(choix));
}

void MainWindow::on_trie_2_activated()
{   son->play();
    Amende A;
    QString choix= ui->trie_2->currentText();
    ui->tab_amende_2->setModel(A.Trier(choix));
}

void MainWindow::on_recherche1_clicked()
{   son->play();
    QSqlQueryModel *modal=new QSqlQueryModel();
                    QSqlQuery request;
                   QString type=ui->rechercher_2->currentText();
                   QString val=ui->le_recherche1->text();
                   val="%"+val+"%";
                   if (type=="id_am"){
                       request.prepare("SELECT * FROM amendes WHERE id_am LIKE:val ");
                   }else if (type=="status"){
                       request.prepare("SELECT * FROM amendes WHERE status LIKE:val");
                   }else if (type=="type"){
                       request.prepare("SELECT * FROM amendes WHERE type LIKE:val");
                   }else if (type=="prix_am"){
                       request.prepare("SELECT * FROM amendes WHERE prix_am LIKE:val");
                   }
                   request.bindValue(":val",val);
                   request.exec();
                   modal->setQuery(request);
                   ui->tab_amende_2->setModel(modal);

}


void MainWindow::makePolt()
{
        QString CurrentYear = QDateTime::currentDateTime().addYears(0).toString("yyyy");

        ui->pa_tabWidget_2->setTabText(0, QDateTime::currentDateTime().toString("yyyy"));
       // ui->pa_tabWidget_2->setTabText(1, QDateTime::currentDateTime().addYears(-1).toString("yyyy"));
       // ui->pa_tabWidget_2->setTabText(2, QDateTime::currentDateTime().addYears(-2).toString("yyyy"));
       // ui->pa_tabWidget_2->setTabText(3, QDateTime::currentDateTime().addYears(-3).toString("yyyy"));
       // ui->pa_tabWidget_2->setTabText(4, QDateTime::currentDateTime().addYears(-4).toString("yyyy"));

        int index = ui->pa_tabWidget_2->currentIndex();
        QString currentTabText = ui->pa_tabWidget_2->tabText(index);


        QLinearGradient gradient(0, 0, 0, 400);
        gradient.setColorAt(0, QColor(0, 90, 90));
        gradient.setColorAt(0.38, QColor(0, 105, 105));
        gradient.setColorAt(1, QColor(0, 70, 70));
        ui->customPlot->setBackground(QBrush(gradient));


        QCPBars *regen = new QCPBars(ui->customPlot->xAxis,ui-> customPlot->yAxis);

        regen->setAntialiased(false);
        regen->setStackingGap(1);
        regen->setName("Nombre des Plaintes par mois");
        regen->setPen(QPen(QColor(0, 0, 0).lighter(130)));
        regen->setBrush(QColor(55,0, 200));

        QVector<double> ticks;
        QVector<QString> labels;

        if(currentTabText==CurrentYear){
        for(int i=1;i<QDate::currentDate().month()+2;i++){
        ticks << i;
        }
        }
        else{
        ticks << 1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12;
        }

        labels <<"janvier"<<"février"<<"mars"<<"avril"<<"mai"<<"juin"<<"juillet"<<"août"<<"septembre"<<"octobre "<<"novembre"<<"décembre ";
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(ticks, labels);
        ui->customPlot->xAxis->setTicker(textTicker);
        ui->customPlot->xAxis->setTickLabelRotation(60);
        ui->customPlot->xAxis->setSubTicks(false);
        ui->customPlot->xAxis->setTickLength(0, 3);
        ui->customPlot->xAxis->setRange(0, 13);
        ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
        ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
        ui->customPlot->xAxis->grid()->setVisible(true);
        ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        ui->customPlot->xAxis->setTickLabelColor(Qt::white);
        ui->customPlot->xAxis->setLabelColor(Qt::white);
        ui->customPlot->yAxis->setRange(0,20);
        ui->customPlot->yAxis->setPadding(50); // a bit more space to the left border
        ui->customPlot->yAxis->setLabel("Nombre des Plaintes");
        ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
        ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
        ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
        ui->customPlot->yAxis->grid()->setSubGridVisible(true);
        ui->customPlot->yAxis->setTickLabelColor(Qt::white);
        ui->customPlot->yAxis->setLabelColor(Qt::white);
        ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
        ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


        QVector<double> regenData;

        int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0,n11=0,n12=0;
        QSqlQuery q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12;
            q1.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=1 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q1.bindValue(":year", currentTabText);
            q1.exec();
            while (q1.next())
            {
                n1 = q1.value(0).toInt();
            }

            q2.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=2 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q2.bindValue(":year", currentTabText);
            q2.exec();
            while (q2.next())
            {
                n2 = q2.value(0).toInt();
            }

            q3.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=3 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q3.bindValue(":year", currentTabText);
            q3.exec();
            while (q3.next())
            {
                 n3 = q3.value(0).toInt();
            }
            q4.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=4 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q4.bindValue(":year", currentTabText);
            q4.exec();
            while (q4.next())
            {
                n4 = q4.value(0).toInt();
            }

            q5.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=5 AND EXTRACT(YEAR FROM date_debut)=:year");
            q5.bindValue(":year", currentTabText);
            q5.exec();
            while (q5.next())
            {
                n5 = q5.value(0).toInt();
            }

            q6.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=6 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q6.bindValue(":year", currentTabText);
            q6.exec();
            while (q6.next())
            {
                 n6 = q6.value(0).toInt();
            }
            q7.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=7 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q7.bindValue(":year", currentTabText);
            q7.exec();
            while (q7.next())
            {
                n7 = q7.value(0).toInt();
            }

            q8.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=8 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q8.bindValue(":year", currentTabText);
            q8.exec();
            while (q8.next())
            {
                n8 = q8.value(0).toInt();
            }

            q9.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=9 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q9.bindValue(":year", currentTabText);
            q9.exec();
            while (q9.next())
            {
                 n9 = q9.value(0).toInt();
            }
            q10.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=10 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q10.bindValue(":year", currentTabText);
            q10.exec();
            while (q10.next())
            {
                n10 = q10.value(0).toInt();
            }

            q11.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=11 AND EXTRACT(YEAR FROM date_debut)=:year ");
            q11.bindValue(":year", currentTabText);
            q11.exec();
            while (q11.next())
            {
                n11 = q11.value(0).toInt();
            }

            q12.prepare("select count(*) from plainte where EXTRACT(MONTH FROM date_debut)=12 AND EXTRACT(YEAR FROM date_debut)=:year");
            q12.bindValue(":year", currentTabText);
            q12.exec();
            while (q12.next())
            {
                 n12 = q12.value(0).toInt();
            }

        regenData <<n1<<n2<<n3<<n4<<n5<<n6<<n7<<n8<<n9<<n10<<n11<<n12;

        regen->setData(ticks, regenData);

        ui->customPlot->legend->setVisible(true);
        ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
        ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
        ui->customPlot->legend->setBorderPen(Qt::NoPen);
        QFont legendFont = font();
        legendFont.setPointSize(10);
        ui->customPlot->legend->setFont(legendFont);
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot->replot();

    }




void MainWindow::makePol_2()
{

       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot_2->setBackground(QBrush(gradient));


       QCPBars *regen = new QCPBars(ui->customPlot_2->xAxis,ui-> customPlot_2->yAxis);

       regen->setAntialiased(false);

       regen->setStackingGap(1);




       regen->setName("Nombre de amende par rapport a la type");
       regen->setPen(QPen(QColor(0, 0, 0).lighter(130)));
       regen->setBrush(QColor(55,0, 200));

       QVector<double> ticks;
       QVector<QString> labels;






       ticks << 1<<2<<3;

      labels <<"téléphone au volant "<<"non-port de la ceinture"<<"non-respect des distances de sécurité";
       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot_2->xAxis->setTicker(textTicker);
       ui->customPlot_2->xAxis->setTickLabelRotation(60);
       ui->customPlot_2->xAxis->setSubTicks(false);
       ui->customPlot_2->xAxis->setTickLength(0, 3);
       ui->customPlot_2->xAxis->setRange(0, 8);
       ui->customPlot_2->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_2->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_2->xAxis->grid()->setVisible(true);
       ui->customPlot_2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot_2->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot_2->xAxis->setLabelColor(Qt::white);


       ui->customPlot_2->yAxis->setRange(0,10);
       ui->customPlot_2->yAxis->setPadding(10); // a bit more space to the left border
       ui->customPlot_2->yAxis->setLabel("Nombre de plainte");
       ui->customPlot_2->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_2->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_2->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot_2->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot_2->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot_2->yAxis->setLabelColor(Qt::white);
       ui->customPlot_2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
       ui->customPlot_2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


       QVector<double> regenData;
       int n1=0,n2=0,n3=0;

           QSqlQuery q1("select count(*) from amendes where type='telephone'");
           while (q1.next())
           {
               n1 = q1.value(0).toInt();
               qDebug()<<"Nombre amendes : "<<n1<<endl;
           }

           QSqlQuery q2("select count(*) from amendes where type='ceinture'");
           while (q2.next())
           {
               n2 = q2.value(0).toInt();
               qDebug()<<"Nombre amendes : "<<n2<<endl;
           }

           QSqlQuery q3("select count(*) from amendes where type='distances'");
           while (q3.next())
           {
                n3 = q3.value(0).toInt();
                qDebug()<<"Nombre amendes : "<<n3<<endl;
           }




       regenData << n1<<n2<<n3;
       regen->setData(ticks, regenData);


       ui->customPlot_2->legend->setVisible(true);
       ui->customPlot_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot_2->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot_2->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot_2->legend->setFont(legendFont);
       ui->customPlot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}

void MainWindow::on_pushButton_pd1_pa_clicked()
{   son->play();
    QString strStream;
                          QTextStream out(&strStream);

                          const int rowCount = ui->tab_plainte_2->model()->rowCount();
                          const int columnCount = ui->tab_plainte_2->model()->columnCount();

                          out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("strTitle")
                              <<  "</head>\n"
                              "<body bgcolor=#ffffff link=#5000A0>\n"

                             //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des Plaintes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                          out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tab_plainte_2->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tab_plainte_2->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tab_plainte_2->isColumnHidden(column)) {
                                      QString data = ui->tab_plainte_2->model()->data(ui->tab_plainte_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_excel1_pa_clicked()
{son->play();
    QTableView *table;
                   table = ui->tab_plainte_2;
                   QString filters("CSV files (*.csv);;All files (*.*)");
                   QString defaultFilter("CSV files (*.csv)");
                   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                      filters, &defaultFilter);
                   QFile file(fileName);
                   QAbstractItemModel *model =  table->model();
                   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                       QTextStream data(&file);
                       QStringList strList;
                       for (int i = 0; i < model->columnCount(); i++) {
                           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") << "\n";
                       for (int i = 0; i < model->rowCount(); i++) {
                           strList.clear();
                           for (int j = 0; j < model->columnCount(); j++) {
                               if (model->data(model->index(i, j)).toString().length() > 0)
                                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") + "\n";
                       }
                       file.close();
                       //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");

                   }
}

void MainWindow::on_pb_calendarWidget_clicked(const QDate &date1)
{   son->play();
    QSqlQueryModel * modal= new QSqlQueryModel();
        QString sql;
                    QDate date= ui->pb_calendarWidget->selectedDate();
                    QSqlQuery request;
                                    request.prepare("select * from plainte where date_debut= :date");
                                    request.bindValue(":date",date);

                                    request.exec();
                                    modal->setQuery(request);
                                    ui->tab_plainte_2->setModel(modal);
}

void MainWindow::on_pushButton_pd1_pa_2_clicked()
{  son->play();
    QString strStream;
                          QTextStream out(&strStream);

                          const int rowCount = ui->tab_amende_2->model()->rowCount();
                          const int columnCount = ui->tab_amende_2->model()->columnCount();

                          out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("strTitle")
                              <<  "</head>\n"
                              "<body bgcolor=#ffffff link=#5000A0>\n"

                             //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des Amendes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                          out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tab_amende_2->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tab_amende_2->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tab_amende_2->isColumnHidden(column)) {
                                      QString data = ui->tab_amende_2->model()->data(ui->tab_amende_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_excel1_pa_2_clicked()
{   son->play();
    QTableView *table;
                   table = ui->tab_amende_2;
                   QString filters("CSV files (*.csv);;All files (*.*)");
                   QString defaultFilter("CSV files (*.csv)");
                   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                      filters, &defaultFilter);
                   QFile file(fileName);
                   QAbstractItemModel *model =  table->model();
                   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                       QTextStream data(&file);
                       QStringList strList;
                       for (int i = 0; i < model->columnCount(); i++) {
                           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") << "\n";
                       for (int i = 0; i < model->rowCount(); i++) {
                           strList.clear();
                           for (int j = 0; j < model->columnCount(); j++) {
                               if (model->data(model->index(i, j)).toString().length() > 0)
                                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") + "\n";
                       }
                       file.close();
                       //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");

                   }
}

void MainWindow::on_pa_pushButton_101_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pa_pushButton_102_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pa_pushButton_103_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pa_pushButton_104_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pa_pushButton_4_clicked()
{
    son->play();
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pa_pushButton_5_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pa_pushButton_105_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pa_pushButton_106_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::clockTimer()
{
    QTime clockTime=QTime::currentTime();
    ui->Clocklabel->setText(clockTime.toString(" hh : mm : ss"));
    QString date = QDate::currentDate().toString();

}

void MainWindow::on_menu_pushButton_48_clicked()
{   son->play();
    ui->stackedWidget->setCurrentIndex(0);

}



//firas
void MainWindow::on_pb_ajouter1_clicked()
{son->play();
    int  id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom->text();
    int  tel=ui->le_tel->text().toInt();

    Fournisseur E(id,nom,prenom,tel);

    bool test=E.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("ajout succesful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tab_fourniseur_2->setModel(F.afficher());
    }
    else{

        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_supprimer_2_clicked()
{son->play();
Fournisseur F1;
F1.setid(ui->le_id_supp_2->text().toInt());
bool test=F1.supprimer(F1.getid());
if(test){
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("supprimer succesful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_fourniseur_2->setModel(F.afficher());
}
else{

    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("supprimer failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pb_ajouter2_2_clicked()
{son->play();
    int  idm=ui->le_idm_2->text().toInt();
    QString nom=ui->le_nom1->text();
    QString type1=ui->le_type_2->text();
    int  prix1=ui->le_prix_2->text().toInt();

    Materiel M(idm,nom,type1,prix1);

    bool test=M.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("ajout succesful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tab_materiel_2->setModel(M.afficher());
    }
    else{

        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_supprimer_3_clicked()
{son->play();
    Materiel M1;
    M1.setidm(ui->le_idm_supp_2->text().toInt());
    bool test=M1.supprimer(M1.getidm());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("supprimer succesful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_materiel_2->setModel(M.afficher());
    }
    else{

        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("supprimer failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_modifier1_clicked()
{son->play();
    int row=ui->tab_fourniseur_2->selectionModel()->currentIndex().row();
    QString id=ui->tab_fourniseur_2->model()->index(row,0).data().toString(); //row = ligne / 0 : colonne
    QString nom=ui->tab_fourniseur_2->model()->index(row,1).data().toString();
    QString prenom=ui->tab_fourniseur_2->model()->index(row,2).data().toString();

    QString tel=ui->tab_fourniseur_2->model()->index(row,3).data().toString();

    if(row==-1)
    {
        QMessageBox ::information(nullptr,QObject::tr("modifier un fournisseur"),
                                          QObject::tr("aucune selection.\n"
                                              "click ok to exit"),QMessageBox::Ok);
    }
    else
    {
        ui->le_id_2->setText(id);
        ui->le_nom_2->setText(nom);
        ui->le_prenom->setText(prenom);
      ui->le_tel->setText(tel);
    }
}

void MainWindow::on_pb_recuperer_1_clicked()
{son->play();
    int id = ui->le_id_2->text().toInt();
    QString nom = ui->le_nom_2->text();
    QString prenom= ui->le_prenom->text();
    int tel= ui->le_tel->text().toInt();

    Fournisseur F(id,nom,prenom,tel);
    bool test =F.modifier(id,nom,prenom,tel);

    if(test)
    {ui->tab_fourniseur_2->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                                 QObject::tr("fournisseur  modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_recup_clicked()
{son->play();
    int row=ui->tab_materiel_2->selectionModel()->currentIndex().row();
    QString idm=ui->tab_materiel_2->model()->index(row,0).data().toString(); //row = ligne / 0 : colonne
    QString nom=ui->tab_materiel_2->model()->index(row,1).data().toString();
    QString type1=ui->tab_materiel_2->model()->index(row,2).data().toString();

    QString prix1=ui->tab_materiel_2->model()->index(row,3).data().toString();

    if(row==-1)
    {
        QMessageBox ::information(nullptr,QObject::tr("modifier materiel"),
                                          QObject::tr("aucune selection.\n"
                                              "click ok to exit"),QMessageBox::Ok);
    }
    else
    {
        ui->le_idm_2->setText(idm);
        ui->le_nom1->setText(nom);
        ui->le_type_2->setText(type1);
      ui->le_prix_2->setText(prix1);
    }
}

void MainWindow::on_pushButton_7_recup_clicked()
{son->play();
    int idm = ui->le_idm_2->text().toInt();
    QString nom = ui->le_nom1->text();
    QString type1= ui->le_type_2->text();
    int prix1= ui->le_prix_2->text().toInt();

    Materiel M(idm,nom,type1,prix1);
    bool test =M.modifier(idm,nom,type1,prix1);

    if(test)
    {ui->tab_materiel_2->setModel(M.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier materiel"),
                                 QObject::tr("materiel  modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier materiel"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_recherche_2_clicked()
{son->play();
    QSqlQueryModel *modal=new QSqlQueryModel();
                    QSqlQuery request;
                   QString type=ui->rechercher_3->currentText();
                   QString val=ui->le_recherche_2->text();
                   val="%"+val+"%";
                   if (type=="id"){
                       request.prepare("SELECT * FROM fourniseur WHERE id LIKE:val ");
                   }else if (type=="nom"){
                       request.prepare("SELECT * FROM fourniseur WHERE nom LIKE:val");
                   }else if (type=="prenom"){
                       request.prepare("SELECT * FROM fourniseur WHERE prenom LIKE:val");
                   }else if (type=="tel"){
                       request.prepare("SELECT * FROM fourniseur WHERE tel LIKE:val");
                   }
                   request.bindValue(":val",val);
                   request.exec();
                   modal->setQuery(request);
                   ui->tab_fourniseur_2->setModel(modal);

}




void MainWindow::on_trie_3_activated()
{son->play();
    Fournisseur F;
    QString choix= ui->trie_3->currentText();
    ui->tab_fourniseur_2->setModel(F.Trier(choix));
}

void MainWindow::on_trie_4_activated()
{son->play();
    Materiel M;
    QString choix= ui->trie_4->currentText();
    ui->tab_materiel_2->setModel(M.Trier(choix));
}

void MainWindow::on_recherche1_2_clicked()
{son->play();
    QSqlQueryModel *modal=new QSqlQueryModel();
                    QSqlQuery request;
                   QString type=ui->rechercher_4->currentText();
                   QString val=ui->le_recherche1_2->text();
                   val="%"+val+"%";
                   if (type=="idm"){
                       request.prepare("SELECT * FROM materiel WHERE idm LIKE:val ");
                   }else if (type=="nom"){
                       request.prepare("SELECT * FROM materiel WHERE nom LIKE:val");
                   }else if (type=="type1"){
                       request.prepare("SELECT * FROM materiel WHERE type LIKE:val");
                   }else if (type=="prix1"){
                       request.prepare("SELECT * FROM materiel WHERE prix LIKE:val");
                   }
                   request.bindValue(":val",val);
                   request.exec();
                   modal->setQuery(request);
                   ui->tab_materiel_2->setModel(modal);

}
void MainWindow::sendMail()
{son->play();
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{son->play();
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

//Statistique
void MainWindow::makePolt1()
{

       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot_6->setBackground(QBrush(gradient));


       QCPBars *regen = new QCPBars(ui->customPlot_6->xAxis,ui-> customPlot_6->yAxis);

       regen->setAntialiased(false);

       regen->setStackingGap(1);




       regen->setName("Nombre de materiel  par rapport a la type");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));

       QVector<double> ticks;
       QVector<QString> labels;






       ticks << 1<<2<<3;

      labels <<"electronique"<<"chaise-table"<<"Autres";
       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot_6->xAxis->setTicker(textTicker);
       ui->customPlot_6->xAxis->setTickLabelRotation(60);
       ui->customPlot_6->xAxis->setSubTicks(false);
       ui->customPlot_6->xAxis->setTickLength(0, 3);
       ui->customPlot_6->xAxis->setRange(0, 8);
       ui->customPlot_6->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_6->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_6->xAxis->grid()->setVisible(true);
       ui->customPlot_6->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot_6->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot_6->xAxis->setLabelColor(Qt::white);


       ui->customPlot_6->yAxis->setRange(0,10);
       ui->customPlot_6->yAxis->setPadding(10); // a bit more space to the left border
       ui->customPlot_6->yAxis->setLabel("Nombre de materiels");
       ui->customPlot_6->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_6->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_6->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot_6->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot_6->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot_6->yAxis->setLabelColor(Qt::white);
       ui->customPlot_6->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
       ui->customPlot_6->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


       QVector<double> regenData;
       int n1=0;
       int n2=0;
               int n3=0;

           QSqlQuery q1("select count(*) from materiel where type='electronique'");
           while (q1.next())
           {
               n1 = q1.value(0).toInt();
               qDebug()<<"Nombre materiels : "<<n1<<endl;
           }

           QSqlQuery q2("select count(*) from materiel where type='chaisetable'");
           while (q2.next())
           {
               n2 = q2.value(0).toInt();
               qDebug()<<"Nombre materiels : "<<n2<<endl;
           }

           QSqlQuery q3("select count(*) from materiel where type='Autres'");
           while (q3.next())
           {
                n3 = q3.value(0).toInt();
                qDebug()<<"Nombre materiels : "<<n3<<endl;
           }




       regenData << n1<<n2<<n3;
       regen->setData(ticks, regenData);


       ui->customPlot_6->legend->setVisible(true);
       ui->customPlot_6->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot_6->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot_6->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot_6->legend->setFont(legendFont);
       ui->customPlot_6->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->time->setText(time_text);



    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString("d / M / yyyy");
    ui->date->setText(datetimetext);


}

void MainWindow::on_pushButton_4_fm_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_5_fm_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_pushButton_4_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_m_pushButton_retour_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_pushButton_mailing_f_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(8);

}

void MainWindow::on_m_pushButton_statistique_clicked()
{son->play();
     ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_f_pushButton_retour_mailing_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_m_pushButton_retour_stat_4_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_menu_pushButton_49_clicked()
{son->play();
    ui->stackedWidget->setCurrentIndex(5);

}







void MainWindow::on_pb_imprimer_clicked()
{son->play();
    QPrinter printer;

              printer.setPrinterName("desiered printer name");

            QPrintDialog dialog(&printer,this);

              if(dialog.exec()== QDialog::Rejected)

                  return;
}

void MainWindow::on_pb_pdf_clicked()
{son->play();
    QString strStream;
          QTextStream out(&strStream);

                     const int rowCount = ui->tab_fourniseur_2->model()->rowCount();
                     const int columnCount = ui->tab_fourniseur_2->model()->columnCount();

                     out <<  "<html>\n"
                           "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                          //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des Fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                             out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                               if (!ui->tab_fourniseur_2->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tab_fourniseur_2->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                             for (int row = 0; row < rowCount; row++) {
                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                 for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tab_fourniseur_2->isColumnHidden(column)) {
                                QString data = ui->tab_fourniseur_2->model()->data(ui->tab_fourniseur_2->model()->index(row, column)).toString().simplified();
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


void MainWindow::on_pb_pdf_2_clicked()
{son->play();
    QString strStream;
          QTextStream out(&strStream);

                     const int rowCount = ui->tab_materiel_2->model()->rowCount();
                     const int columnCount = ui->tab_materiel_2->model()->columnCount();

                     out <<  "<html>\n"
                           "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                          //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des Materiels </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                             out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                               if (!ui->tab_materiel_2->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tab_materiel_2->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                             for (int row = 0; row < rowCount; row++) {
                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                 for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tab_materiel_2->isColumnHidden(column)) {
                                QString data = ui->tab_materiel_2->model()->data(ui->tab_materiel_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pb_imprimer_2_clicked()
{son->play();
    QPrinter printer;

              printer.setPrinterName("desiered printer name");

            QPrintDialog dialog(&printer,this);

              if(dialog.exec()== QDialog::Rejected)

                  return;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;

    double labelNumber;

    if((ui->pushButton_plus->isChecked()||ui->pushButton_minus->isChecked()||ui->pushButton_division->isChecked()||ui->pushButton_times->isChecked()) && (!userIsTypingSecondNum))
    {
        labelNumber = (button->text()).toDouble();
        userIsTypingSecondNum = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    //new label number
    else
    {
        if(ui->label_27->text().contains(".") && button->text() == "0")
        {
            newLabel = ui->label_27->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label_27->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }

    //label of the ui
    ui->label_27->setText(newLabel);
}

void MainWindow::on_pushButton_point_released()
{
    ui->label_27->setText(ui->label_27->text()+("."));
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton *)sender();
    double labelNumber;
    QString newLabel;
    if(button->text() == "+/-")
    {
        labelNumber = ui->label_27->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_27->setText(newLabel);
    }
    if(button->text() == "%")
    {
        labelNumber = ui->label_27->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_27->setText(newLabel);
    }
}

void MainWindow::on_pushButton_C_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_times->setChecked(false);

    userIsTypingSecondNum = false;

    ui->label_27->setText("0");
}

void MainWindow::on_pushButton_equal_released()
{
    double labelNumber,secondNum;
    QString newLabel;

    secondNum = ui->label_27->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_27->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_27->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_27->setText(newLabel);
        ui->pushButton_division->setChecked(false);
    }
    else if(ui->pushButton_times->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_27->setText(newLabel);
        ui->pushButton_times->setChecked(false);
    }

    userIsTypingSecondNum = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton *)sender();

    firstNum = ui->label_27->text().toDouble();
    button->setChecked(true);
}


//firas

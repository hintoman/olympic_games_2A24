#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include "smtp.h"
#include "mailing.h"
#include "employes.h"
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include<QFile>
#include <QFileDialog>
#include<QTextDocument>
#include "evenement.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "qcustomplot.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendmail, SIGNAL(clicked()),this, SLOT(sendMail()));

    ui->tablemp->setModel(emp.afficher());
    timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
        timer->start(1000);

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id_emp=ui->id_emp->text().toInt();
    QString nom=ui->nom->text();
    int salaire=ui->salaire->text().toInt();
    QString date_entre=ui->dateEdit->text();
    employer r(id_emp,nom,salaire,date_entre);
    r.ajouter();
    ui->tablemp->setModel(emp.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    int id_emp=ui->id_emp->text().toInt();
    QString nom=ui->nom->text();
    int salaire=ui->salaire->text().toInt();
    QString date_entre=ui->dateEdit->text();
    employer r(id_emp,nom,salaire,date_entre);
    r.modifier(id_emp);


    if(salaire>0)
   { bool test=r.modifier(id_emp);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("employer modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->tablemp->setModel(emp.afficher());

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("employer non modifié"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }}
    else{
        QMessageBox::critical(nullptr, QObject::tr("verifiez le prix"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int id_emp=ui->id_empSupp->text().toInt();
    emp.supprimer(id_emp);
    ui->tablemp->setModel(emp.afficher());
}


void MainWindow::on_trier_activated()
{
    employer A;
    QString choix= ui->trier->currentText();
    ui->tablemp->setModel(A.Trier(choix));
}


void MainWindow::on_recherche_button_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
                    QSqlQuery request;
                   QString type=ui->recherche_type->currentText();
                   QString val=ui->text_recherche->text();
                   val="%"+val+"%";
                   if (type=="id_emp"){
                       request.prepare("SELECT * FROM gs_employer WHERE id_emp LIKE:val ");
                   }else if (type=="nom"){
                       request.prepare("SELECT * FROM gs_employer WHERE nom LIKE:val");
                   }else if (type=="date_entre"){
                       request.prepare("SELECT * FROM gs_employer WHERE date_entre LIKE:val");

                   }
                   request.bindValue(":val",val);
                   request.exec();
                   modal->setQuery(request);
                   ui->tablemp_1->setModel(modal);

}



void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;
          QTextStream out(&strStream);

                     const int rowCount = ui->tablemp->model()->rowCount();
                     const int columnCount = ui->tablemp->model()->columnCount();

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
                               if (!ui->tablemp->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tablemp->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                             for (int row = 0; row < rowCount; row++) {
                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                 for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tablemp->isColumnHidden(column)) {
                                QString data = ui->tablemp->model()->data(ui->tablemp->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                         }
                                     }
                                     out << "</tr>\n";
                                  }
                                 out <<  "</table> </center>\n"
                                      "</body>\n"
                                    "</html>\n";

                            QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), ".pdf");
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




void MainWindow::on_login_2_clicked()
{MainWindow w;

    res1=false;
    res2=false;
    user=ui->username->text();
   pass = ui->password->text();

       QString c_pass = "yassine";
       int a = c_pass.compare(pass);
       if(a == 0)
       res1 = true ;

       QString c_user = "yassine";
       int b = c_user.compare(user);
       if( b == 0 )
       res2 = true ;
       if(res2 == true && res1 == true)
       {QMessageBox::information(nullptr, QObject::tr("compte is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
w.show();
             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("compte is not open"),
                                 QObject::tr("connection failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_sendmail_clicked()
{
    Smtp* smtp = new Smtp("yassine.hamrouni@esprit.tn",ui->passwrd->text(), "smtp.gmail.com");


        smtp->sendMail("yassine.hamrouni@esprit.tn",ui->recep->text() , ui->object->text(),ui->msg->toPlainText());
}
void MainWindow::myfunction()
{

    QTime time =QTime::currentTime();

    QString time_text = time.toString("hh:mm:ss");

    ui->time_label->setText(time_text);//hedha fel page d'acceuil

    ui->time_label_2->setText(time_text); //hedha fel page 2 lezem fi kol page ta3mel label

    ui->time_label_3->setText(time_text);

    ui->time_label_4->setText(time_text);
    ui->time_label_5->setText(time_text);
    ui->time_label_6->setText(time_text);


}


//fatma//




void MainWindow::on_pushButton_ajouter_E_clicked()
{
    evenement e;
        int code = ui->lineEdit_code->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString dates= ui->lineEdit_date->text();
        QString type= ui->lineEdit_type->text();
        QString ville= ui->lineEdit_ville->text();
        int prix= ui->lineEdit_prix->text().toInt();

      evenement E (code,nom,dates,type,ville,prix);
      bool test=E.ajouter();

      if(test)
    {
          ui->tableView->setModel(tmp.afficher());//refresh
          QMessageBox msgBox ;
   QMessageBox::information(this,"information","evenement ajouté");
               ui->lineEdit_code->setText("");
               ui->lineEdit_nom->setText("");
               ui->lineEdit_date->setText("");
               ui->lineEdit_type->setText("");
               ui->lineEdit_ville->setText("");
               ui->lineEdit_prix->setText("");
  }

  else

  {
  QMessageBox msgBox ;
    msgBox.setText("evenement non ajouté ");

  }
}


void MainWindow::on_pushButton_supprimer_E_clicked()
{
    int code = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=tmp.supprimer(code);
    if(test)
    {
        ui->tableView->setModel(tmp.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","evenement supprimé");
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("evenement non Supprimer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_code->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->lineEdit_nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->lineEdit_date->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->lineEdit_type->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
    ui->lineEdit_ville->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->lineEdit_prix->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString());

}


void MainWindow::on_pushButton_modifier_E_clicked()
{
    int code = ui->lineEdit_code->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString dates= ui->lineEdit_date->text();
    QString type= ui->lineEdit_type->text();
    QString ville= ui->lineEdit_ville->text();
    int prix= ui->lineEdit_prix->text().toInt();

          bool test=tmp.modifier(code,nom,dates,type,ville,prix);
             if (test)
             {
                  ui->tableView->setModel(tmp.afficher());
                  QMessageBox msgBox ;
           QMessageBox::information(this,"information","evenement bien Modifié");
           ui->lineEdit_code->setText("");
           ui->lineEdit_nom->setText("");
           ui->lineEdit_date->setText("");
           ui->lineEdit_type->setText("");
           ui->lineEdit_ville->setText("");
           ui->lineEdit_prix->setText("");

                }
}


void MainWindow::on_pushButton_rafraichir_E_clicked()
{
    ui->lineEdit_code->setText("");
    ui->lineEdit_nom->setText("");
    ui->lineEdit_date->setText("");
    ui->lineEdit_type->setText("");
    ui->lineEdit_ville->setText("");
    ui->lineEdit_prix->setText("");
}


void MainWindow::on_pushButton_quitter_clicked()
{
    close();
}


void MainWindow::on_pushButton_rafraichir_clicked()
{
    ui->tableView->setModel(tmp.afficher());
    ui->lineEdit_chercher_type->setText("");
    ui->lineEdit_chercher_ville->setText("");
}


void MainWindow::on_pushButton_2_quitter_clicked()
{
    close();
}


void MainWindow::on_pushButton_tri_codee_clicked()
{
    ui->tableView->setModel(tmp.trier_code());
}


void MainWindow::on_pushButton_tri_nom_clicked()
{
    ui->tableView->setModel(tmp.trier_nom());
}


void MainWindow::on_pushButton_tri_prix_clicked()
{
    ui->tableView->setModel(tmp.trier_prix());
}


void MainWindow::on_pushButton_chercher_type_clicked()
{
    QString valeur=ui->lineEdit_chercher_type->text();
        evenement *c=new evenement();
        ui->tableView->setModel(c->chercher_type(valeur));
}


void MainWindow::on_pushButton_chercher_ville_clicked()
{
    QString valeur=ui->lineEdit_chercher_ville->text();
        evenement *c=new evenement();
        ui->tableView->setModel(c->chercher_ville(valeur));

}


void MainWindow::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/Administrateur/Documents/evenements/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des Evenement ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"Code Evenement");
        painter.drawText(1700,3300,"Nom Evenement");
        painter.drawText(3200,3300,"Date Evenement");
        painter.drawText(4700,3300,"Type Evenement");
        painter.drawText(6300,3300,"Ville Evenement");
        painter.drawText(7800,3300,"Prix Evenement");


        QSqlQuery query;
        query.prepare("select * from evenement");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4700,i,query.value(3).toString());
            painter.drawText(6300,i,query.value(4).toString());
            painter.drawText(7800,i,query.value(5).toString());

           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Administrateur/Documents/evenements/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}

QVector<double> MainWindow::Statistique()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT prix FROM evenement WHERE prix<=10");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT prix FROM evenement WHERE 10<prix and prix<=20");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT prix FROM evenement WHERE 20<prix and prix<=30");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT prix FROM evenement WHERE 30<prix and prix<=40");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT prix FROM evenement WHERE 40<prix ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void MainWindow::makePlot()
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
    bars1->setData(x3, MainWindow::Statistique());
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
    Ticks<<1<<2<<3<<4<<5<<6<<7;
    QVector<QString> labels;
    labels<<"0-10"<<"10-20"<<"20-30"<<"30-40"<<"40+"<<"Dinar";
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

void MainWindow::on_pushButton_statistique_clicked()
{
    MainWindow::makePlot();
}


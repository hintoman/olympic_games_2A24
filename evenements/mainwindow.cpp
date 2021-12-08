#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    ui->tableView->setModel(tmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


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
    QPdfWriter pdf("C:/Users/Asus/Desktop/fatma/evenements/Pdf.pdf");
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
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Asus/Desktop/fatma/evenements/Pdf.pdf"));
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


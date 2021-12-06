#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transaction.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QDateTimeEdit>
#include <QTableView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
#include <QtCharts>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());

    int ret=A.connect_arduino();
             switch(ret){
             case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
                 break;
             case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
                 break;
             case(-1):qDebug()<< "arduino is not availble";
             }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_valider_clicked()
{
    int id = ui->l_id->text().toInt();
    int montant = ui -> l_montant->text().toInt();
    QString type = ui ->l_type->text();
    QDateTime datet = ui -> dateTimeEdit->dateTime();
    Transaction transaction(id,type,montant,datet);

    bool test = transaction.ajouter();

    if(test){
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("add successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Cancel"),
                    QObject::tr("add failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }



}

void MainWindow::update_label()  { //label arduino

    data=A.read_from_arduino();
    QString DataAsString = QString(data);
    code=code+DataAsString;

    int ret;
    qDebug()<< code;
    ui->label_arduino->setText(code);
    if(code.length()==4){
        if(code.compare("1234")==0){
            A.write_to_arduino("1");


        }
       else {
            A.write_to_arduino("0");
        }
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_4->text().toInt();
    bool test = Etmp.supprimer(id);

    if(test){
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("delete successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("delete failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }


}


void MainWindow::on_pushButton_4_clicked()
{
}




void MainWindow::on_stat_clicked()
{



}

void MainWindow::on_trie_clicked()
{
    bool test = Etmp.tri();
    if(test){
        ui->tableViewT->setModel(Etmp.tri());


    }

}

void MainWindow::on_prd_clicked()
{
    bool test = Etmp.trd();
    if(test){
        ui->tableViewT->setModel(Etmp.trd());


    }else{


    }
}

void MainWindow::on_prm_clicked()
{
    bool test = Etmp.trm();
    if(test){
        ui->tableViewT->setModel(Etmp.trm());


    }
}

void MainWindow::on_calcul_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select datet SUM(montant) as recette FROM * transaction GROUP BY datet");

    ;


}

void MainWindow::on_OK_clicked()
{
    bool test = Etmp.calculT();
    QDateTime datet = ui->date_edit->dateTime();

}

void MainWindow::on_pushButton_clicked()
{


    ui->tableView_2->setModel(Etmp.chercher_id());


}



void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView_2->setModel(Etmp.revenue());

}



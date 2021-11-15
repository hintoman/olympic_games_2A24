#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transaction.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QDateTimeEdit>
#include <QTableView>








MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());

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







void MainWindow::on_stat_clicked()
{


}

void MainWindow::on_trie_clicked()
{
    bool test = Etmp.tri();
    if(test){
        ui->tableView->setModel(Etmp.afficher());


    }

}

void MainWindow::on_prd_clicked()
{
    bool test = Etmp.trd();
    if(test){
        ui->tableView->setModel(Etmp.afficher());


    }else{


    }
}

void MainWindow::on_prm_clicked()
{
    bool test = Etmp.trm();
    if(test){
        ui->tableView->setModel(Etmp.afficher());


    }
}

void MainWindow::on_calcul_clicked()
{
     bool test = Etmp.calculF();
     QDateTime datet = ui->date_edit->dateTime();
     if(test){
         ui->tableView->setModel(Etmp.afficher());


     }

}

void MainWindow::on_OK_clicked()
{
    bool test = Etmp.calculT();
    QDateTime datet = ui->date_edit->dateTime();
    if(test){
        ui->tableView->setModel(Etmp.afficher());


    }
}

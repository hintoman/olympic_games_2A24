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
    int id = ui->lineEdit->text().toInt();
    QString type = ui -> lineEdit->text();
    QString mont = ui -> lineEdit->text();
    QDateTime dat;
    Transaction transaction (id,type,mont,dat);

    bool test = transaction.ajouter();

    if(test){
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("add successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("add failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_3->text().toInt();
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



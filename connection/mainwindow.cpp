#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "employés.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_tab.h"
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
#include <QTimer>
#include <QDateTime>
#include <QListWidgetItem>
#include "QSqlRecord"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(digit_pressed()));



ui->tab_emp->setModel(P.afficher());
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int id_emp=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString adresse_email=ui->lineEdit_3->text();
    employés E(id_emp,nom,adresse_email);
   bool test=E.ajouter();
   if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("ajout effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                   QObject::tr("ajout non effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    bool test=etmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString adresse_mail= ui->lineEdit_3->text();
    QString nom= ui->lineEdit_2->text();
    int salaire = ui->lineEdit5->text().toInt();
  employés a(id,adresse_mail,nom);
  bool test=a.modifier(id);
  if(test)
{

      ui->tab_emp->setModel(tmpagence.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier une agence"),
                  QObject::tr("Agence modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier une agence"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}








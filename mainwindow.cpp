//if connex works by boutton ->close fenetre mainwindow and open fenetre gestion amira /we have variable type ga we give it constructeur par defaut
//and then chop//
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     c.createconnect();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ouverture connection base de donnees

      //if( c.createconnect()){
       close();
       gestion_amira *ga;
       ga = new gestion_amira();
       ga->show();
      // }

}

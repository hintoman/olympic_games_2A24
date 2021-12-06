//if connex works by boutton ->close fenetre mainwindow and open fenetre gestion amira /we have variable type ga we give it constructeur par defaut
//and then chop//
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/LENOVO/Desktop/amira/amira/back_amira.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

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

void MainWindow::on_pushButton_2_clicked()
{
    close();
    gestion_mahdi *ga;
    ga = new gestion_mahdi();
    ga->show();
}

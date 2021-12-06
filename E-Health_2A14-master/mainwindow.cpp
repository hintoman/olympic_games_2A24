#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "health.h"
#include "connection.h"
#include<QThread>
#include "arduinoo.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player= new QMediaPlayer(this);
    animation= new QPropertyAnimation(ui->label_6, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->label_6->geometry());
    animation->setEndValue(QRect(450,50,200,200));
    animation->start();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    Connection c;

   QSqlQuery query(test_bd);
    QString select = "SELECT UserName from LOGINS where UserName=? and Password=?";
    qDebug() << select;
    query.prepare(select);
    query.addBindValue(ui->lineEdit_user->text());
    query.addBindValue(ui->lineEdit_pass->text());
    query.exec();
     health h;

   if (query.exec())
    {

        int count=0;
        while (query.next())
        {
            count++;
        }
        if (count==1)
        {
            ui->label_4->setText(" username and password are correct ");



            this->hide();
            player->setMedia(QUrl::fromLocalFile("C:\\Users\\iTech\\Desktop\\QT validation finale\\G_Ressource_Humaine\\click-sound.mp3"));
            player->play();
            qDebug()<< player->errorString();
           health h;

            h.exec();
        }

         else if (count<1)
        {
            ui->label_4->setText(" username and password are incorrect ");
            player->setMedia(QUrl::fromLocalFile("C:\\Users\\iTech\\Desktop\\QT validation finale\\G_Ressource_Humaine\\error-404-sound-effects.mp3"));
             player->play();
             qDebug()<< player->errorString();
               c.fermerconnection();

        }
    }

  }


void MainWindow::on_pushButton_2_clicked()
{

    player->setMedia(QUrl::fromLocalFile("C:\\Users\\iTech\\Desktop\\QT validation finale\\G_Ressource_Humaine\\Quitter_Sound.mp3"));
    player->play();
    qDebug()<< player->errorString();
    sleep(2);
    close();

}

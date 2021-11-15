#ifndef ATHLETE_H
#define ATHLETE_H

#include<QString>
#include<QRegularExpression>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include<QtGui>
#include<QDialog>
#include <iostream>
#include<QtCore>
#include <QList>
#include<QTableView>
#include"qr.h"

class Athlete
{
public:
    Athlete();
    Athlete(int  ,int ,QString, QString , QString ,QString,QString  );
     int getid();
     void setid(int);
     QString getage();
     void setage(QString);
     int getnum_tel();
     void setnum_tel(int);
     QString getnom();
     void setnom(QString);
     QString getprenom();
     void setprenom(QString);
     QString getfliere();
     void setfliere(QString);
     QString getEmail();
     void setEmail(QString);
     bool Ajouter();
     QSqlQueryModel* affichier();
     bool supprimer(int);
     bool Email_validation(QString);
     bool modifier();
     QString printPDF();


     QSqlQueryModel* chercher(QString);
   //  QSqlTableModel modifier();
     QSqlQueryModel * triid();
     QSqlQueryModel * trinom();
     QSqlQueryModel * tridate();




       static QList<Athlete *> FindAll();
       static Athlete* getAthleteById(int id);
       static Athlete *currentSelectedAthlete;

     static void dispatchList(QTableView * view);
     static void updateListBySearchingMerchantName(QString namePattern,QTableView * view);
     static Athlete* setCurrentSelectedAthlete(Athlete * m);









     public:
    int id ,num_tel;

    QString nom,prenom,fliere,Email,age;




};


#endif // ATHLETE_H

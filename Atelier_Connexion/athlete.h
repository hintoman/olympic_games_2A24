#ifndef ATHLETE_H
#define ATHLETE_H

#include<QString>
#include<QRegularExpression>
#include<QSqlQueryModel>
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




private:
    int id ,num_tel;

    QString nom,prenom,fliere,Email,age;




};

#endif // ATHLETE_H

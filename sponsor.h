#ifndef SPONSOR_H
#define SPONSOR_H
#include<QString>

class sponsor
{
public:
    sponsor();
    void setid(QString n);
    void setnom(QString n);
   void setprenom(QString n);
   void set_adresse_mail(QString n);
        void set_genre(QString n);
        void set_mot_de_passe(int n);
        void setdate_de_naissance(QString n);
        QString get_id();
        QString get_nom();
        QString get_prenom();
         QString get_adresse_mail();
        QString get_genre();
        int get_mot_de_passe();
        QString get_date_de_naissance();
private:
     QString id, nom ,prenom,genre,adresse_mail,date_de_naissance;
     int mot_de_passe;

};

#endif // SPONSOR_H

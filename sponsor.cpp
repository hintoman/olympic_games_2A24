#include "sponsor.h"

sponsor::sponsor()
{

    id="";
    nom="";
    prenom="";
    mot_de_passe=0;
    adresse_mail="";
    date_de_naissance="";
    genre="";


}
void sponsor::setid(QString n)
{
    id = n;
}
void sponsor::setnom(QString n)
{
    nom = n;
}
void  sponsor::setprenom(QString n)
{
    prenom = n;
}
void sponsor::set_adresse_mail(QString n)
{
    adresse_mail = n;
}
void  sponsor::setdate_de_naissance(QString n)
{
    date_de_naissance = n;
}
void  sponsor::set_genre(QString n)
{
    genre = n;
}

QString sponsor::get_id()
{return id;}

QString  sponsor::get_nom()
{return nom;}

QString  sponsor::get_prenom()
{return prenom;}

QString  sponsor::get_genre()
{return genre;}

QString   sponsor::get_adresse_mail()
{return adresse_mail;}

QString  sponsor::get_date_de_naissance()
{return date_de_naissance;}
    int  sponsor:: get_mot_de_passe()
    {return mot_de_passe;}

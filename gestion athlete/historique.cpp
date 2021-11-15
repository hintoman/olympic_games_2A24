#include "historique.h"
#include<QSqlQuery>
#include"athlete.h"
#include <QPieSeries>

historique::historique()
{
     nbrpg=0;
     nbrpp=0;
     nbrmd=0;
     nbra=0;
     nbrb=0;
       }

       historique::historique(int nbrpg,int nbrpp,int nbrmd,int nbra,int nbrb)
       {this->nbrpg=nbrpg;this->nbrpp=nbrpp;this->nbrmd=nbrmd;this->nbra=nbra;this->nbrb=nbrb;}
       int historique::getnbrpg(){return nbrpg;}
       void historique::setnbrpg(int nbrpg){this->nbrpg=nbrpg;}
       int historique::getnbrpp(){return nbrpp;}
       void historique::setnbrpp(int nbrpp){this->nbrpp=nbrpp;}
       int historique::getnbrmd(){return nbrmd;}
       void historique::setnbrmd(int nbrmd){this->nbrmd=nbrmd;}
       int historique::getnbra(){return nbra;}
       void historique::setnbra(int nbra){this->nbra=nbra;}
       int historique::getnbrb(){return nbrb;}
       void historique::setnbrb(int nbrb){this->nbrb=nbrb;}
bool historique::ajouterhis()
{

    QSqlQuery query;


          query.prepare("INSERT INTO HISTO (nbrpg,nbrpp,nbrmd,nbra,nbrb ) "
                        "VALUES (:0,:1, :2 ,:3,:4)");
          query.bindValue(":0", nbrpg);
          query.bindValue(":1",  nbrpp);
          query.bindValue(":2", nbrmd);
          query.bindValue(":3",  nbra);
          query.bindValue(":4", nbrb);


          return query.exec();




}

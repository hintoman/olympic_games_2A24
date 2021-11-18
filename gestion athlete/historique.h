#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include<QSqlQueryModel>

class historique
{
public:
    historique();
    historique(int,int,int,int,int);
    int getnbrpg();
    void setnbrpg(int);
    int getnbrpp();
    void setnbrpp(int);
    int getnbrmd();
    void setnbrmd(int);
    int getnbra();
    void setnbra(int);
    int getnbrb();
    void setnbrb(int);



     bool ajouterhis();
   QSqlQueryModel* affichierhis();


private:
    int nbrpg;
    int nbrpp;
    int nbrmd;
    int nbra;
    int nbrb;
};

#endif // HISTORIQUE_H

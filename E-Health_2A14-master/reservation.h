#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reservation
{
public:
    reservation();
    reservation(int id_r,QString nom_pat,QString prenom_pat,QString email_pat,QString date_r,QString sex_e);

    int get_id_r();
    QString get_nom_pat();
    QString get_prenom_pat();
    QString get_email_pat();
    QString get_date_r();
    QString get_sex_e();


    void set_id_r(int id_r1 ){id_r=id_r1;}
    void set_nom_pat(QString nom_pat1){nom_pat=nom_pat1;}
    void set_prenom_pat(QString prenom_pat1){prenom_pat=prenom_pat1;}
    void set_email_pat(QString email_pat1){email_pat=email_pat1;}
    void set_date_r(QString date_r1){date_r=date_r1;}
    void set_sex_e(QString sex_e1){sex_e=sex_e1;}
    bool modifier(int id_rr,QString nom_patt,QString prenom_patt,QString email_patt,QString date_rr,QString sex_ee);

    void chercher();
    bool ajouter(int id_r,QString nom_pat,QString prenom_pat,QString email_pat,QString date_r,QString sex_e);
    bool supprimer(int id_r);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche_e(int valeur);
    QSqlQueryModel * tri(int index);




private:
   int id_r;
   QString nom_pat,prenom_pat,email_pat,date_r,sex_e;
};

#endif // RESERVATION_H

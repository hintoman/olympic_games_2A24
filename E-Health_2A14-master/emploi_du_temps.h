#ifndef EMPLOI_DU_TEMPS_H
#define EMPLOI_DU_TEMPS_H

#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class emploi
{
public:
    emploi();
    emploi(int id_res,int id_doc,QString email_doc,QString date_rv,int heure_rv);
    int get_id_res();
    int get_id_doc();
    QString get_email_doc();
    QString get_date_rv();
    int get_heure_rv();

    void set_id_res(int id_res1){id_res=id_res1;}
    void set_id_doc(int id_doc1 ){id_doc=id_doc1;}
    void set_email_doc(QString email_doc1){email_doc=email_doc1;}
    void set_date_rv(QString date_rv1){date_rv=date_rv1;}
    void set_heure_rv(int heure_rv1 ){heure_rv=heure_rv1;}

    void chercher();
    bool ajouter(int id_res,int id_doc,QString email_doc,QString date_rv,int heure_rv);
    bool supprimer(int id_doc);
    bool modifier(int id_res,int id_doc,QString email_doc,QString date_rv,int heure_rv);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche_e(int id_doc);
    QSqlQueryModel * tri(int index);




private:
    QString email_doc,date_rv;
    int id_res,id_doc,heure_rv;

};


#endif // EMPLOI_DU_TEMPS_H

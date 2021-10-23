#ifndef employe_H
#define employe_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employe
{
public:
    employe();
    employe(int,QString,QString,int);
    int getid();
    QString getnom();
    QString getprenom();
    int gettel();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void settel(int);
    bool ajouter();
    bool modifier(int id,QString nom, QString prenom,int tel );
    QSqlQueryModel * rechercher(int id);
        QSqlQueryModel * afficher();
        QSqlQueryModel *Trier(QString );
        bool supprimer(int);
private:
    int id, tel ;
    QString nom,prenom;
};

#endif // employe_H

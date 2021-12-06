#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QAbstractSocket>
#include "ui_gestion_yessin.h"
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class employer
{
public:
    employer();
    employer(int,QString,int,QString);
    bool ajouter();
    bool supprimer(int id_emp);
    bool modifier(int id_emp);
    QSqlQueryModel* afficher();
    QSqlQueryModel *Trier(QString );
    QSqlQueryModel * rechercher(int id);
    void  browse();
    void  sendMail();
    void   mailSent(QString status);

private:
    QStringList files;
    int id_emp;
    QString nom;
    int salaire;
    QString date_entre;
    Ui::gestion_yessin *ui;

};





#endif // EMPLOYES_H



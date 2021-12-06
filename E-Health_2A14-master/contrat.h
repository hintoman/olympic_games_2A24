#ifndef CONTRAT_H
#define CONTRAT_H

#include <QString>
#include <iostream>
#include "health.h"
#include "ui_health.h"
#include <QtSql/QSqlQueryModel>
class contrat
{
private:
    int id;
    QString nomp;
    QString duree;
    QString dater;
    int remise;
public:
    contrat();
    contrat(int,QString,QString,QString,int);
    bool ajouter(Ui::health*ui);
    bool modifier(Ui::health*ui);
    bool supprimer (Ui::health*ui);
    void afficher(Ui::health*ui);
    void affichertable(Ui::health*ui);
    void Tri_Prix(Ui::health *ui);
    QSqlQueryModel *triercontrat();
    QSqlQueryModel *triercontrat_desc();
    QSqlQueryModel *recherchercontrat(QString id);
};

#endif // CONTRAT_H

#ifndef HISTORIQUE1_H
#define HISTORIQUE1_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historique1
{
    QString tmp;
public:
    historique1();
    void save(int,QString,QString,QString,QString,QString,QString);
    QString load();
};

#endif // HISTORIQUE1_H

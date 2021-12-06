#ifndef AFFICHER_H
#define AFFICHER_H

#include <QDialog>
#include "EMPLOYE.h"


namespace Ui {
class Afficher;
}

class Afficher : public QDialog
{
    Q_OBJECT

public:
    explicit Afficher(QWidget *parent = nullptr);
    void setEmploye(EMPLOYE E);
    ~Afficher();

private:
    Ui::Afficher *ui;
};

#endif // AFFICHER_H

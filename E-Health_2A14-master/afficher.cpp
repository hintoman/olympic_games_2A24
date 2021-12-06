#include "afficher.h"
#include "ui_afficher.h"
#include "EMPLOYE.h"


Afficher::Afficher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher)
{
    ui->setupUi(this);
}

Afficher::~Afficher()
{
    delete ui;
}
void Afficher::setEmploye(EMPLOYE E)
{

    ui->lineEditNom->setText(E.get_nom());
    ui->lineEditPrenom->setText(E.get_prenom());
    ui->lineEditMail->setText(E.get_mail());
    ui->lineEditDDN->setText(E.get_DDN());
    ui->lineEditTache->setText(E.get_Tache());

}

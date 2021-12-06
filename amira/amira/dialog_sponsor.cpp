#include "dialog_sponsor.h"
#include "ui_dialog_sponsor.h"

Dialog_sponsor::Dialog_sponsor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_sponsor)
{
    ui->setupUi(this);
}

Dialog_sponsor::~Dialog_sponsor()
{
    delete ui;
}

//config ok et cancel
void Dialog_sponsor::on_buttonBox_accepted()
{
accept();
}

void Dialog_sponsor::on_buttonBox_rejected()
{
reject();
}

//recuperation des donnees du formulaire


QString Dialog_sponsor::get_type() const { //combo box

    return ui->type->currentText();
}

QString Dialog_sponsor::get_nom() const { //line edit

    return ui->nom->text();
}

QString Dialog_sponsor::get_id() const { //line edit

    return ui->id->text();
}

QString Dialog_sponsor::get_adresse() const { //line edit

    return ui->adresse->text();
}


double Dialog_sponsor::get_montant() const{ //float

    return ui->montant->value();
}

//remplissage des champs du formulaire a partir de la base

void Dialog_sponsor::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from sponsors where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){

  ui->id->setText(query.value(0).toString()); //line edit
    ui->nom->setText(query.value(1).toString()); //line edit
      ui->adresse->setText(query.value(2).toString()); //line edit
   ui->type->setCurrentText(query.value(3).toString()); //combobox
     ui->montant->setValue(query.value(4).toReal()); // reel

    }

}

#include "form.h"
#include "ui_form.h"
#include "EMPLOYE.h"


Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
void Form::on_pushButton_3_clicked()
{
    EMPLOYE E;
   // E.setcin(ui->lineEdit->text());
    E.setnom(ui->lineEditNom->text());
    E.setprenom(ui->lineEditPrenom->text());
    E.setmail(ui->lineEditMail->text());
    E.setDDN(ui->lineEditDDN->text());
    E.setTache(ui->lineEditTache->text());

    Afficher A ;

    A.setEmploye(E);
    A.exec();

}
/*void Form::on_pushButton_3_clicked()
{
    EMPLOYE E ;
   Afficher A ;

   A.setEmploye(E);
   A.exec();


}*/

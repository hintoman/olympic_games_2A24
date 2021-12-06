#include "calculatrice.h"
#include <QMessageBox>


calculatrice::calculatrice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculatrice)
{
    ui->setupUi(this);
}

calculatrice::~calculatrice()
{
    delete ui;
}
void calculatrice::on_calculBouton_clicked()
{
    float nbr2, calculNbr;
    nbr2 = ui->resultLine->text().toFloat();
    if(action == diviser) {
        if(nbr2 != 0) {
            calculNbr = premierNombre / nbr2;
        } else {
            calculNbr = 0;
            QMessageBox::critical(this, "Calculatrice - sKy", "Math Error! (x/0)");
        }
    } else if (action == additionner) {
        calculNbr = premierNombre + nbr2;
    } else if (action == multiplier) {
        calculNbr = premierNombre * nbr2;
    } else if (action == soustraire) {
        calculNbr = premierNombre - nbr2;
    }
    ui->resultLine->setText(QString::number(calculNbr));
    ansNombre = QString::number(calculNbr);
    premierNombre = 0;
}

void calculatrice::on_diviserBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre = ui->resultLine->text().toFloat();
        action = diviser;
        ui->resultLine->setText("0");
    }
}

void calculatrice::on_additionnerBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre =ui->resultLine->text().toFloat();
        action = additionner;
        ui->resultLine->setText("0");
    }
}

void calculatrice::on_multiplierBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre = ui->resultLine->text().toFloat();
        action = multiplier;
        ui->resultLine->setText("0");
    }
}

void calculatrice::on_soustraireBouton_clicked()
{
    if(ui->resultLine->text() != "0") {
        premierNombre = ui->resultLine->text().toFloat();
        action = soustraire;
        ui->resultLine->setText("0");
    }
}

void calculatrice::on_number0_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("0");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("0");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "0");
    }
}

void calculatrice::on_number1_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("1");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("1");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "1");
    }
}

void calculatrice::on_number2_clicked()
{
     if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("2");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("2");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "2");
    }
}

void calculatrice::on_number3_clicked()
{
     if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("3");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("3");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "3");
    }
}

void calculatrice::on_number4_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("4");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
       ui->resultLine->setText("4");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "4");
    }
}

void calculatrice::on_number5_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("5");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("5");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "5");
    }
}

void calculatrice::on_number6_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("6");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("6");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "6");
    }
}

void calculatrice::on_number7_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("7");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("7");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "7");
    }
}

void calculatrice::on_number8_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("8");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("8");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "8");
    }
}

void calculatrice::on_number9_clicked()
{
    if(ui->resultLine->text() == "0") {
        ui->resultLine->setText("9");
    } else if(ui->resultLine->text() == "0" and not premierNombre) {
        ui->resultLine->setText("9");
    } else if(ui->resultLine->text() != "0") {
        ui->resultLine->setText(ui->resultLine->text() + "9");
    }
}

void calculatrice::on_clearBouton_clicked()
{
    ui->resultLine->setText("0");
    premierNombre = 0;
}

void calculatrice::on_ansBouton_clicked()
{
    if(ansNombre != 0) {
        ui->resultLine->setText(ansNombre);
    }
}

void calculatrice::on_virguleBouton_clicked()
{
    ui->resultLine->setText(ui->resultLine->text() + ".");
}


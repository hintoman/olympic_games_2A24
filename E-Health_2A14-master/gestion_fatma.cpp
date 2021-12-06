#include "gestion_fatma.h"
#include "ui_gestion_fatma.h"

gestion_fatma::gestion_fatma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_fatma)
{
    ui->setupUi(this);
}

gestion_fatma::~gestion_fatma()
{
    delete ui;
}

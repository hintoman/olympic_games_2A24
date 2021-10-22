#include "modul.h"
#include "ui_modul.h"

MODUL::MODUL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MODUL)
{
    ui->setupUi(this);
}

MODUL::~MODUL()
{
    delete ui;
}

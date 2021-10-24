#include "gest_sponsors.h"
#include "ui_gest_sponsors.h"

gest_sponsors::gest_sponsors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gest_sponsors)
{
    ui->setupUi(this);
}

gest_sponsors::~gest_sponsors()
{
    delete ui;
}

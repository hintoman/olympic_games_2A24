#include "arduinoo.h"
#include "ui_arduinoo.h"

arduinoo::arduinoo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinoo)
{
    ui->setupUi(this);
    int ret =A.connect_arduino();//lancer la connection to arduino
    switch (ret) {

    case(0):qDebug()<<"arduino is available and connect to : "<<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available and not  connect to : "<<A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available ";
        break;

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}


void arduinoo::update_label()
{

    data=A.read_from_arduino();

    if (data=="2")

        ui->label_2->setText("ALARME ACTIVER");//afficher on si les données reçues par arduino est 1

    else if(data=="3")

           ui->label_2->setText("ALARME DESACTIVER");
    if (data=="4")

        ui->label_3->setText("LAMPE ALLUMER");//afficher on si les données reçues par arduino est 1

    else if(data=="5")

           ui->label_3->setText("LAMPE ETEINDRE");
}

void arduinoo::on_pushButton_clicked()
{
        A.write_to_arduino("2");//pour l'activation de l'alarme
}

void arduinoo::on_pushButton_2_clicked()
{
    A.write_to_arduino("3");// pour la désactivation de l'alarme
}

void arduinoo::on_pushButton_3_clicked()
{
    A.write_to_arduino("4");//pour l'allumation de la lampe
}

void arduinoo::on_pushButton_4_clicked()
{
    A.write_to_arduino("5");//pour l'eteindre de la lampe
}
arduinoo::~arduinoo()
{
    delete ui;
}

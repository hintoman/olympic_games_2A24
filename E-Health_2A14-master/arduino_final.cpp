#include "arduino_final.h"
#include "ui_arduino_final.h"

Arduino_final::Arduino_final(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arduino_final)
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
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(detction_de_chaleur()));
}
void Arduino_final::update_label()
{
    data=A.read_from_arduino();

    if (data=="4")

        ui->label_2->setText("LAMPE ALLUMER");//afficher on si les données reçues par arduino est 1

    else if(data=="5")

        ui->label_3->setText("LAMPE ETEINDRE");


}
void Arduino_final::on_pushButton_3_clicked()
{
    A.write_to_arduino("4");
}
void Arduino_final::on_pushButton_4_clicked()
{
    A.write_to_arduino("5");

}
Arduino_final::~Arduino_final()
{
    delete ui;
}





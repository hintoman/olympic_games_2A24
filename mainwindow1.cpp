#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "transaction.h"
#include "mainwindow.h"



MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    int ret=A1.connect_arduino();
             switch(ret){
             case(0):qDebug()<< "arduino is availble and connected to :"<< A1.getarduino_port_name();
                 break;
             case(1):qDebug()<< "arduino is availble but not connected to :"<< A1.getarduino_port_name();
                 break;
             case(-1):qDebug()<< "arduino is not availble";
             }
             QObject::connect(A1.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_clicked()
{
      code="";




}
void MainWindow1::update_label()  { //label arduino

    data1 =A1.read_from_arduino();
    QString DataAsString = QString(data1);
    code=code+DataAsString;

    int ret;
    qDebug()<< code;
    ui->label_arduino1->setText(code);
    if(code.length()==4){
        if(code.compare("1234")==0){
            A1.write_to_arduino("1");
            close();
                      MainWindow W;
                     W.show();


        }
       else {
            A1.write_to_arduino("0");
        }
    }


}

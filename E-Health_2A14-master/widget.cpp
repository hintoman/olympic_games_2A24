#include "widget.h"
#include "ui_widget.h"
#include "DuMesengerConnectionDialog.h"
#include <QTcpSocket>
#include <QTextStream>
namespace DuarteCorporation
{
widget::widget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });
}

widget::~widget()
{
    delete ui;
}

void widget::on_send_clicked()
{
    QTextStream T(mSocket);
    T << ui->nickname->text() <<" : " << ui->message->text();
    mSocket->flush();
    ui->message->clear();
}

void widget::on_bind_clicked()
{
   DuMesengerConnectionDialog D (this);
   if(D.exec() == QDialog ::Rejected){
       return;
   }
   mSocket->connectToHost(D.hostname(),D.port());


}
}

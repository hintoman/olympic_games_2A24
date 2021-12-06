#include "arduino.h"

arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    Serial=new QSerialPort ;
}
QString arduino::getarduino_port_name()
{

    return arduino_port_name ;

}

QSerialPort *arduino::getserial()
{

    return Serial;
}

int arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info,QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if (serial_port_info.vendorIdentifier()== arduino_uno_vendor_id && serial_port_info.productIdentifier()== arduino_uno_producy_id)
            {
                arduino_is_available=true ;
                arduino_port_name=serial_port_info.portName();

            }
        }

    }
    qDebug() <<"arduino_port_name is :" <<arduino_port_name ;
    if(arduino_is_available)
    {
        Serial->setPortName(arduino_port_name);
        if(Serial->open(QSerialPort::ReadWrite))
        {
            Serial->setBaudRate(QSerialPort::Baud9600);//débit : 9600bits/s
            Serial->setDataBits(QSerialPort::Data8);//Longeur de donnée : 8bits
            Serial->setParity(QSerialPort::NoParity);//1 bit de parite optionnel
            Serial->setStopBits(QSerialPort::OneStop);//Nombre de bit de stop 1
            Serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0 ;

        }
        return 1;

    }
    return -1;

}
int arduino::close_arduino()
{

    if(Serial->isOpen())
    {
        Serial->close();
        return 0;
    }
    return 1;

}

QByteArray arduino::read_from_arduino()
{

    if (Serial->isReadable()){

        data=Serial->readAll();//récuperer les données réçues
       return data;
    }


}

int arduino::write_to_arduino( QByteArray d)
{
    if (Serial->isWritable())
    {
       Serial->write(d);

    }
    else {qDebug()<<"couldn't write to Arduino !";}

}










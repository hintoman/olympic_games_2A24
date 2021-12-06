#include "mainwindow.h"
#include"connection.h"
#include <QMessageBox>
#include <QApplication>
#include <QTranslator>
#include<QInputDialog>
#include "DuMesengerConnectionDialog.h"
#include "widget.h"

using namespace DuarteCorporation;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;

   Connection c ;
    QTranslator t;
       QStringList languages ;
       languages << "ARABIC"<<"FRENCH"<<"ENGLISH";
       QString lang = QInputDialog::getItem(NULL,"SELECTIONNER VOTRE LANGUE",
                                            "LANGUE",languages);
       if ( lang =="ARABIC")
       {
           t.load(":/arabic.qm");
       }
       else if( lang =="ENGLISH")
        {
           t.load(":/english.qm");
        }

       if ( lang != "fFRENCH")
       {
           a.installTranslator(&t);
       }

    bool test=c.createconnect();
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}


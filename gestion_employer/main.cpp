#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include <QSystemTrayIcon>


int main(int argc, char *argv[])

{


    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();

        {   QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                           notifyIcon->show();
                           notifyIcon->setIcon(QIcon("icone.png"));

                           notifyIcon->showMessage("database is open ","Connection Successful",QSystemTrayIcon::Information,15000); }

}
    else

    {   QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                       notifyIcon->show();
                       notifyIcon->setIcon(QIcon("icone.png"));

                       notifyIcon->showMessage("database is not open ","Connection Failed",QSystemTrayIcon::Information,15000); }



    return a.exec();
}

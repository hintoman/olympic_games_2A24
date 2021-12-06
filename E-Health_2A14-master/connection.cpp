#include "connection.h"
//test git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase test_bd = QSqlDatabase::addDatabase("QODBC");
test_bd.setDatabaseName("test_bd");//inserer le nom de la source de données ODBC
test_bd.setUserName("oussama");//inserer nom de l'utilisateur
test_bd.setPassword("oussama");//inserer mot de passe de cet utilisateur


if (test_bd.open())
test=true;





    return  test;
}
    void Connection::fermerconnection()
    {

        test_bd.close();
    }

    QSqlDatabase Connection::get_db()
    {
        return test_bd;
    }



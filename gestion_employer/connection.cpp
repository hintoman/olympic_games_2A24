#include "connection.h"
//test tutoriel Git

Connection::Connection()

{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2");//inserer le nom de la source de données ODBC
db.setUserName("firas");//inserer nom de l'utilisateur
db.setPassword("firas2001");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

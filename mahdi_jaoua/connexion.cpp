#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("qt_2021");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("Youssef123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

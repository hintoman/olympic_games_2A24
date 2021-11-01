#ifndef CLIENT_H
#define CLIENT_H
#include<QString>

class client
{
public:
    void setcin(QString n);
    void setprenom(QString n);
    void setnom(QString n);
    QString get_cin();
    QString get_prenom();
    QString get_nom();
    client();

private:
    QString cin,prenom,nom ;
};

#endif // CLIENT_H

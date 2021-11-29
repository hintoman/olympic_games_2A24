
#include "historique1.h"

historique1::historique1()
{

}
void historique1::save(int id, QString num_c, QString id_c, QString couleur, QString carte, QString annee,QString dates)
{    QFile file ("C:/Users/Monta/Desktop/monta.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";

     QTextStream out(&file);
     out << id+"\n"+num_c << "\n"+id_c << "\n"+couleur<< "\n"+carte<< "\n"+annee <<  "\n"+dates<<"\n""------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";


}
QString historique1::load()
{   tmp="";
    QFile file("C:/Users/Monta/Desktop/monta.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}

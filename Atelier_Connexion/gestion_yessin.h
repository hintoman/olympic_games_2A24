#ifndef GESTION_YESSIN_H
#define GESTION_YESSIN_H
#include "employes.h"
#include <QMainWindow>
#include <mailing.h>
#include <QAbstractSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class gestion_yessin; }
QT_END_NAMESPACE

class gestion_yessin : public QMainWindow
{
    Q_OBJECT

public:
    gestion_yessin(QWidget *parent = nullptr);
    ~gestion_yessin();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_trier_activated();
    void on_recherche_button_clicked();

    void on_pb_pdf_clicked();
    void on_sendmail_clicked();


void on_login_2_clicked();
private:
    QStringList files;
    Ui::gestion_yessin *ui;
    employer emp;
    mailing P;
    QString pass , user ;
        bool res1  , res2  ;

};
#endif // GESTION_YESSIN_H

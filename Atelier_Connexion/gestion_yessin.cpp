#include "gestion_yessin.h"
#include "ui_gestion_yessin.h"
#include "ui_form.h"
#include "smtp.h"
#include "mailing.h"
#include "mainwindow.h"
#include "employes.h"
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include<QFile>
#include <QFileDialog>
#include<QTextDocument>
gestion_yessin::gestion_yessin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_yessin)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/Monta/Desktop/back.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    connect(ui->sendmail, SIGNAL(clicked()),this, SLOT(sendMail()));

    ui->tablemp->setModel(emp.afficher());

}



gestion_yessin::~gestion_yessin()
{
    delete ui;
}


void gestion_yessin::on_pushButton_clicked()
{
    int id_emp=ui->id_emp->text().toInt();
    QString nom=ui->nom->text();
    int salaire=ui->salaire->text().toInt();
    QString date_entre=ui->dateEdit->text();
    employer r(id_emp,nom,salaire,date_entre);
    r.ajouter();
    ui->tablemp->setModel(emp.afficher());
}

void gestion_yessin::on_pushButton_2_clicked()
{
    int id_emp=ui->id_emp->text().toInt();
    QString nom=ui->nom->text();
    int salaire=ui->salaire->text().toInt();
    QString date_entre=ui->dateEdit->text();
    employer r(id_emp,nom,salaire,date_entre);
    r.modifier(id_emp);


    if(salaire>0)
   { bool test=r.modifier(id_emp);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("employer modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->tablemp->setModel(emp.afficher());

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("employer non modifié"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }}
    else{
        QMessageBox::critical(nullptr, QObject::tr("verifiez le prix"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void gestion_yessin::on_pushButton_3_clicked()
{
    int id_emp=ui->id_empSupp->text().toInt();
    emp.supprimer(id_emp);
    ui->tablemp->setModel(emp.afficher());
}


void gestion_yessin::on_trier_activated()
{
    employer A;
    QString choix= ui->trier->currentText();
    ui->tablemp->setModel(A.Trier(choix));
}


void gestion_yessin::on_recherche_button_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
                    QSqlQuery request;
                   QString type=ui->recherche_type->currentText();
                   QString val=ui->text_recherche->text();
                   val="%"+val+"%";
                   if (type=="id_emp"){
                       request.prepare("SELECT * FROM gs_employer WHERE id_emp LIKE:val ");
                   }else if (type=="nom"){
                       request.prepare("SELECT * FROM gs_employer WHERE nom LIKE:val");
                   }else if (type=="date_entre"){
                       request.prepare("SELECT * FROM gs_employer WHERE date_entre LIKE:val");

                   }
                   request.bindValue(":val",val);
                   request.exec();
                   modal->setQuery(request);
                   ui->tablemp_1->setModel(modal);

}



void gestion_yessin::on_pb_pdf_clicked()
{
    QString strStream;
          QTextStream out(&strStream);

                     const int rowCount = ui->tablemp->model()->rowCount();
                     const int columnCount = ui->tablemp->model()->columnCount();

                     out <<  "<html>\n"
                           "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                          //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des Fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                             out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                               if (!ui->tablemp->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tablemp->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                             for (int row = 0; row < rowCount; row++) {
                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                 for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tablemp->isColumnHidden(column)) {
                                QString data = ui->tablemp->model()->data(ui->tablemp->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                         }
                                     }
                                     out << "</tr>\n";
                                  }
                                 out <<  "</table> </center>\n"
                                      "</body>\n"
                                    "</html>\n";

                            QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), ".pdf");
                              if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
                            QPrinter printer (QPrinter::PrinterResolution);
                               printer.setOutputFormat(QPrinter::PdfFormat);
                              printer.setPaperSize(QPrinter::A4);
                             printer.setOutputFileName(fileName);

                              QTextDocument doc;
                               doc.setHtml(strStream);
                               doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                               doc.print(&printer);
    }




void gestion_yessin::on_login_2_clicked()
{gestion_yessin w;

    res1=false;
    res2=false;
    user=ui->username->text();
   pass = ui->password->text();

       QString c_pass = "yassine";
       int a = c_pass.compare(pass);
       if(a == 0)
       res1 = true ;

       QString c_user = "yassine";
       int b = c_user.compare(user);
       if( b == 0 )
       res2 = true ;
       if(res2 == true && res1 == true)
       {QMessageBox::information(nullptr, QObject::tr("compte is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
w.show();
             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("compte is not open"),
                                 QObject::tr("connection failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestion_yessin::on_sendmail_clicked()
{
    Smtp* smtp = new Smtp("yassine.hamrouni@esprit.tn",ui->passwrd->text(), "smtp.gmail.com");


        smtp->sendMail("yassine.hamrouni@esprit.tn",ui->recep->text() , ui->object->text(),ui->msg->toPlainText());
}

void gestion_yessin::on_pushButton_4_clicked()
{
    close();
    MainWindow *ga;
    ga = new MainWindow();
    ga->show();
}

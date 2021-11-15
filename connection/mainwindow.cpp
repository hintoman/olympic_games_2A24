#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include "smtp.h"
#include "mailing.h"
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include<QFile>
#include <QFileDialog>
#include<QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablemp->setModel(emp.afficher());

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id_emp=ui->id_emp->text().toInt();
    QString nom=ui->nom->text();
    int salaire=ui->salaire->text().toInt();
    QString date_entre=ui->dateEdit->text();
    employer r(id_emp,nom,salaire,date_entre);
    r.ajouter();
    ui->tablemp->setModel(emp.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    int id_emp=ui->id_emp->text().toInt();
    QString nom=ui->nom->text();
    int salaire=ui->salaire->text().toInt();
    QString date_entre=ui->dateEdit->text();
    employer r(id_emp,nom,salaire,date_entre);
    r.modifier(id_emp);
    ui->tablemp->setModel(emp.afficher());
}
void MainWindow::on_pushButton_3_clicked()
{
    int id_emp=ui->id_empSupp->text().toInt();
    emp.supprimer(id_emp);
    ui->tablemp->setModel(emp.afficher());
}


void MainWindow::on_trier_activated()
{
    employer A;
    QString choix= ui->trier->currentText();
    ui->tablemp->setModel(A.Trier(choix));
}


void MainWindow::on_recherche_button_clicked()
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
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->name->text(), ui->passwrd->text());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->name->text(), ui->recep->text() , ui->object->text(),ui->plainTextEdit->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );}


void MainWindow::on_pb_pdf_clicked()
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


void Ui_Form::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username ==  "test" && password == "test") {
        QMessageBox::information(this, "Login", "Username and password is correct");
        //hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}

#include "gestion_amira.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include "ui_gestion_amira.h"
#include "mainwindow.h"

gestion_amira::gestion_amira(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_amira)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/LENOVO/Desktop/amira/amira/back_amira.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    //affichage contenu de la base
    show_tables();


}

gestion_amira::~gestion_amira()
{
    delete ui;
}
//************************************* CRUD ******************************************
//dialog out  named ds then we have result (1:created/0:still didn't //dialog rejected return :fon closed
//ajout
void gestion_amira::on_actionadd_sponsor_triggered()
{
    //creation instance
        Dialog_sponsor ds(this);

        //ouvrir dialog
        int res=ds.exec();
        if (res == QDialog::Rejected )
            return;

    //recuperation des donnees
      QString s1=ds.get_id();
      QString s2=ds.get_nom();
      QString s3=ds.get_adresse();
      QString s4=ds.get_type();
      double x=ds.get_montant();

      //we ve variable->requette de prog  with bindvalue
      //ajout
      sponsor s(s1,s2,s3,s4,x);
      s.ajouter();

      //refresh du tableau (affichage)
        show_tables();
}

//get id of selected row
void gestion_amira::on_tableau_sponsors_clicked(const QModelIndex &index)
{
selected=ui->tableau_sponsors->model()->data(index).toString();
}
//from detect we ve tab where  id then
//suppression
void gestion_amira::on_actiondelete_sponsor_triggered()
{
    sponsor s;
  s.supprimer(selected);

 //refresh du tableau (affichage)
   show_tables();
}
//dialog opened:file form then i get donnes and modifiy them
//knowd with id /update:refresh->name set tab/name set colone /variable
//modification
void gestion_amira::on_tableau_sponsors_doubleClicked(const QModelIndex &index)
{
    Dialog_sponsor ds(this);

  ds.fill_form(selected);
  int res=ds.exec();
  if (res == QDialog::Rejected )
    return;


  //recuperation des donnees
  QString s1=selected;
  QString s2=ds.get_nom();
  QString s3=ds.get_adresse();
  QString s4=ds.get_type();
  double x=ds.get_montant();

    //mofication
    sponsor s(selected,s2,s3,s4,x);
    s.modifier(selected);



  //refresh du tableau (affichage)
   show_tables();

}
//select*tab name ill get all colon and all continues
//affichage
void gestion_amira::show_tables(){
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp.afficher());
//proxysinsi(coloneproxy /filter string needs chainee de caractere to filter
 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableau_sponsors->setModel(proxy);

}



//************************************* Metiers ***************************************

//mailing
void  gestion_amira::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   gestion_amira::sendMail()
{
    Smtp* smtp = new Smtp("manai.amira@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("manai.amira@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("manai.amira@esprit.tn",ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   gestion_amira::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}



//recherche dynamique
void gestion_amira::on_sel_col_currentIndexChanged(int index)
{
    sel_col=ui->sel_col->currentIndex()-1;
        proxy->setFilterKeyColumn(sel_col); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}

void gestion_amira::on_rech_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}



//export excel
void gestion_amira::on_export_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableau_sponsors);

    //colums to export
    obj.addField(0, "ID", "char(20)");
    obj.addField(1, "NOM", "char(20)");
    obj.addField(2, "ADRESSE", "char(20)");
    obj.addField(3, "TYPE_CONTRAT", "char(20)");
    obj.addField(4, "MONTANT", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}


//stats
void gestion_amira::on_actionstats_triggered()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_bar();
  s->show();
}

void gestion_amira::on_pushButton_clicked()
{
    QMediaPlayer* player = new QMediaPlayer ;
        QVideoWidget* vw = new QVideoWidget ;
        player->setVideoOutput(vw);
        vw->setGeometry(100,100,300,400);
        player->setMedia(QUrl::fromLocalFile("C:/Users/MIRA10/Downloads/olympic games.mp4"));
        vw->show();
        player->play();
}

void gestion_amira::on_pushButton_2_clicked()
{
    close();
    MainWindow *ga;
    ga = new MainWindow();
    ga->show();
}


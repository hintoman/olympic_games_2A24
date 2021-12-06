#include "gestion_mahdi.h"
#include "ui_gestion_mahdi.h"
#include "mainwindow.h"

gestion_mahdi::gestion_mahdi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_mahdi)
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

gestion_mahdi::~gestion_mahdi()
{
    delete ui;
}

//affichage
void gestion_mahdi::show_tables(){

    show_table_terrain();
    show_table_reclamation();

}



//******************************** terrain ***********************************************

//************ get variables ***********************

//recuperation des donnees du formulaire


QString gestion_mahdi::get_etat() const { //combo box

    return ui->etat->currentText();
}

QString gestion_mahdi::get_nom() const { //line edit

    return ui->nom->text();
}

QString gestion_mahdi::get_id_terrain() const { //line edit

    return ui->id_terrain->text();
}

QString gestion_mahdi::get_lieu() const { //line edit

    return ui->lieu->text();
}


int gestion_mahdi::get_capacite() const{ //float

    return ui->capacite->value();
}

//remplissage des champs du formulaire a partir de la base

void gestion_mahdi::fill_form_terrain(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from terrain where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){

  ui->id_terrain->setText(query.value(0).toString()); //line edit
    ui->nom->setText(query.value(1).toString()); //line edit
      ui->lieu->setText(query.value(2).toString()); //line edit
   ui->etat->setCurrentText(query.value(3).toString()); //combobox
     ui->capacite->setValue(query.value(4).toInt()); // int

    }

}

void gestion_mahdi::clear_form_terrain( ) {

    ui->id_terrain->clear();
    ui->nom->clear();
    ui->lieu->clear();
    ui->etat->setCurrentIndex(0);
    ui->capacite->setValue(0);
}

//************** crud *******************************

//ajout
void gestion_mahdi::on_actionajout_terrain_triggered()
{
    //recuperation des donnees
      QString s1=get_id_terrain();
      QString s2=get_nom();
      QString s3=get_lieu();
      QString s4=get_etat();
      int x=get_capacite();


      //ajout
      terrain s(s1,s2,s3,s4,x);
      s.ajouter();

      clear_form_terrain( );

      //refresh du tableau (affichage)
        show_tables();
}


void gestion_mahdi::on_ajou_t_clicked()
{
    //recuperation des donnees
      QString s1=get_id_terrain();
      QString s2=get_nom();
      QString s3=get_lieu();
      QString s4=get_etat();
      int x=get_capacite();


      //ajout
      terrain s(s1,s2,s3,s4,x);
      s.ajouter();

      clear_form_terrain( );

      //refresh du tableau (affichage)
        show_tables();
}


//supression
void gestion_mahdi::on_actionsuppression_terrain_triggered()
{
    terrain s;
  s.supprimer(selected_terrain);

 //refresh du tableau (affichage)
   show_tables();
}

void gestion_mahdi::on_suppression_t_clicked()
{
    terrain s;
  s.supprimer(selected_terrain);

 //refresh du tableau (affichage)
   show_tables();
}


//get row
void gestion_mahdi::on_tableau_terrain_clicked(const QModelIndex &index)
{
 selected_terrain=ui->tableau_terrain->model()->data(index).toString();
}


//modification

void gestion_mahdi::on_actionmodifier_terrain_triggered()
{
    //recuperation des donnees
    QString s1=selected_terrain;
    QString s2=get_nom();
    QString s3=get_lieu();
    QString s4=get_etat();
    int x=get_capacite();

      //mofication
      terrain s(selected_terrain,s2,s3,s4,x);
      s.modifier(selected_terrain);

clear_form_terrain( );

    //refresh du tableau (affichage)
     show_tables();
}


void gestion_mahdi::on_modification_t_clicked()
{
    //recuperation des donnees
    QString s1=selected_terrain;
    QString s2=get_nom();
    QString s3=get_lieu();
    QString s4=get_etat();
    int x=get_capacite();

      //mofication
      terrain s(selected_terrain,s2,s3,s4,x);
      s.modifier(selected_terrain);

clear_form_terrain( );

    //refresh du tableau (affichage)
     show_tables();
}



void gestion_mahdi::on_tableau_terrain_doubleClicked(const QModelIndex &index)
{
   fill_form_terrain(selected_terrain);
}

//affichage
void gestion_mahdi::show_table_terrain(){
//creation model (masque du tableau) : permet recherche et tri
    proxy_terrain = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy_terrain->setSourceModel(tmp_terrain.afficher());

 //pour la recherche
    proxy_terrain->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy_terrain->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableau_terrain->setModel(proxy_terrain);

}



//**************** metiers **********************************

//recherche

//get col
void gestion_mahdi::on_sel_col_terrain_currentIndexChanged(const QString &arg1)
{
    sel_col_terrain=ui->sel_col_terrain->currentIndex()-1;
        proxy_terrain->setFilterKeyColumn(sel_col_terrain); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}

//get text
void gestion_mahdi::on_rech_terrain_textChanged(const QString &arg1)
{
  proxy_terrain->setFilterFixedString(arg1);
}

























//******************************** reclamation ***********************************************

//************ get variables ***********************

//recuperation des donnees du formulaire


QString gestion_mahdi::get_etat_reclamation() const { //combo box

    return ui->etat_reclamation->currentText();
}

QString gestion_mahdi::get_mail() const { //line edit

    return ui->mail->text();
}

QString gestion_mahdi::get_id_reclamation() const { //line edit

    return ui->id_reclamation->text();
}

QString gestion_mahdi::get_description() const { //text edit

    return ui->description->toPlainText();
}


//remplissage des champs du formulaire a partir de la base

void gestion_mahdi::fill_form_reclamation(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from reclamation where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){

  ui->id_reclamation->setText(query.value(0).toString()); //line edit
    ui->description->setText(query.value(1).toString()); //text edit
      ui->mail->setText(query.value(2).toString()); //line edit
   ui->etat_reclamation->setCurrentText(query.value(3).toString()); //combobox

    }

}

void gestion_mahdi::clear_form_reclamation( ) {

    ui->id_reclamation->clear();
    ui->description->clear();
    ui->mail->clear();
    ui->etat_reclamation->setCurrentIndex(0);

}

//************** crud *******************************

//ajout
void gestion_mahdi::on_actionajout_reclamation_triggered()
{
    //recuperation des donnees
      QString s1=get_id_reclamation();
      QString s2=get_description();
      QString s3=get_mail();
      QString s4=get_etat_reclamation();


      //ajout
      reclamation s(s1,s2,s3,s4);
      s.ajouter();

      clear_form_reclamation();

      //refresh du tableau (affichage)
        show_tables();
}


void gestion_mahdi::on_ajout_r_clicked()
{
    //recuperation des donnees
      QString s1=get_id_reclamation();
      QString s2=get_description();
      QString s3=get_mail();
      QString s4=get_etat_reclamation();


      //ajout
      reclamation s(s1,s2,s3,s4);
      s.ajouter();

      clear_form_reclamation();

      //refresh du tableau (affichage)
        show_tables();
}

//supression
void gestion_mahdi::on_actionsuppression_reclamation_triggered()
{
    reclamation s;
  s.supprimer(selected_reclamation);

 //refresh du tableau (affichage)
   show_tables();
}


void gestion_mahdi::on_suppression_r_clicked()
{
    reclamation s;
  s.supprimer(selected_reclamation);

 //refresh du tableau (affichage)
   show_tables();
}


//get row
void gestion_mahdi::on_tableau_reclamation_clicked(const QModelIndex &index)
{
 selected_reclamation=ui->tableau_reclamation->model()->data(index).toString();
}


//modification

void gestion_mahdi::on_actionmodifier_reclamation_triggered()
{
    //recuperation des donnees
    QString s1=selected_reclamation;
    QString s2=get_description();
    QString s3=get_mail();
    QString s4=get_etat_reclamation();

      //mofication
      reclamation s(selected_reclamation,s2,s3,s4);
      s.modifier(selected_reclamation);

clear_form_reclamation() ;

    //refresh du tableau (affichage)
     show_tables();
}


void gestion_mahdi::on_modification_r_clicked()
{
    //recuperation des donnees
    QString s1=selected_reclamation;
    QString s2=get_description();
    QString s3=get_mail();
    QString s4=get_etat_reclamation();

      //mofication
      reclamation s(selected_reclamation,s2,s3,s4);
      s.modifier(selected_reclamation);

clear_form_reclamation() ;

    //refresh du tableau (affichage)
     show_tables();
}


void gestion_mahdi::on_tableau_reclamation_doubleClicked(const QModelIndex &index)
{
   fill_form_reclamation(selected_reclamation);
}

//affichage
void gestion_mahdi::show_table_reclamation(){
//creation model (masque du tableau) : permet recherche et tri
    proxy_reclamation = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy_reclamation->setSourceModel(tmp_reclamation.afficher());

 //pour la recherche
    proxy_reclamation->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy_reclamation->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableau_reclamation->setModel(proxy_reclamation);

}



//**************** metiers **********************************

//recherche

//get col
void gestion_mahdi::on_sel_col_reclamation_currentIndexChanged(const QString &arg1)
{
    sel_col_reclamation=ui->sel_col_reclamation->currentIndex()-1;
        proxy_reclamation->setFilterKeyColumn(sel_col_reclamation); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}

//get text
void gestion_mahdi::on_rech_reclamation_textChanged(const QString &arg1)
{
  proxy_reclamation->setFilterFixedString(arg1);
}









//mailing
void  gestion_mahdi::browse()
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
void   gestion_mahdi::sendMail()
{
    Smtp* smtp = new Smtp("mahdi.jaoua@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("mahdi.jaoua@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("mahdi.jaoua@esprit.tn",ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   gestion_mahdi::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}


//geolocalisation

void gestion_mahdi::on_actioncheck_map_triggered()
{
    /*
maps *m;
m=new maps();
m->resize(1024, 768);
m->show();
*/
}



void gestion_mahdi::on_pushButton_clicked()
{
    close();
    MainWindow *ga;
    ga = new MainWindow();
    ga->show();
}

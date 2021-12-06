#ifndef GESTION_AMIRA_H
#define GESTION_AMIRA_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>

#include "sponsor.h"
#include "dialog_sponsor.h"
#include "smtp.h"
#include "exportexcelobject.h"
#include "stat_combo.h"


namespace Ui {
class gestion_amira;
}

class gestion_amira : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_amira(QWidget *parent = nullptr);
    ~gestion_amira();

    sponsor tmp;
    QSortFilterProxyModel *proxy;

    void show_tables();

private slots:


    void sendMail();
    void mailSent(QString);
    void browse();


    void on_tableau_sponsors_clicked(const QModelIndex &index);

    void on_tableau_sponsors_doubleClicked(const QModelIndex &index);

    void on_actionadd_sponsor_triggered();

    void on_actiondelete_sponsor_triggered();

    void on_sel_col_currentIndexChanged(int index);

    void on_rech_textChanged(const QString &arg1);

    void on_export_excel_clicked();

    void on_actionstats_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestion_amira *ui;
    QString selected="";
    int sel_col=-1;
    QStringList files;
        stat_combo *s;
};

#endif // GESTION_AMIRA_H

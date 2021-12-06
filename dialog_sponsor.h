#ifndef DIALOG_SPONSOR_H
#define DIALOG_SPONSOR_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Dialog_sponsor;
}

class Dialog_sponsor : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_sponsor(QWidget *parent = nullptr);
    ~Dialog_sponsor();

    QString get_nom () const ;
    QString get_id () const ;
    QString get_adresse() const;
    QString get_type() const ;
    double get_montant() const;

    void fill_form(QString);


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
    private:
    Ui::Dialog_sponsor *ui;
};

#endif // DIALOG_SPONSOR_H

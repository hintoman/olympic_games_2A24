#ifndef DUMESENGERCONNECTIONDIALOG_H
#define DUMESENGERCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class DuMesengerConnectionDialog;
}
namespace DuarteCorporation
{
class DuMesengerConnectionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DuMesengerConnectionDialog(QWidget *parent = nullptr);
    ~DuMesengerConnectionDialog();
    QString hostname() const;
    quint16 port() const ;
private slots:
    void on_ok_clicked();
    void on_cancel_clicked();
private:
    Ui::DuMesengerConnectionDialog *ui;
    QString mHostname;
    quint16 mPort;

};
inline QString DuMesengerConnectionDialog::hostname() const
{
    return mHostname;
}
inline quint16 DuMesengerConnectionDialog::port() const
{
    return  mPort;
}
}
#endif // DUMESENGERCONNECTIONDIALOG_H

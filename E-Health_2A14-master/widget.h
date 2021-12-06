#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>

namespace Ui {
class widget;
}
class QTcpSocket;
namespace DuarteCorporation
{
class widget : public QDialog
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();
private slots:
    void on_send_clicked();
    void on_bind_clicked();
private:
    Ui::widget *ui;
    QTcpSocket *mSocket;

};
}
#endif // WIDGET_H

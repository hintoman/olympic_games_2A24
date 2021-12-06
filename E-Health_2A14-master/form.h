#ifndef FORM_H
#define FORM_H
#include "afficher.h"


#include <QWidget>
#include <QDialog>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
private slots :
    //void on_pushButton_clicked();
   void on_pushButton_3_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H

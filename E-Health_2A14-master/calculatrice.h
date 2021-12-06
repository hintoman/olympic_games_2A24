#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QDialog>

namespace Ui {
class calculatrice;
}

class calculatrice : public QDialog
{
    Q_OBJECT

public:
    explicit calculatrice(QWidget *parent = nullptr);
    ~calculatrice();
private slots:
    void on_number0_clicked();
    void on_number1_clicked();
    void on_number2_clicked();
    void on_number3_clicked();
    void on_number4_clicked();
    void on_number5_clicked();
    void on_number6_clicked();
    void on_number7_clicked();
    void on_number8_clicked();
    void on_number9_clicked();
    void on_clearBouton_clicked();
    void on_calculBouton_clicked();
    void on_ansBouton_clicked();
    void on_additionnerBouton_clicked();
    void on_diviserBouton_clicked();
    void on_soustraireBouton_clicked();
    void on_multiplierBouton_clicked();
    void on_virguleBouton_clicked();

private:
    Ui::calculatrice *ui;
    float premierNombre;
    QString ansNombre;
    enum Actions {diviser, multiplier, additionner, soustraire};
    Actions action;
};

#endif // CALCULATRICE_H

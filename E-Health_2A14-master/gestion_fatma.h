#ifndef GESTION_FATMA_H
#define GESTION_FATMA_H

#include <QDialog>

namespace Ui {
class gestion_fatma;
}

class gestion_fatma : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_fatma(QWidget *parent = nullptr);
    ~gestion_fatma();

private:
    Ui::gestion_fatma *ui;
};

#endif // GESTION_FATMA_H

#ifndef MODUL_H
#define MODUL_H

#include <QWidget>

namespace Ui {
class MODUL;
}

class MODUL : public QWidget
{
    Q_OBJECT

public:
    explicit MODUL(QWidget *parent = nullptr);
    ~MODUL();

private:
    Ui::MODUL *ui;
};

#endif // MODUL_H

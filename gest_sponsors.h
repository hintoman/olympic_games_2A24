#ifndef GEST_SPONSORS_H
#define GEST_SPONSORS_H

#include <QDialog>

namespace Ui {
class gest_sponsors;
}

class gest_sponsors : public QDialog
{
    Q_OBJECT

public:
    explicit gest_sponsors(QWidget *parent = nullptr);
    ~gest_sponsors();

private:
    Ui::gest_sponsors *ui;
};

#endif // GEST_SPONSORS_H

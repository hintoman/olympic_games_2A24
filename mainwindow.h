#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "transaction.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_valider_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Transaction Etmp;

};

#endif // MAINWINDOW_H
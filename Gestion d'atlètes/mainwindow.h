#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<athlete.h>

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
    void on_pb_Ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_Aaffichier_clicked();

private:
    Ui::MainWindow *ui;
    Athlete A;

};

#endif // MAINWINDOW_H

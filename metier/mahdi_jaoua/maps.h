#ifndef MAPS_H
#define MAPS_H

#include <QMainWindow>
//#include <QWebEngineView>


namespace Ui {
class maps;
}

class maps : public QMainWindow
{
    Q_OBJECT

public:
    explicit maps(QWidget *parent = nullptr);
    ~maps();

private:
    Ui::maps *ui;
  //  QWebEngineView *m_view;

};

#endif // MAPS_H

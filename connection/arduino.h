#ifndef ARDUINO_H
#define ARDUINO_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class arduinoData;

class arduino
{
    Q_OBJECT
public:
    arduino();
    arduino(const arduino &);
    arduino &operator=(const arduino &);
    ~arduino();

private:
    QSharedDataPointer<arduinoData> data;
};

#endif // ARDUINO_H

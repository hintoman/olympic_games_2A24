#include "arduino.h"

class arduinoData : public QSharedData
{
public:

};

arduino::arduino() : data(new arduinoData)
{

}

arduino::arduino(const arduino &rhs) : data(rhs.data)
{

}

arduino &arduino::operator=(const arduino &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

arduino::~arduino()
{

}

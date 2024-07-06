#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "port.h"

class Controller
{
public:
    Controller();
    float analogRead(Port port);
    bool digitalRead(Port port);
    void analogWrite(Port port, float value);
    void digitalWrite(Port port, bool value);
};

#endif // CONTROLLER_H

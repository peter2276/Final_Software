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
    static bool checkPortIsValid(Port port);
};

#endif // CONTROLLER_H

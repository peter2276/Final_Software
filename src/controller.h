#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "port.h"
#include <vector>

class Controller
{
public:
    virtual float analogRead(Port* port) = 0;
    virtual bool digitalRead(Port* port) = 0;
    virtual void analogWrite(Port* port, float value) = 0;
    virtual void digitalWrite(Port* port, bool value) = 0;
    virtual bool checkPortIsValid(Port port) = 0;
    virtual Port* getPort(Port port)=0;
protected:
    static std::vector<Port> digitalPorts;
    static std::vector<Port> analogPorts;
};

#endif // CONTROLLER_H

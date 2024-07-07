#ifndef Light_H
#define Light_H

#include "controller.h"

class Light: public Utility
{
public:
    Light();
    void setActuatorOn(Port port);
    void setActuatorOff(Port port);
    bool getState();
private:
    Port actuator;
    bool state;
};

#endif // Light_H

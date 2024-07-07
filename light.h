#ifndef Light_H
#define Light_H

#include "utility.h"

class Light: public Utility
{
public:
    Light();
    void setPort(Port);
    void setActuatorOn();
    void setActuatorOff();
    bool getState();
private:
    Port actuator;
    bool state;
};

#endif // Light_H

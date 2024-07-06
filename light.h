#ifndef Light_H
#define Light_H

#include "controller.h"

class Light
{
public:
    Light();
    void setActuatorOn(Port port);
    void setActuatorOff(Port port);
    void setController(Controller *board);
    bool getState();
private:
    Controller* board;
    Port actuator;
    bool state;
};

#endif // Light_H

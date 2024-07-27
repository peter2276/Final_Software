#ifndef Light_H
#define Light_H

#include "utility.h"

class Light: public Utility
{
public:
    Light();
    ~Light();
    void setPort(Port P);
    void setActuatorOn();
    void setActuatorOff();
    bool getState();
    void updateState() override;
private:
    Port *actuator;
    bool state;
};

#endif // Light_H

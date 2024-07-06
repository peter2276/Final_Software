#ifndef HEATER_H
#define HEATER_H

#include "controller.h"

class Heater
{
public:
    static Heater* getInstance();
    void setTarget_Temp(int temp);
    void setState(bool state);
    bool getState();
    int getTemp();
    int getTarget_Temp();
    void setSensor(Port port);
    void setActuator(Port port);
    void setController(Controller *board);
protected:
    Heater();
private:
    static Heater* instance;
    Controller* board;
    int Target_Temp;
    Port sensor;
    Port actuator;
    bool state;
};

#endif // HEATER_H

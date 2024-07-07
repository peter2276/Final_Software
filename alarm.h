#ifndef ALARM_H
#define ALARM_H

#include "controller.h"
#include "states.h"
#include <list>
#include <string>

class Alarm: public Utility
{
public:
    static Alarm* getInstance();
    void newSensor(Port port);
    void setActuator(Port port);
    void assembleAlarm();
    void disassembleAlarm();
    void setPassword(std::string password);
protected:
    Alarm();
private:
    std::string password;
    static Alarm* instance;
    std::list<Port> sensors;
    Port actuator;
    StateType state;
};

#endif // ALARM_H

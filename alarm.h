#ifndef ALARM_H
#define ALARM_H

#include "utility.h"
#include <list>
#include <string>

enum StateType {
    ARMED,
    DISARMED,
    ALARM
};

class Alarm: public Utility
{
public:
    static Alarm* getInstance();
    void newSensor(Port port);
    void setActuator(Port port);
    bool toggleAlarm(std::string pass);
    void setPassword(std::string password);
    std::string getState();
protected:
    Alarm();
private:
    bool checkPassword(std::string pass);
    std::string password;
    static Alarm* instance;
    std::list<Port> sensors;
    Port actuator;
    StateType state;
};

#endif // ALARM_H

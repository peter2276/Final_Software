#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H
#include "alarm.h"
#include "controller.h"
#include "light.h"
#include "heater.h"

class SystemManager
{
public:
    static SystemManager* getInstance();
    Alarm * MyAlarm;
    Heater * MyHeater;
    std::list<Light> lights;

protected:
    SystemManager();
private:
    static SystemManager* instance;
};

#endif // SYSTEMMANAGER_H

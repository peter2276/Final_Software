#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H
#include "alarm.h"
#include "controller.h"
#include "light.h"
#include "heater.h"
#include "port.h"

class SystemManager
{
public:
    static SystemManager* getInstance();
    Alarm * MyAlarm;
    Heater * MyHeater;
    std::list<Light> lights;
    CreateAlarm(Controller*, Port);
    CreateHeater(Controller*, Port);
    CreateLight(Controller*, Port);

protected:
    SystemManager();
private:
    static SystemManager* instance;
};

#endif // SYSTEMMANAGER_H

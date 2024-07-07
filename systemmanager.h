#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <list>
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
    void CreateAlarm(Port);
    void CreateHeater(Port act, Port sensor);
    void CreateLight(Port);
    void CreateController();

protected:
    SystemManager();
private:
    Controller* board;
    static SystemManager* instance;
};

#endif // SYSTEMMANAGER_H

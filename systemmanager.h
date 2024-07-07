#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <list>
#include "alarm.h"
#include "controller.h"
#include "light.h"
#include "heater.h"
#include "port.h"
#include <string>

class SystemManager
{
public:
    static SystemManager* getInstance();

    void CreateAlarm(Port act);
    void AddSensor(Port sensor);
    bool SetPassword(std::string pass);
    bool ToggleAlarm(std::string pass);
    std::string CheckAlarm();

    void CreateHeater(Port act, Port sensor);
    void SetTemp(int temp);
    int GetTemp();
    void ToggleHeater();
    bool GetHeaterState();

    void CreateLight(Port);
    void LightOn(int id);
    void LightOff(int id);
    bool GetLightState(int id);

    void CreateController();

protected:
    SystemManager();
private:
    Alarm * MyAlarm;
    Heater * MyHeater;
    std::list<Light> lights;
    Controller* board;
    static SystemManager* instance;
};

#endif // SYSTEMMANAGER_H

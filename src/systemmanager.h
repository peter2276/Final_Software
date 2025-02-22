#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <list>
#include "alarm.h"
#include "arduinouno.h"
#include "light.h"
#include "heater.h"
#include "port.h"
#include <string>
#include <iterator>

class SystemManager
{
public:
    static SystemManager* getInstance();

    bool CreateAlarm(std::string port);
    bool AddSensor(std::string port);
    bool SetPassword(std::string pass, std::string newpass);
    bool ToggleAlarm(std::string pass);
    std::string CheckAlarm();

    bool CreateHeater(std::string port_act, std::string port_sensor);
    void SetTemp(int temp);
    int GetTemp();
    void ToggleHeater();
    bool GetHeaterState();

    bool CreateLight(std::string port);
    bool DeleteLight(int id);
    void LightOn(int id);
    void LightOff(int id);
    bool GetLightState(int id);

    void CreateController();
    void updateUtilities();

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

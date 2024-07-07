#include "systemmanager.h"

SystemManager* SystemManager::instance = 0;

SystemManager::SystemManager() {}

SystemManager* SystemManager::getInstance(){
    if (instance == 0){
        instance = new SystemManager;
    }
    return instance;
}

void SystemManager::CreateAlarm(Controller*, Port){
    //MyAlarm = Alarm::getInstance();
}
void SystemManager::CreateHeater(Controller* board, Port act,Port sensor ){
    MyHeater = Heater::getInstance();
    MyHeater->setController(board);
    MyHeater->setActuator(act);
    MyHeater->setSensor(sensor);
}
void SystemManager::CreateLight(Controller*, Port P){
    /*
    l = new light;
    l.setPort(P);
    lights.push_front(l);
    */
}

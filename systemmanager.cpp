#include "systemmanager.h"

SystemManager* SystemManager::instance = 0;

SystemManager::SystemManager() {}

SystemManager* SystemManager::getInstance(){
    if (instance == 0){
        instance = new SystemManager;
    }
    return instance;
}

void SystemManager::CreateAlarm(Port P){
    MyAlarm = Alarm::getInstance();
    MyAlarm->setContoller(this->board);
    MyAlarm->setActuator(P);
}
void SystemManager::CreateHeater(Port act,Port sensor ){
    MyHeater = Heater::getInstance();
    MyHeater->setController(this->board);
    MyHeater->setActuator(act);
    MyHeater->setSensor(sensor);
}
void SystemManager::CreateLight(Port P){

    l = new light;
    l.setPort(P);
    l.secController(this->board);
    lights.push_front(l);

}

void SystemManager::CreateController(){
    if (board==NULL){
        board = new Controller;
    }
}

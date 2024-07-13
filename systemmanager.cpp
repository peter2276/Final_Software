#include "systemmanager.h"

SystemManager* SystemManager::instance = 0;

SystemManager::SystemManager() {}
SystemManager* SystemManager::getInstance(){
    if (instance == 0){
        instance = new SystemManager;
    }
    return instance;
}

bool SystemManager::CreateAlarm(std::string port){
    Port P(port);
    if (Controller::checkPortIsValid(P)){
        MyAlarm = Alarm::getInstance();
        MyAlarm->setController(this->board);
        MyAlarm->setActuator(P);
        return 1;
    }
    else
        return 0;
}

bool SystemManager::AddSensor(std::string port){
    Port sensor(port);
    if (Controller::checkPortIsValid(sensor)){
        MyAlarm->newSensor(sensor);
        return 1;
    }
    else
        return 0;
}

bool SystemManager::SetPassword(std::string pass, std::string newpass){
    return MyAlarm->setPassword(pass,newpass);
}

bool SystemManager::ToggleAlarm(std::string pass){
    return MyAlarm->toggleAlarm(pass);
}

std::string SystemManager::CheckAlarm(){
    return MyAlarm->getState();
}

bool SystemManager::CreateHeater(std::string port_act, std::string port_sensor){
    Port act(port_act);
    Port sensor(port_sensor);
    if (Controller::checkPortIsValid(act) && Controller::checkPortIsValid(sensor)){
        MyHeater = Heater::getInstance();
        MyHeater->setController(this->board);
        MyHeater->setActuator(act);
        MyHeater->setSensor(sensor);
        return 1;
    }
    else
        return 0;
}

void SystemManager::SetTemp(int temp){
    MyHeater->setTarget_Temp(temp);
}

int SystemManager::GetTemp(){
    return MyHeater->getTemp();
}

void SystemManager::ToggleHeater(){
    if(MyHeater->getState()){
        MyHeater->setState(0);
    }
    else{
        MyHeater->setState(1);
    }
}

bool SystemManager::GetHeaterState(){
    return MyHeater->getState();
}

bool SystemManager::CreateLight(std::string port){
    Port P(port);
    if (Controller::checkPortIsValid(P)){
        auto l = new Light;
        l->setPort(P);
        l->setController(this->board);
        lights.push_back(*l);
        return 1;
    }
    else
        return 0;
}

void SystemManager::LightOn(int id){
    if(lights.size() > id && id >= 0){
        auto it =lights.begin();
        std::advance(it, id);
        it->setActuatorOn();
    }
}

void SystemManager::LightOff(int id){
    if(lights.size() > id && id >= 0){
        auto it =lights.begin();
        std::advance(it, id);
        it->setActuatorOff();
    }
}

bool SystemManager::GetLightState(int id){
    if(lights.size() > id && id >= 0){
        auto it =lights.begin();
        std::advance(it, id);
        return it->getState();
    }
    else
        return 0;
}

void SystemManager::CreateController(){
    if (board==NULL){
        board = new Controller;
    }
}

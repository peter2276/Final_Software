#include "systemmanager.h"

#include <iostream>

SystemManager* SystemManager::instance = 0;

SystemManager::SystemManager(){
    this->MyHeater = nullptr;
    this->MyAlarm = nullptr;
}

SystemManager* SystemManager::getInstance(){
    if (instance == 0){
        instance = new SystemManager;
    }
    return instance;
}

bool SystemManager::CreateAlarm(std::string port){
    Port P(port);
    if (this->board->checkPortIsValid(P)){
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
    if (this->board->checkPortIsValid(sensor)){
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
    if (this->MyAlarm != nullptr)
        return MyAlarm->getState();
    else
        return " ";
}

bool SystemManager::CreateHeater(std::string port_act, std::string port_sensor){
    Port act(port_act);
    Port sensor(port_sensor);
    if (this->board->checkPortIsValid(act) && this->board->checkPortIsValid(sensor)){
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
    if (this->MyHeater != nullptr)
        return MyHeater->getTemp();
    else
        return 0;
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
    if (this->MyHeater != nullptr)
        return MyHeater->getState();
    else
        return 0;
}

bool SystemManager::CreateLight(std::string port){
    Port P(port);
    if (this->board->checkPortIsValid(P)){
        auto l = new Light;
        l->setController(this->board);
        l->setPort(P);
        lights.push_back(*l);
        return 1;
    }
    else
        return 0;
}

bool SystemManager::DeleteLight(int id){
    //Buscar lampara
    //Eliminar lampara
    if(lights.size() > id && id >= 0){
        auto it =lights.begin();
        std::advance(it, id);
        it->setActuatorOff();
        lights.erase(it);
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
        board = new ArduinoUNO;
    }
}

void SystemManager::updateUtilities(){
    if (this->MyAlarm != nullptr)
        this->MyAlarm->updateState();
    if (this->MyHeater != nullptr)
        this->MyHeater->updateState();
}

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
    MyAlarm->setController(this->board);
    MyAlarm->setActuator(P);
}
void SystemManager::AddSensor(Port sensor){
    MyAlarm->newSensor(sensor);
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

void SystemManager::CreateHeater(Port act,Port sensor ){
    MyHeater = Heater::getInstance();
    MyHeater->setController(this->board);
    MyHeater->setActuator(act);
    MyHeater->setSensor(sensor);
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
    return MyHeater->();
}

void SystemManager::CreateLight(Port P){
    l = new Light;
    l.setPort(P);
    l.setController(this->board);
    lights.push_back(l);
}
void SystemManager::LightOn(int id){
    if(lights.size() > id && id >= 0){
        auto it = std::advance(lights.begin(), id);
        it->setActuatorOn();
    }
}
void SystemManager::LightOff(int id){
    if(lights.size() > id && id >= 0){
        auto it = std::advance(lights.begin(), id);
        it->setActuatorOff();
    }
}
bool SystemManager::GetLightState(int id){
    if(lights.size() > id && id >= 0){
        auto it = std::advance(lights.begin(), id);
        return it->getState();
    }
    return 0;
}

void SystemManager::CreateController(){
    if (board==NULL){
        board = new Controller;
    }
}

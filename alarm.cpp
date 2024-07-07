#include "alarm.h"

Alarm* Alarm::instance = 0;

Alarm::Alarm(){

}

Alarm* Alarm::getInstance(){
    if (instance == 0){
        instance = new Alarm;
    }
    return instance;
}

void Alarm::newSensor(Port port){
    this->sensors.push_back(port);
}

void Alarm::setActuator(Port port){
    this->actuator = port;
}

void Alarm::assembleAlarm(){
    this->state = StateType::ARMED;
}

void Alarm::disassembleAlarm(){
    this->state = StateType::DISARMED;
}

void Alarm::setPassword(std::string password){
    this->password = password;
}

std::string Alarm::getState(){
    if (this->state == StateType::ARMED){
        return "ARMED";
    }
    else if (this->state == StateType::DISARMED){
        return "DISARMED";
    }
    else if (this->state == StateType::ALARM){
        return "ALARM";
    }
    else
        return "ERROR";
}

bool Alarm::checkPassword(std::string password){
    return this->password == password;
}


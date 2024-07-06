#include "heater.h"

Heater* Heater::instance = 0;

Heater::Heater(){

}

Heater* Heater::getInstance(){
    if (instance == 0){
        instance = new Heater;
    }
    return instance;
}

void Heater::setTarget_Temp(int temp){
    this->Target_Temp = temp;
}

void Heater::setState(bool state){
    this->state = state;
}

bool Heater::getState(){
    return this->state;
}

int Heater::getTemp(){
    return int(board->analogRead(sensor));
}

int Heater::getTarget_Temp(){
    return this->Target_Temp;
}

void Heater::setSensor(Port port){
    this->sensor = port;
}

void Heater::setActuator(Port port){
    this->actuator = port;
}

void Heater::setController(Controller *board){
    this->board = board;
}

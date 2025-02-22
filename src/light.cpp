#include "light.h"

Light::Light(){
    state = 0;
}
Light::~Light(){
    this->actuator->setState(0);
}
void Light::setPort(Port P){
    this->actuator=this->board->getPort(P);
}
void Light::setActuatorOn(){
    if (state == 0){
        this->board->digitalWrite(this->actuator,1);
        this->state = 1;
    }
}

void Light::setActuatorOff(){
    if (state == 1){
        this->board->digitalWrite(this->actuator,0);
        this->state = 0;
    }
}

bool Light::getState(){
    return this->state;
}

void Light::updateState(){
    this->board->digitalWrite(this->actuator, this->state);
}

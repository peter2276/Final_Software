#include "light.h"

Light::Light(){
    state = 0;
}

void Light::setActuatorOn(Port port){
    if (state == 0){
        this->board->digitalWrite(port,1);
        this->state = 1;
    }
}

void Light::setActuatorOff(Port port){
    if (state == 1){
        this->board->digitalWrite(port,0);
        this->state = 0;
    }
}

bool Light::getState(){
    return this->state;
}

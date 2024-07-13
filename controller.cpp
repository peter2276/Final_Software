#include "controller.h"

Controller::Controller(){

}

float Controller::analogRead(Port port){
    return 0; // stubbed
}

bool Controller::digitalRead(Port port){
    return 0; // stubbed
}

void Controller::analogWrite(Port port, float value){
    return; // stubbed
}

void Controller::digitalWrite(Port port, bool value){
    return; // stubbed
}

bool Controller::checkPortIsValid(Port port){
    return 1; // stubbed
}

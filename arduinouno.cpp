#include "arduinouno.h"

ArduinoUNO::ArduinoUNO() {
    std::string analog = "A";
    std::string digital = "D";
    for (int i = 0; i <= 5; i++){
        Port port(analog + std::to_string(i));
        analogPorts.push_back(port);
    }
    for (int i = 0; i <= 13; i++){
        Port port(digital + std::to_string(i));
        digitalPorts.push_back(port);
    }
}

std::vector<Port> ArduinoUNO::digitalPorts;

std::vector<Port> ArduinoUNO::analogPorts;

float ArduinoUNO::analogRead(Port port){
    return 0; // stubbed
}

bool ArduinoUNO::digitalRead(Port port){
    return 0; // stubbed
}

void ArduinoUNO::analogWrite(Port port, float value){
    return; // stubbed
}

void ArduinoUNO::digitalWrite(Port port, bool value){
    return; // stubbed
}

bool ArduinoUNO::checkPortIsValid(Port port){
    for (int i = 0; i < analogPorts.size(); i++){
        if (analogPorts[i] == port)
            return 1;
    }
    for (int i = 0; i < digitalPorts.size(); i++){
        if (digitalPorts[i] == port)
            return 1;
    }
    return 0;
}

std::vector<Port> ArduinoUNO::getAvailableDigitalPorts(){
    std::vector<Port> available (digitalPorts);
    for (int i = 0; i < available.size(); i++){
        if (available[i].getState()){
            available.erase(available.begin() + i);
        }
    }
    return available;
}

std::vector<Port> ArduinoUNO::getAvailableAnalogPorts(){
    std::vector<Port> available (analogPorts);
    for (int i = 0; i < available.size(); i++){
        if (available[i].getState()){
            available.erase(available.begin() + i);
        }
    }
    return available;
}

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

float ArduinoUNO::analogRead(Port* port){
    return 0; // stubbed
}

bool ArduinoUNO::digitalRead(Port* port){
    return 0; // stubbed
}

void ArduinoUNO::analogWrite(Port* port, float value){
    return; // stubbed
}

void ArduinoUNO::digitalWrite(Port* port, bool value){
    return; // stubbed
}

bool ArduinoUNO::checkPortIsValid(Port port){
    for (int i = 0; i < analogPorts.size(); i++){
        if (analogPorts[i] == port && !analogPorts[i].getState())
            return 1;
    }
    for (int i = 0; i < digitalPorts.size(); i++){
        if (digitalPorts[i] == port && !digitalPorts[i].getState())
            return 1;
    }
    return 0;
}
Port* ArduinoUNO::getPort(Port port){
    bool valid=0;
    Port* p=NULL;
    valid=this->checkPortIsValid(port);
    if(valid){
        for (int i = 0; i < analogPorts.size(); i++){
            if (analogPorts[i] == port){
                p=&analogPorts[i];
                analogPorts[i].setState(1);
            }
        }
        for (int i = 0; i < digitalPorts.size(); i++){
            if (digitalPorts[i] == port){
                p=&digitalPorts[i];
                digitalPorts[i].setState(1);
            }
        }
    }
    return p;
}

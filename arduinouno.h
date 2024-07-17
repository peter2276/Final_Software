#ifndef ARDUINOUNO_H
#define ARDUINOUNO_H

#include "controller.h"

class ArduinoUNO: public Controller
{
public:
    ArduinoUNO();
    float analogRead(Port port) override;
    bool digitalRead(Port port) override;
    void analogWrite(Port port, float value) override;
    void digitalWrite(Port port, bool value) override;
    bool checkPortIsValid(Port port) override;
    static std::vector<Port> digitalPorts;
    static std::vector<Port> analogPorts;
};

#endif // ARDUINOUNO_H

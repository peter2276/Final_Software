#include "port.h"

Port::Port(std::string port_){
    port = port_;
    used = 0;
}

void Port::setState(bool state){
    this->used = state;
}

Port::Port() {}

bool Port::getState(){
    return this->used;
}

std::string Port::getPort(){
    return this->port;
}

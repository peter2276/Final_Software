#include "port.h"

Port::Port(std::string port_) {
    port = port_;
    used=0;
}

Port::Port() {}

void Port::setState(bool state){
    this->used = state;
}

bool Port::getState(){
    return this->used;
}

std::string Port::getPort(){
    return this->port;
}

void Port::setPort(std::string port_){
    this->port = port_;
}

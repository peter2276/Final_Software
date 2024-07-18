#include "alarm.h"

Alarm* Alarm::instance = 0;

Alarm::Alarm(){
    state = StateType::DISARMED;
    password = "1234";
}
Alarm::~Alarm(){
    this->actuator->setState(0);
}

Alarm* Alarm::getInstance(){
    if (instance == 0){
        instance = new Alarm;
    }
    return instance;
}

void Alarm::newSensor(Port port){
    this->sensors.push_back(this->board->getPort(port));
}

bool Alarm::deleteSensor(int id){
    Port * p;
    if(this->sensors.size() > id && id >= 0){
        std::_List_iterator<Port*> it =this->sensors.begin();
        std::advance(it, id);
        //it->(setState(0));
        p=*it;
        p->setState(0);
        this->sensors.erase(it);
        return 1;
    }
    else
        return 0;
}


void Alarm::setActuator(Port port){
    this->actuator = this->board->getPort(port);
}

bool Alarm::toggleAlarm(std::string pass){
    if (this->checkPassword(pass)){
        if (this->state == StateType::ARMED || this->state == StateType::ALARM){
            this->state = StateType::DISARMED;
        }
        else if (this->state == StateType::DISARMED){
            this->state = StateType::ARMED;
        }
        return 1;
    }
    else
        return 0;
}

bool Alarm::setPassword(std::string Actualpassword,std::string Newpassword){
    if(this->checkPassword(Actualpassword)){
        this->password = Newpassword;
        return 1;
    }
    else return 0;
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


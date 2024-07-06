#ifndef HEATER_H
#define HEATER_H

class Heater
{
public:
    static Heater* getInstance();
protected:
    Heater();
private:
    static Heater* instance;
};

#endif // HEATER_H

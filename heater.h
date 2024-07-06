#ifndef HEATER_H
#define HEATER_H

class Heater
{
public:
    Heater();
    static Heater* getInstance();
protected:
    Heater();
private:
    static Heater* instance;
};

#endif // HEATER_H

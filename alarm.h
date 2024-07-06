#ifndef ALARM_H
#define ALARM_H

class Alarm
{
public:
    static Alarm* getInstance();
protected:
    Alarm();
private:
    static Alarm* instance;
};

#endif // ALARM_H

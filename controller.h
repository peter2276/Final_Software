#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    static Controller* getInstance();
protected:
    Controller();
private:
    static Controller* instance;
};

#endif // CONTROLLER_H

#ifndef UTILITY_H
#define UTILITY_H
#include "controller.h"

class Utility
{
public:
    Utility();
    void setController(Controller *board);
    virtual void updateState() = 0;
protected:
    Controller* board;
};

#endif // UTILITY_H

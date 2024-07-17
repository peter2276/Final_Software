#ifndef PORT_H
#define PORT_H
#include <string>

class Port
{
public:
    Port(std::string port_);
    Port();
    std::string port;
    bool operator==(const Port& other) const {
        return this->port == other.port;
    }
};

#endif // PORT_H

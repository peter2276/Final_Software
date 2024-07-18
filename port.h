#ifndef PORT_H
#define PORT_H
#include <string>

class Port
{
public:
    Port(std::string port_);
    Port();
    bool operator==(const Port& other) const {
        return this->port == other.port;
    }
    bool getState();
    void setState(bool state);
    std::string getPort();
private:
    std::string port;
    bool used;
};

#endif // PORT_H

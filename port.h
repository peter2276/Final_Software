#ifndef PORT_H
#define PORT_H
#include <string>

class Port
{
public:
    Port(std::string port_);
    Port();
    void setPort(std::string port_);
    std::string getPort();
    void setState(bool state);
    bool getState();
    bool operator==(const Port& other) const {
        return this->port == other.port;
    }
private:
    std::string port;
    bool used;
};

#endif // PORT_H

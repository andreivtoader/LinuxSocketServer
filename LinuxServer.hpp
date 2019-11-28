#pragma once

#include <string>
#include "Socket.hpp"

class LinuxServer
{
public:
    explicit LinuxServer(const std::string& address);
    ~LinuxServer();

    void Start();

private:
    std::string _IPv4Address;
    unsigned int _port;
    
    Socket _socket;
};



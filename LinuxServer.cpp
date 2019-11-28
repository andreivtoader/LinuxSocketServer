#include "LinuxServer.hpp"

#include <iostream>

LinuxServer::LinuxServer(const std::string& address)
: _IPv4Address(address)
, _port(27015)
, _socket()
{
}

LinuxServer::~LinuxServer()
{
}

void LinuxServer::Start()
{
    _socket.InitializeSocketStructure(_IPv4Address, _port);
    _socket.StartListening();
    _socket.StartCommunicating();
}

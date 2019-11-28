#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <string>


class Socket
{
public:
    Socket();
    ~Socket();

    void InitializeSocketStructure(const std::string& address, unsigned int port);
    void StartListening();
    void StartCommunicating();

private:
    const unsigned int _numberOfConnections = 5;

    int _socketFD = -1;
    struct sockaddr_in _serverAddress;

    int _newSockedFD = -1;
    struct sockaddr_in _clientAddress;
    socklen_t _clientLength = 0;

    void Open();
    void Close();
};



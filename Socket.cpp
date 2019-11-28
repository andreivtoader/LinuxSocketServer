#include "Socket.hpp"

#include <iostream>

Socket::Socket()
{
    Open();
}

Socket::~Socket()
{
    Close();
}

void Socket::Open()
{
    _socketFD = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Socket file descriptor: " << _socketFD << std::endl;
    
    if(_socketFD >= 0)
    {
        std::cout << "Opened socked successfully..." << std::endl;
    }
    else
    {
        std::cout << "ERROR opening socket..." << std::endl;
        std::exit(1);
    }
}

void Socket::Close()
{
    close(_socketFD);
    close(_newSockedFD);
}

void Socket::InitializeSocketStructure(const std::string& address, unsigned int port)
{
    bzero((char *) &_serverAddress, sizeof(_serverAddress));
    
    _serverAddress.sin_family = AF_INET;
    _serverAddress.sin_addr.s_addr = inet_addr(address.c_str());;
    _serverAddress.sin_port = htons(port);

    int errorCode = bind(_socketFD, (struct sockaddr *) &_serverAddress, sizeof(_serverAddress));

    if(errorCode >= 0)
    {
        std::cout << "Binded the host address succesfully..." << std::endl;
    }
    else
    {
        std::cout << "ERROR on binding the socket..." << std::endl;
        std::exit(errorCode);
    }
}

void Socket::StartListening()
{
    listen(_socketFD, _numberOfConnections);
    
    _clientLength = sizeof(_clientAddress);
    _newSockedFD = accept(_socketFD, (struct sockaddr *)&_clientAddress, 
                        &_clientLength);

    if(_newSockedFD >= 0)
    {
        std::cout << "Accepting connections successfully..." << std::endl;
    }
    else
    {
        std::cout << "ERROR on accepting connections from the client..." << std::endl;
        std::exit(1);
    }
}

void Socket::StartCommunicating()
{
    std::cout << "Connection is established, now starting to communicate..." << std::endl;
    
    const std::string hello = "Echo reply...";
    char buffer[1024] = {0};
    
    int valRead = read( _newSockedFD , buffer, 1024);
    if(valRead >= 0)
    {
        std::cout << "Client sent: " << buffer << std::endl;
    }
    else
    {
        std::cout << "ERROR reading from socket..." << std::endl;
        std::exit(1);
    }
    
    int valSend = send(_newSockedFD , hello.c_str() , hello.size() , 0);
    if(valRead >= 0)
    {
        std::cout << "Server reply message sent" << std::endl;
    }
    else
    {
        std::cout << "ERROR sending to socket..." << std::endl;
        std::exit(1);
    }
}
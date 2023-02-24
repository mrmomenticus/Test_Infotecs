#ifndef SOCKET_H
#define SOCKET_H
#include <arpa/inet.h>
#include <iostream>
#include <string.h>

using std::cout;

class Socket
{
    const int c_port = 3425;
    int sock;
    struct sockaddr_in socket_addr;



public:
    Socket();
    void receive();
    void connection();
};

#endif // SOCKET_H

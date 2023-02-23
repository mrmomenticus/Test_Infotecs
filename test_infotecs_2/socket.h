#ifndef SOCKET_H
#define SOCKET_H
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
class Socket
{
    struct sockaddr_in socket_addr;
    int sock;
    const int c_port = 8888;

public:
    Socket();
    void receive();
    void connection();
};

#endif // SOCKET_H

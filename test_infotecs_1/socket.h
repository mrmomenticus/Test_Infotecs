#ifndef SOCKET_H
#define SOCKET_H
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <cstring>

using std::cout;

class Socket
{
    const int c_port = 3425;
    int sock;
    struct sockaddr_in socket_addr;

public:
    Socket();
    void sendBuffer(int sum);
    void connection();
};

#endif // SOCKET_H

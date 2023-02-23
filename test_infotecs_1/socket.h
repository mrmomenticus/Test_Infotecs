#ifndef SOCKET_H
#define SOCKET_H
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include "stdlib.h"
class Socket
{
    const int c_port = 8888;
    struct sockaddr_in socket_addr;
    int sock;
public:
    Socket();
    void sendBuffer(int sum);
    void connection();
};

#endif // SOCKET_H

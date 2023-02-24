#include "socket.h"

Socket::Socket()
{
}
void Socket::connection(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        cout << strerror(errno)<<std::endl;
        exit(0);
    }
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_port = htons(c_port);
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(connect(sock, (struct sockaddr *)&socket_addr, sizeof(socket_addr)) < 0)
    {
        cout << strerror(errno)<<std::endl;
        exit(0);
    };
}
void Socket::sendBuffer(int sum){

    char buffer[256];
    std::string tmp = std::to_string(sum);
    memset(buffer, 0, 256);
    strcpy(buffer, tmp.c_str());
    send(sock, buffer, 256, MSG_NOSIGNAL);
    shutdown(sock, SHUT_WR);
}

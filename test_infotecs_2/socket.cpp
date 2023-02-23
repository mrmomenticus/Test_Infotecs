#include "socket.h"

Socket::Socket()
{
}
void Socket::connection(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        std::cout << "Error socket!";
    }
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_port = htons(3425);
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sock, (struct sockaddr *)&socket_addr, sizeof(socket_addr)) < 0 ){
        std::cout << "Error bind!";
    }
    if(listen(sock, 3) < 0){
        std::cout << "Error listen!";
    }






}
void Socket::receive(){
    while(true){
        int socket_accept = accept(sock, nullptr, nullptr);
        if(socket_accept < 0){
            std::cout << "accept error";
        }
        char buffer[256];
        memset(buffer, 0, 256);
        if(recv(socket_accept, buffer, 256, MSG_NOSIGNAL) < 0){ //попробовать передать чисто стринг c_str;
            std::cout << strerror(errno);
        }
        std::string tmp(buffer, sizeof(buffer));

        int sum = std::stoi(tmp);
        if(sum > 99 && sum % 32==0){
            std::cout << "Corret" << std::endl;

        }
        else{
            std::cout << "Error" << std::endl;
        }
        shutdown(socket_accept, SHUT_RDWR);
    };
}

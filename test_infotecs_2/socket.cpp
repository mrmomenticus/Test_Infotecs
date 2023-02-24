#include "socket.h"

Socket::Socket()
{
}
void Socket::connection(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        cout << strerror(errno)<<std::endl;
        exit(0);
    }
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_port = htons(c_port);
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sock, (struct sockaddr *)&socket_addr, sizeof(socket_addr)) < 0 ){//исключение
        cout << strerror(errno)<<std::endl;
        exit(0);
    }
    if(listen(sock, 3) < 0){//исключение
        cout << strerror(errno)<<std::endl;
        exit(0);
    }
}
void Socket::receive(){
    while(true){
        int socket_accept = accept(sock, nullptr, nullptr);
        if(socket_accept < 0){
            cout << strerror(errno)<<std::endl;
        }
        char buffer[256];
        memset(buffer, 0, 256);
        if(recv(socket_accept, buffer, 256, MSG_NOSIGNAL) < 0){
            cout << strerror(errno)<<std::endl;
        }
        int sum = std::atoi(buffer);
        if(sum > 99 && sum % 32==0){
            cout << "Corret date!" << std::endl;
        }
        else{
            cout << "Error date!" << std::endl;
        }
        shutdown(socket_accept, SHUT_RDWR);//посмотреть другие варианты закрытия сокета
    };
}

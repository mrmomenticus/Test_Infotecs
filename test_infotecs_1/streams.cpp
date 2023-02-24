#include "streams.h"


Streams::Streams()
{

}
void Streams::oneStream(){
    while(true){
        std::string user;
        std::getline(std::cin, user);
        if(format.stringChecking(user)){
            throw std::invalid_argument("Error date input!");
        }
        std::sort(user.begin(), user.end(), std::greater<char>());
        format.stringFormatting(user);
        std::unique_lock<std::mutex> ulm(mtx);
        buffer.swap(user);
        cv.notify_one();
    }

}
void Streams::twoStream(){
    while(true){
        int sum = 0;
        std::unique_lock<std::mutex> ulm(mtx);
        cv.wait(ulm, [this]{return !this->buffer.empty();});
        cout << buffer << std::endl;
        socket.connection();
        socket.sendBuffer(format.sum(buffer));
        buffer.clear();
    }
}

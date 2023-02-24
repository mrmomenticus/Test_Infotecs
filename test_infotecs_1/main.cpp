#include "streams.h"
#include <iostream>
#include <thread>

int main()
{

    Streams streams;
    std::thread t1([&streams](){ //проверить многопточность
        streams.oneStream();
    });
    std::thread t2([&streams](){
        streams.twoStream();
    });
    t1.join();
    t2.join();


}

#ifndef STREAMS_H
#define STREAMS_H
#include <string>
#include <iostream>
#include <mutex>
#include <algorithm>
#include <condition_variable>
#include "stringprocessing.h"
#include "socket.h"

using std::cout;

class Streams
{
    Socket socket;
    StringProcessing format;

    std::mutex mtx;    
    std::condition_variable cv;

    std::string buffer;


public:
    Streams();
    void oneStream();
    void twoStream();
};

#endif // STREAMS_H

#ifndef STREAMS_H
#define STREAMS_H
#include <string>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include "stringprocessing.h"
#include "socket.h"
class Streams
{
    StringProcessing format;
    std::mutex mtx;
    std::condition_variable cv;
    std::string buffer;
    Socket socket;

public:
    Streams();
    void oneStream();
    void twoStream();
};

#endif // STREAMS_H

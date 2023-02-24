#ifndef STRINGPROCESSING_H
#define STRINGPROCESSING_H
#include <string>



class StringProcessing
{
public:
    StringProcessing();
    bool stringChecking(const std::string &str);
    void stringFormatting(std::string &str);
    int sum(const std::string &str);
};

#endif // STRINGPROCESSING_H

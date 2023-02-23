#include "stringprocessing.h"

StringProcessing::StringProcessing()
{

}
bool StringProcessing::stringChecking(const std::string &str){
    int len {0};
    if(str.empty()){
        return true;
    }
    for(const auto &i:str){
        if(!std::isdigit(i)){
            return true;
        };
        len++;
    }
    return (len>64);
}

void StringProcessing::stringFormatting(std::string &str){ //подумать через итератор

    std::string format;
    for(const auto &i : str){
        std::string tmp;
        tmp += i;
        if(std::stoi(tmp) % 2  == 0){
            format += "KB";
        }
        else{
            format += i;
        }
    }
    str.swap(format);
}

int StringProcessing::sum(const std::string &str){
    int sum = 0;
    for (const auto &i : str)
    {
        if (std::isdigit(i))
        {
            std::string tmp;
            tmp += i;
            sum += std::stoi(tmp);
        }
    }
    return sum;
}



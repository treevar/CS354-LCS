#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>
#include "Timer.h"

std::string promptForStr(const std::string &prompt){
    std::cout << prompt << ": ";
    std::string str{};
    std::getline(std::cin, str);
    return str;
}

#endif //UTIL_H
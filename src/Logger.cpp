#include "Logger.h"
#include <iostream>

void Logger::log(const std::string& text)
{
    std::cout << "[LOG] " << text << std::endl;
}
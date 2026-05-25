#ifndef UTILS_H
#define UTILS_H

#include <thread>
#include <chrono>

inline void delay(int ms)
{
    std::this_thread::sleep_for(
        std::chrono::milliseconds(ms)
    );
}

#endif
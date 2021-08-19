#include <chrono>
#include "api/Common.h"
#include "utils.h"
#include <thread>

static std::chrono::steady_clock::time_point const millis_begin = std::chrono::steady_clock::now();

unsigned long millis()
{
    std::chrono::steady_clock::time_point millis_now = std::chrono::steady_clock::now();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(millis_now - millis_begin).count();
    return static_cast<unsigned long>(millis);
}

void delay(unsigned long ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void delayMicroseconds(unsigned int us)
{
    delay(us / 1000 + 1);
}

void yield()
{
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <Arduino.h>
#include <pigpiod_if2.h>

int main()
{
    randomSeed(millis());

    setup();
    while (true)
    {
        loop();
    }
}

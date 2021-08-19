#pragma once
#include "Arduino.h"
#include "api/HardwareSerial.h"

namespace arduino
{
    class Console : public HardwareSerial
    {
    public:
        void begin(unsigned long)
        {
        }
        void begin(unsigned long baudrate, uint16_t config)
        {
        }
        void end()
        {
        }
        int available(void)
        {
            return 0;
        }
        int peek(void)
        {
            return 0;
        }
        int read(void)
        {
            return 0;
        }
        void flush(void)
        {
            fflush(stdout);
        }
        size_t write(uint8_t c)
        {
            // printf("%c", c);
            return putchar(c);
            // return 1;
        }
        size_t write(const uint8_t *data, size_t length)
        {
            return fwrite(data, length, 1, stdout);
        }
        operator bool()
        {
            return true;
        }
    };
}

extern arduino::Console _Console;
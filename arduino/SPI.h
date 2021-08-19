#pragma once

#include "Arduino.h"
#include "api/HardwareSPI.h"
#include "PiGpio.h"

namespace arduino
{
    class SPIPI : public SPIClass
    {
    public:
        SPIPI()
        {
        }

        SPIPI(int miso, int mosi, int sck)
        {
        }

        virtual void begin()
        {
            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return;
            }
            pig->spi_begin();
        }

        virtual void end()
        {
            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return;
            }
            pig->spi_end();
        }

        virtual uint8_t transfer(uint8_t data)
        {
            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return 0;
            }
            uint8_t result = 0;
            pig->spi_transfer(&data, &result, sizeof(data));
            return result;
        }

        virtual uint16_t transfer16(uint16_t data)
        {
            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return 0;
            }
            uint16_t result = 0;
            pig->spi_transfer((uint8_t *)&data, (uint8_t *)&result, sizeof(data));
            return result;
        }

        virtual void transfer(void *buf, size_t count)
        {
            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return;
            }
            uint8_t result = 0;
            pig->spi_transfer((uint8_t *)buf, (uint8_t *)buf, count);
        }

        void write(uint8_t *input, uint32_t count)
        {
            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return;
            }
            uint8_t result = 0;
            pig->spi_write(input, count);
        }

        virtual void usingInterrupt(int interruptNumber)
        {
        }

        virtual void notUsingInterrupt(int interruptNumber)
        {
        }

        virtual void beginTransaction(SPISettings settings)
        {
        }

        virtual void endTransaction(void)
        {
        }

        virtual void attachInterrupt()
        {
        }

        virtual void detachInterrupt()
        {
        }

    private:
        SPISettings settings = SPISettings(0, MSBFIRST, SPI_MODE0);
    };

}

extern arduino::SPIPI SPI;
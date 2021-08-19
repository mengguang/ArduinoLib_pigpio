#pragma once

#include "Arduino.h"
#include "api/HardwareSPI.h"

namespace arduino
{

    class FT232HSPI : public SPIClass
    {
    public:
        FT232HSPI();
        FT232HSPI(int miso, int mosi, int sck);
        virtual uint8_t transfer(uint8_t data);
        virtual uint16_t transfer16(uint16_t data);
        virtual void transfer(void *buf, size_t count);
        void write(uint8_t *input, uint32_t count);

        // Transaction Functions
        virtual void usingInterrupt(int interruptNumber);
        virtual void notUsingInterrupt(int interruptNumber);
        virtual void beginTransaction(SPISettings settings);
        virtual void endTransaction(void);

        // SPI Configuration methods
        virtual void attachInterrupt();
        virtual void detachInterrupt();

        virtual void begin();
        virtual void end();

    private:
        SPISettings settings = SPISettings(0, MSBFIRST, SPI_MODE0);
        // _ft232h_spi *dev = NULL;
    };

}

extern arduino::FT232HSPI SPI;
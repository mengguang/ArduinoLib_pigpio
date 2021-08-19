#pragma once

#include "Arduino.h"
#include "api/HardwareI2C.h"
#include "PiGpio.h"

#define I2C_TX_BUFFER_SIZE 60

namespace arduino
{
    class I2CPI : public HardwareI2C
    {
    public:
        I2CPI()
        {
        }

        void begin()
        {
        }

        void begin(uint8_t address)
        {
        }

        void end()
        {
        }

        void setClock(uint32_t freq)
        {
        }

        void beginTransmission(uint8_t address)
        {
            _address = address;
            usedTxBuffer = 0;
        }
        uint8_t endTransmission(bool stopBit)
        {
            // uint32_t s = millis();
            uint32_t n = 0;

            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return 0;
            }
            n = pig->i2c_write_device(_address, txBuffer, usedTxBuffer);
            if (n == usedTxBuffer)
            {
                // printf("i2c write: %u, time: %u\n", usedTxBuffer, millis() - s);
                return 0;
            }
            return 2;
        }
        uint8_t endTransmission(void)
        {
            return endTransmission(true);
        }

        size_t requestFrom(uint8_t address, size_t len, bool stopBit)
        {
            // printf("requestFrom length: %d\n", len);
            uint8_t buf[256];
            memset(buf, 0, sizeof(buf));
            if (len > 256)
            {
                printf("max read length is 256.\n");
                return 0;
            }
            if (rxBuffer.availableForStore() < len)
            {
                printf("rxBuffer will overflow!, stop read.\n");
                return 0;
            }
            int ret = 0;
            auto pig = PiGpio::get_instance();
            if (!pig)
            {
                return 0;
            }
            ret = pig->i2c_read_device(_address, buf, len);
            if (ret != len)
            {
                printf("data returned length (%d) not equal to request length(%d).\n", ret, len);
                return 0;
            }
            for (size_t i = 0; i < len; i++)
            {
                rxBuffer.store_char(buf[i]);
            }
            return len;
        }

        size_t requestFrom(uint8_t address, size_t len)
        {
            return requestFrom(address, len, true);
        }

        void onReceive(void (*)(int));
        void onRequest(void (*)(void));

        size_t write(uint8_t data)
        {
            if (usedTxBuffer == sizeof(txBuffer))
            {
                return 0;
            }

            txBuffer[usedTxBuffer] = data;
            usedTxBuffer++;
            return 1;
        }
        size_t write(int data)
        {
            return write((uint8_t)data);
        };
        size_t write(const uint8_t *data, int len)
        {
            if (usedTxBuffer + len > sizeof(txBuffer))
            {
                // len = 256 - usedTxBuffer;
                return 0;
            }
            memcpy(txBuffer + usedTxBuffer, data, len);
            usedTxBuffer += len;
            return len;
        }
        using Print::write;
        int read()
        {
            if (rxBuffer.available())
            {
                return rxBuffer.read_char();
            }
            return 0;
        }
        int peek()
        {
            return rxBuffer.peek();
        }
        void flush()
        {
        }
        int available()
        {
            return rxBuffer.available();
        }

    private:
        int _address;
        uint8_t txBuffer[I2C_TX_BUFFER_SIZE];
        uint32_t usedTxBuffer;
        RingBufferN<256> rxBuffer;
    };

}

extern arduino::I2CPI Wire;
typedef arduino::I2CPI TwoWire;
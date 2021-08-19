#pragma once

#include <pigpiod_if2.h>
#include <cstdio>
#include <Arduino.h>

class PiGpio
{
public:
    PiGpio()
    {
    }
    static PiGpio *get_instance()
    {
        if (!pig)
        {
            pig = new PiGpio();
            if (!pig->init())
            {
                delete pig;
                return nullptr;
            }
            return pig;
        }
        else
        {
            return pig;
        }
    }
    bool init()
    {
        instance = pigpio_start("127.0.0.1", "8888");
        if (instance < 0)
        {
            printf("pigpio_start error: %d\n", instance);
            return false;
        }
        return true;
    }

    void gpio_set_mode(uint8_t pin, uint8_t mode)
    {
        if (mode == INPUT)
        {
            ::set_mode(instance, pin, PI_INPUT);
        }
        if (mode == OUTPUT)
        {
            ::set_mode(instance, pin, PI_OUTPUT);
        }
    }

    PinStatus gpio_read(uint8_t pin)
    {
        auto val = ::gpio_read(instance, pin);
        if (val == PI_HIGH)
        {
            return HIGH;
        }
        else
        {
            return LOW;
        }
    }

    void gpio_write(uint8_t pin, uint8_t val)
    {
        if (val == HIGH)
        {
            ::gpio_write(instance, pin, PI_HIGH);
        }
        else
        {
            ::gpio_write(instance, pin, PI_LOW);
        }
    }

    int i2c_write_device(uint8_t addr, const uint8_t *data, uint32_t data_length)
    {
        int i2c = i2c_open(instance, 1, addr, 0);
        if (i2c < 0)
        {
            printf("i2c_open error: %d\n", i2c);
            return -1;
        }
        int status = ::i2c_write_device(instance, i2c, (char *)data, data_length);
        if (status == 0)
        {
            ::i2c_close(instance, i2c);
            return data_length;
        }
        else
        {
            printf("i2c_write_device error: %d\n", status);
            ::i2c_close(instance, i2c);
            return 0;
        }
    }

    int i2c_read_device(uint8_t addr, uint8_t *data, uint32_t data_length)
    {
        int i2c = i2c_open(instance, 1, addr, 0);
        if (i2c < 0)
        {
            printf("i2c_open error: %d\n", i2c);
            return -1;
        }
        int status = ::i2c_read_device(instance, i2c, (char *)data, data_length);
        if (status > 0)
        {
            ::i2c_close(instance, i2c);
            return data_length;
        }
        else
        {
            printf("i2c_read_device error: %d\n", status);
            ::i2c_close(instance, i2c);
            return 0;
        }
    }

private:
    int instance = -1;
    static PiGpio *pig;
};

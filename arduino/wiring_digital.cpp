#include <Arduino.h>
#include <PiGpio.h>

void pinMode(uint8_t pin, PinMode mode)
{
    auto pig = PiGpio::get_instance();
    if (!pig)
    {
        return;
    }
    pig->gpio_set_mode(pin, mode);
}

void digitalWrite(uint8_t pin, PinStatus val)
{
    auto pig = PiGpio::get_instance();
    if (!pig)
    {
        return;
    }
    pig->gpio_write(pin, val);
}

PinStatus digitalRead(uint8_t pin)
{
    auto pig = PiGpio::get_instance();
    if (!pig)
    {
        return LOW;
    }
    return pig->gpio_read(pin);
}

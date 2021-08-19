#include "SPI.h"

arduino::FT232HSPI::FT232HSPI()
{
}

void arduino::FT232HSPI::begin()
{
}

void arduino::FT232HSPI::end()
{
}

uint8_t arduino::FT232HSPI::transfer(uint8_t data)
{
    return 0;
}

uint16_t arduino::FT232HSPI::transfer16(uint16_t data)
{
    return 0;
}

void arduino::FT232HSPI::transfer(void *buf, size_t count)
{
}

void arduino::FT232HSPI::write(uint8_t *input, uint32_t count)
{
}

void arduino::FT232HSPI::usingInterrupt(int interruptNumber)
{
}

void arduino::FT232HSPI::notUsingInterrupt(int interruptNumber)
{
}

void arduino::FT232HSPI::beginTransaction(SPISettings settings)
{
}

void arduino::FT232HSPI::endTransaction()
{
}
void arduino::FT232HSPI::attachInterrupt()
{
}
void arduino::FT232HSPI::detachInterrupt()
{
}

arduino::FT232HSPI SPI;
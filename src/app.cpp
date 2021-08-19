#include <Arduino.h>
#include <Wire.h>
#include "SHTSensor.h"
#include "SSD1306Wire.h"

const int led = P7;

SHTSensor sht(SHTSensor::SHTC3);

#define OLED_I2C_ADDR 0x3c
SSD1306Wire display(OLED_I2C_ADDR);

void drawFontFaceDemo()
{
    // create more fonts at http://oleddisplay.squix.ch/
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Hello world");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 10, "Hello world");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 26, "Hello world");
    display.display();
}

void displaySensorData(double humidity, double temperature)
{
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    char buffer[32];
    display.drawStringf(0, 0, buffer, "Humd: %.02f%%", humidity);
    display.drawStringf(0, 22, buffer, "Temp: %.02f°C", temperature);
    display.display();
}

void setup()
{
    // SPI.begin();
    Wire.begin();

    pinMode(led, OUTPUT);

    Serial.begin(115200);
    delay(1000);
    sht.init();
    display.init();
    // display.flipScreenVertically();
    // display.setFont(ArialMT_Plain_10);
    drawFontFaceDemo();
}

void loop()
{
    // put your main code here, to run repeatedly:
    // read from first sensor
    if (sht.readSample())
    {
        double humidity = sht.getHumidity();
        double temperature = sht.getTemperature();
        Serial.printf("RH: %.02f\n T: %.02f\n\n", humidity, temperature);
        displaySensorData(humidity, temperature);
    }
    else
    {
        Serial.print("Sensor 1: Error in readSample()\n");
    }
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
}

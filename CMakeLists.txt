cmake_minimum_required(VERSION 3.16)
project(ArduinoLib_pigpio)

set(CMAKE_CXX_STANDARD 14)

add_compile_definitions(ARDUINO)

include_directories(src)
include_directories(arduino)

include_directories(lib/arduino-sht-master/)
include_directories(lib/esp8266-oled-ssd1306-master/src)

add_executable(main 
    arduino/main.cpp 
    src/app.cpp 
    arduino/wiring.cpp 
    arduino/wiring_digital.cpp
    arduino/wiring_analog.cpp
    arduino/Serial.cpp
    arduino/WMath.cpp
    arduino/itoa.cpp
    arduino/api/Common.cpp 
    arduino/api/Stream.cpp
    arduino/api/String.cpp
    arduino/api/Print.cpp
    arduino/utils.cpp
    arduino/Wire.cpp
    arduino/SPI.cpp
    arduino/PiGpio.cpp
    lib/arduino-sht-master/SHTSensor.cpp
    lib/esp8266-oled-ssd1306-master/src/OLEDDisplay.cpp
    lib/esp8266-oled-ssd1306-master/src/OLEDDisplayUi.cpp
)

target_link_libraries(main pigpiod_if2 rt)


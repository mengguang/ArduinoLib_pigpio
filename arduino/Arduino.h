#if !defined(Arduino_h)
#define Arduino_h

#include "api/ArduinoAPI.h"
#include "PinWiringPi.h"

#include "Serial.h"
#define Serial _Console

#define _min(a, b) ((a) < (b) ? (a) : (b))
#define _max(a, b) ((a) > (b) ? (a) : (b))

#endif
#include "Wire.h"

typedef void (*voidFuncPtrParamInt)(int);

void arduino::I2CPI::onReceive(voidFuncPtrParamInt cb)
{
}
void arduino::I2CPI::onRequest(voidFuncPtr cb)
{
}

arduino::I2CPI Wire;
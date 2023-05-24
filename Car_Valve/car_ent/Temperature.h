#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

//###########################################
// Status led control abstraction
//###########################################
void InitTemperatureSensors();

float getTemperaturesExhaust();
float getTemperaturesValve();

//###########################################

#endif

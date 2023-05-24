#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "hal.h"
#include "Temperature.h"

OneWire oneWire_Exhaust(ONE_WIRE_BUS_EXHAUST);
OneWire oneWire_Valve(ONE_WIRE_BUS_VALVE);

DallasTemperature sensors_tE(&oneWire_Exhaust);   // Temperature sensor for Exhaust gases
DallasTemperature sensors_tV(&oneWire_Valve);     // Temperature sensor for the outcomming valve

void InitTemperatureSensors() {
  sensors_tE.begin();
  sensors_tV.begin();

  sensors_tE.requestTemperatures();
  sensors_tV.requestTemperatures();
}

float getTemperaturesExhaust() {
  sensors_tE.requestTemperatures();

  return sensors_tE.getTempCByIndex(0);
}

float getTemperaturesValve() {
  sensors_tV.requestTemperatures();

  return sensors_tV.getTempCByIndex(0);
}

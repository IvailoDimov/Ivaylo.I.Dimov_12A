#include <Arduino.h>
#include "hal.h"
#include "Shock.h"

// Initialize Shock sensor
void InitShockSensor() {
  //pinMode(SHOCK_PIN, INPUT);
}

// Function to get current status of a shock sensor
int GetShockStatus() {

  if(analogRead(A7) < SHOCK_TRESSHOLD ) {    // 5V/(2^10) * 100 = 0,5V
    return SHOCK_DETECTED;
  }
  else {
    return SHOCK_CLEAR;
  }
  
}

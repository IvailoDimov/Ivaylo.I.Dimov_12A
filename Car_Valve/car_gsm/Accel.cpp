#include <Arduino.h>
#include <Adafruit_ADXL345_U.h>
#include "hal.h"
#include "Accel.h"
#include "StatusLed.h"


Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// Initialize status led
void InitAccel() {
  if(!accel.begin())
  {
    while(1) {
      Blink(2);
      delay(1000);
    }
  }

  accel.setRange(ADXL345_RANGE_16_G);
  
}

// Function to turn status led on
float GetAccelAbsolute() {
  
  sensors_event_t event;
  accel.getEvent(&event);
  float acceleration = sqrt(pow(event.acceleration.x, 2) + pow(event.acceleration.y, 2) + pow(event.acceleration.z, 2));
  
  return acceleration;
}

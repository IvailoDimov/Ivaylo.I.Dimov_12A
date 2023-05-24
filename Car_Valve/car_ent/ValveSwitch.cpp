#include <Arduino.h>
#include "hal.h"
#include "ValveSwitch.h"

// Initialize button that controls valve
void InitValveSwitch() {
  pinMode(BTN_PIN , INPUT);

}

// Get status of the button
int getButtonStatus() {
  int buttonStatus;
  
  buttonStatus = digitalRead(BTN_PIN);

  return buttonStatus;
}

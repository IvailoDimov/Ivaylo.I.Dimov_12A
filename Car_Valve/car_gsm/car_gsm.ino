#include "hal.h"
#include "StatusLed.h"
#include "Shock.h"
#include "Gsm.h"
#include "Accel.h"
#include "Comm.h"

void setup() {
  

  InitStatusLed();
  TurnLedOn();
  Serial.begin(9600);
  InitShockSensor();
  InitGsm();
  InitAccel();

  delay(7500);
  Blink(3);
}

void loop() {

  if(GetShockStatus() == SHOCK_DETECTED) {
    QuickBlink(10);
    SendSmsShock();
  }
 
  if (GetAccelAbsolute() > ACCEL_THRESHOLD) {
    QuickBlink(3);
    SendSmsAccel();
  }

  //Ping();
  if (CheckPing() == COMM_NOT_OK) {
    SendSmsComm();
    while(1);
  }
}

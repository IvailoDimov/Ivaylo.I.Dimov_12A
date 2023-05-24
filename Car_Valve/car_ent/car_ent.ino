#include "hal.h"
#include "StatusLed.h"
#include "ValveSwitch.h"
#include "ValveControl.h"
#include "LcdControl.h"
#include "Temperature.h"
#include "Comm.h"

float tempExhaust, tempValve;                     // Globaly store temperatures fromo the two sensors


void setup() {

  InitStatusLed();
  TurnLedOn();
  
  InitComm();
  
  InitLcd();
  printDemo();

  
  InitValveSwitch();
  
  InitValve();
  CloseValve();

  InitTemperatureSensors();
  
  delay(3000);
  ClearDisplay();
  Blink(3);
}

void loop() {

  tempExhaust = getTemperaturesExhaust();
  tempValve   = getTemperaturesValve();
  printTemperature(tempExhaust, tempValve);
  printShortValveStatus(GetValveStatus());
  
  // Make connection between the button and the valve
  if( getButtonStatus() == IS_BTN_PRESSED) {
    QuickBlink(10);
    if(GetValveStatus() == VALVE_CLOSED) {
      printValveOpening();
      OpenValve();
      printDone();
    }
    else {
      printValveClosing();
      CloseValve();
      printDone();
    }
  }
  
  Ping();
  if (CheckPing() == COMM_NOT_OK) {
    printCommLost();
    while(1);
  }
  delay(500);
}

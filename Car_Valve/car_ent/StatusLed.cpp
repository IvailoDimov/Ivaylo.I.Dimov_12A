#include <Arduino.h>
#include "hal.h"
#include "StatusLed.h"

// Initialize status led
void InitStatusLed() {
  pinMode(LED_PIN, OUTPUT);
  TurnLedOff();
}

// Function to turn status led on
void TurnLedOn() {
  digitalWrite(LED_PIN, LED_ON);
}

// Function to turn status led off
void TurnLedOff() {
  digitalWrite(LED_PIN, LED_OFF);
}

// Function to make a led blink
void Blink(unsigned char blinks) {
  
  for(unsigned char i = 0; i < blinks; i++) {
    TurnLedOn();
    delay(250);
    TurnLedOff();
    delay(250);
  }
  
}

// Blink the Status led quickly
void QuickBlink(unsigned char blinks) {
  
  for(unsigned char i = 0; i < blinks; i++) {
    TurnLedOn();
    delay(50);
    TurnLedOff();
    delay(50);
  }
  
}

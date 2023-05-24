#include <Arduino.h>
#include "hal.h" 
#include "ValveControl.h"

int ValveStatus = VALVE_CLOSED;

// Initialize valve control pins
void InitValve() {
  pinMode(EN_A, OUTPUT);
  pinMode(IN_1, OUTPUT);
  digitalWrite(IN_1, LOW);
  pinMode(IN_2, OUTPUT);
  digitalWrite(IN_2, LOW);
}

// Function to open the valve
void CloseValve() {
  digitalWrite(EN_A, HIGH);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  delay(TIME_MS_VALVE_OPERATION);
  digitalWrite(EN_A, LOW);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);

  ValveStatus = VALVE_CLOSED;
}

// Function to close the valve
void OpenValve() {
  digitalWrite(EN_A, HIGH);
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  delay(TIME_MS_VALVE_OPERATION);
  digitalWrite(EN_A, LOW);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);

  ValveStatus = VALVE_OPENED;
}

// Function to get the status of the valve
int GetValveStatus() {
  return ValveStatus;
}

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "hal.h"
#include "Gsm.h"
#include "StatusLed.h"

SoftwareSerial SIM900A(GSM_RX, GSM_TX);

// Initialize Shock sensor
void InitGsm() {
  SIM900A.begin(9600);
}

// Function to get current status of a shock sensor
void SendSmsShock() {
  Blink(2);
  SIM900A.println("AT+CMGF=1");
  delay(1000);
  SIM900A.println("AT+CMGS=\"+359887726372\"\r");
  delay(1000);
  SIM900A.println("Shock Alarm is triggered");
  delay(100);
  SIM900A.println((char)26);
}

void SendSmsAccel() {
  Blink(2);
  SIM900A.println("AT+CMGF=1");
  delay(1000);
  SIM900A.println("AT+CMGS=\"+359887726372\"\r");
  delay(1000);
  SIM900A.println("Accel Alarm is triggered");
  delay(100);
  SIM900A.println((char)26);
}

void SendSmsComm() {
  Blink(2);
  SIM900A.println("AT+CMGF=1");
  delay(1000);
  SIM900A.println("AT+CMGS=\"+359887726372\"\r");
  delay(1000);
  SIM900A.println("Ent Alarm is triggered");
  delay(100);
  SIM900A.println((char)26);
}

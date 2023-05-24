#include <Arduino.h>
#include <SoftwareSerial.h>
#include "hal.h"
#include "Comm.h"
#include "StatusLed.h"

unsigned long lastReceiveTime = 0;
unsigned long lastSentTime = 0;
SoftwareSerial Comm(COMM_RX, COMM_TX);

// Initialize Communication interface
void InitComm() {
  Comm.begin(COMM_SPEED);
  Comm.listen();
  Serial.begin(9600);
}

// Function to send ping message
void Ping() {
  if (millis() - lastSentTime >= 500) {
    Comm.print('R');
    lastSentTime = millis();
    QuickBlink(1);
    Serial.println("Ping");
  }
}

// Function to receive ping
int CheckPing() {
  
  
  if (Comm.available()) {
    char receivedChar = Comm.read(); // Read the received character
    Serial.println("Rx");
    if (receivedChar == 'R') {
      lastReceiveTime = millis(); // Update the last received time
      QuickBlink(5);
      return COMM_OK;
    }
  }

  // Check if more than 2 seconds have passed since the last received time
  if (millis() - lastReceiveTime > 20000) {
    
    return COMM_NOT_OK;
  } else{
    return COMM_OK;
  }
}

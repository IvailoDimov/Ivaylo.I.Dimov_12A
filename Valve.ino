#include <Wire.h>

int enA = 9;
int in1 = 8;
int in2 = 7;
const int buttonPin = 2; 
const int ledPin = 13; 

bool closed = 0;
int buttonState = 0; 

void setup() {

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(buttonPin, INPUT);
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}

void loop() {
  directionControl();

  delay(1000);

}


void directionControl() {

  bool pressed = 0;
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
   pressed = 1;
   if(closed == 0)
   {
    closed = 1;
   }else{
    closed = 0;
   }
 } 

  if(closed == 0 && pressed == 1)
  {
   analogWrite(enA, 255);
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   delay(2500);
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
  }

  if(closed == 1 && pressed == 1)
  {
    analogWrite(enA, 255);
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   delay(2500);
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
  }

}

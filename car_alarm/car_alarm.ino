#include <SoftwareSerial.h>
#include <Adafruit_ADXL345_U.h>

#define ACCEL_THRESHOLD 5.0
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
SoftwareSerial SIM900A(PA9,PA10.);
int shocksensor=PB9;              
int sensorvalue; 
boolean connected = false;      
void setup()
{
   pinMode(shocksensor,INPUT);
  SIM900A.begin(9600);   
  Serial.begin(9600);    
  Serial.println ("SIM900A Ready");
  delay(100);
  Serial.println ("Type s to send message or r to receive message");
}
void loop()
{
  if (Serial.available()) { 
    String msg = Serial.readString(); 
    Serial.println("Received message: " + msg);
    connected = true; 
  }
   else{
      SendMessage();
   }

    sensors_event_t event;
  accel.getEvent(&event);
  float acceleration = sqrt(pow(event.acceleration.x, 2) + pow(event.acceleration.y, 2) + pow(event.acceleration.z, 2));
   if (acceleration > ACCEL_THRESHOLD) {
    SendMessage();
  }
 
 sensorvalue = digitalRead(shocksensor); 
 if (!sensorvalue)      
 {
  SendMessage();
 }
}
 void SendMessage()
{
  Serial.println ("Sending Message");
  SIM900A.println("AT+CMGF=1");    
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+359887726372\"\r"); 
  delay(1000);
  Serial.println ("Set SMS Content");
  SIM900A.println("Alarm is triggered");
  delay(100);
  Serial.println ("Finish");
  SIM900A.println((char)26);
  delay(1000);
  Serial.println ("Message has been sent ");
  
}

#include <SoftwareSerial.h>
SoftwareSerial SIM900A(10,11);
int shocksensor=8;              
int sensorvalue;       
void setup()
{
   pinMode(shocksensor,INPUT);
  SIM900A.begin(9600);     
  Serial.begin(9600);    
  Serial.println ("SIM900A Ready");
  delay(100);
 
}
void loop()
{
 sensorvalue = digitalRead(shocksensor);
 if (sensorvalue==HIGH)      
 
 {
  SendMessage();
    
     return 0;
  
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
  SIM900A.println("Shock sensor on");
  delay(100);
  
}

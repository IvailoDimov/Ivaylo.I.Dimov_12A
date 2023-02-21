#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>

const int SENSOR_PIN = 13; 

OneWire oneWire(SENSOR_PIN);
DallasTemperature tempSensor(&oneWire);

float tempCelsius;

LiquidCrystal_I2C lcd(0x27,16,2); 

int WhichScreen =1;  
boolean hasChanged = true;
const int buttonPin = 4; 
int buttonState; 
int lastButtonState = LOW; 
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50; 
void setup()
{
  Serial.begin(9600); 
  tempSensor.begin(); 
  lcd.init();
  lcd.backlight();
  pinMode(buttonPin, INPUT);

}
void loop()

{
  tempSensor.requestTemperatures(); 
  tempCelsius = tempSensor.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(tempCelsius); 
  Serial.print("°C");

  if (hasChanged == true) {

  switch(WhichScreen) {
  case 1:
   {
     firstScreen();
   }
    break;

   case 2:
   {
     secondScreen();
   }
     break;

     case 0:
   {

   }
    break;
   }
}


  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) { 
   lastDebounceTime = millis();
  }

if ((millis() - lastDebounceTime) > debounceDelay) {

 
    if (reading != buttonState) {
    buttonState = reading;
 
    if (buttonState == HIGH) {
     hasChanged = true;
     WhichScreen++;
     }
   } else {
     hasChanged = false;
   }
  }
  lastButtonState = reading;
  if (WhichScreen > 2){
   WhichScreen = 1;
  }
}
void firstScreen()
 {
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print( tempCelsius);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("On a menu system");
  delay(500);
  }
void secondScreen()
  {
   lcd.clear();
   lcd.setCursor(0,0); 
   lcd.print(" Second screen");
   lcd.setCursor(0,1);
   lcd.print("of my menu !!");
  }




#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>


#define ONE_WIRE_BUS_1 12
#define ONE_WIRE_BUS_2 11
int enA = 9;
int in1 = 8;
int in2 = 7;
const int buttonPin = 2; 
const int ledPin = 13;   

bool closed = 0;
int buttonState = 0;

OneWire oneWire_1(ONE_WIRE_BUS_1);
OneWire oneWire_2(ONE_WIRE_BUS_2);
DallasTemperature sensors_1(&oneWire_1);
DallasTemperature sensors_2(&oneWire_2);



LiquidCrystal_I2C lcd(0x27, 16, 2);



float temp1, temp2;


bool displayTemp1 = true;

void setup() {
  Serial.begin(9600);

  sensors_1.begin();
  sensors_2.begin();
  lcd.init();
  lcd.backlight();



  sensors_1.requestTemperatures();
  sensors_2.requestTemperatures();
  temp1 = sensors_1.getTempCByIndex(0);
  temp2 = sensors_2.getTempCByIndex(0);


  lcd.setCursor(0, 0);
  lcd.print("Temp 1: ");
  lcd.print(temp1, 1);
  lcd.setCursor(0, 1);
  lcd.print("Temp 2: ");
  lcd.print(temp2, 1);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(buttonPin, INPUT);


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {

  directionControl();
  sensors_1.requestTemperatures();
  sensors_2.requestTemperatures();
  temp1 = sensors_1.getTempCByIndex(0);
  temp2 = sensors_2.getTempCByIndex(0);

  lcd.setCursor(0, 0);
  lcd.print("Temp1: ");
  lcd.print(temp1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Temp2: ");
  lcd.print(temp2);
  lcd.print("C");


  delay(500);
}

void directionControl() {

  bool pressed = 0;
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    pressed = 1;
    if (closed == 0) {
      closed = 1;
    } else {
      closed = 0;
    }
  }

  if (closed == 0 && pressed == 1) {
    analogWrite(enA, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(2500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
                                                                                                                                                                                                                                                              
  if (closed == 1 && pressed == 1) {
    analogWrite(enA, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(2500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}

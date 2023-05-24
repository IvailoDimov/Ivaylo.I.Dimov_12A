#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "hal.h"
#include "LcdControl.h"

LiquidCrystal_I2C lcd(LCD_I2C_ADDR, LCD_COLS, LCD_ROWS);

// Initialize LCD screen
void InitLcd() {
  
  lcd.init();
  lcd.begin(LCD_COLS, LCD_ROWS);
  ClearDisplay();
  lcd.backlight();
}

// Print Demo screen
void printDemo() {
  
  ClearDisplay();
  lcd.setCursor(0, 0);
  lcdPrintString("Valve control", 13);
  lcd.setCursor(0, 1);
  lcdPrintString("Ivo Dimov", 9);

  delay(2000);

  ClearDisplay();
  lcd.setCursor(0, 0);
  lcdPrintString("TUES  17.02.2023", 16);
  lcd.setCursor(0, 1);
  lcdPrintString("v. 2.1.1", 8);

  delay(2000);
}

void ClearDisplay() {
  lcd.clear();
}

// To print const strings like "Hello world", use this thing
void lcdPrintString(const char _str[], int _size) {
  for(int i = 0; i < _size; i++) {
    lcd.print(_str[i]);
  }
}

// For any other uses
void lcdPrint(char _str[], int _size) {
  for(int i = 0; i < _size; i++) {
    lcd.print(_str[i]);
  }
}

// Print a Screen showing the valve is opening
void printValveOpening(){

  ClearDisplay();
  lcd.setCursor(0, 0);
  lcdPrintString("Opening ...", 11);
  lcd.setCursor(0, 1);
  lcdPrintString("Ridin\' dirty", 12);
}

// Print a Screen showing the valve is closing
void printValveClosing(){
  
  ClearDisplay();
  lcd.setCursor(0, 0);
  lcdPrintString("Closing ...", 11);
  lcd.setCursor(0, 1);
  lcdPrintString("Gettin\' Legal", 13);
}

// Print a Screen showing a operation is done
void printDone() {
  ClearDisplay();
  lcd.setCursor(0, 0);
  lcdPrintString("    Done", 9);
  delay(2000);
  ClearDisplay();
}

// Print a Screen showing the valve of both temperature sensors
void printTemperature( int _temp_valve, int _temp_exhaust) {
  ClearDisplay();
  lcd.setCursor(0, 0);
    
  lcdPrint("Temp1: ", 7);
  lcd.print(_temp_valve);
  lcdPrint(" *C", 3);

  lcd.setCursor(0, 1);
  lcdPrint("Temp2: ", 7);
  lcd.print(_temp_exhaust);
  lcdPrint(" *C", 3);
}

// Print a Screen showing the valve of both temperature sensors
void printCommLost() {
  ClearDisplay();
  lcd.setCursor(0, 0);
    
  lcdPrint("Comm with GSM", 13);

  lcd.setCursor(0, 1);
  lcdPrint("LOST !", 6);
}

void printShortValveStatus(int _valve_status) {
  
  lcd.setCursor(15, 0);
  if(_valve_status == VALVE_OPENED)
    lcdPrintString("O", 1);
  else
    lcdPrintString("I", 1);

}

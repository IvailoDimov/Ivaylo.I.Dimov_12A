#ifndef __LCDCONTROL_H__
#define __LCDCONTROL_H__

//###########################################
// LCD abstraction
//###########################################
void InitLcd();

void ClearDisplay();
void lcdPrint(char _str[], int _size);
void lcdPrintString(const char _str[], int _size);

void printDemo();
void printValveOpening();
void printValveClosing();
void printDone();
void printTemperature( int _temp_valve, int _temp_exhaust);
void printCommLost();

void printShortValveStatus(int _valve_status);
//###########################################

#endif

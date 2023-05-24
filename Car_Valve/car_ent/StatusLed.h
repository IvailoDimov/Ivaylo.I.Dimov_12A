#ifndef __STATUSLED_H__
#define __STATUSLED_H__

//###########################################
// Status led control abstraction
//###########################################
void InitStatusLed();

void TurnLedOn();
void TurnLedOff();

void Blink(unsigned char blinks);

void QuickBlink(unsigned char blinks);
//###########################################

#endif

#ifndef __HAL_H__
#define __HAL_H__

//###########################################
// Hardware Abstraction Layer - HAL
//###########################################

// HAL related to valve control
#define EN_A 			4
#define IN_1 			3
#define IN_2 			2

#define VALVE_CLOSED  		0
#define VALVE_OPENED   		1

#define TIME_MS_VALVE_OPERATION 2500
//-------------------------------------------

// HAL related to temperature sensors
#define ONE_WIRE_BUS_VALVE    	10
#define ONE_WIRE_BUS_EXHAUST  	5     //Temp 2
//-------------------------------------------

// HAL related to button control
#define BTN_PIN 		12
#define IS_BTN_PRESSED LOW
//-------------------------------------------

// HAL related to status led
#define LED_PIN    		13  
#define LED_ON			HIGH
#define LED_OFF			LOW

// HAL related to LCD 
#define LCD_ROWS        2
#define LCD_COLS        16
#define LCD_I2C_ADDR    0x27

// HAL related to Communication
#define COMM_RX 9
#define COMM_TX 8
#define COMM_SPEED	9600
#define COMM_OK		1
#define COMM_NOT_OK	0
//###########################################

#endif

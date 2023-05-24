#ifndef __HAL_H__
#define __HAL_H__

//###########################################
// Hardware Abstraction Layer - HAL
//###########################################

// HAL related Shock sensor
#define SHOCK_PIN		      A7
#define SHOCK_TRESSHOLD    100

#define SHOCK_DETECTED    1
#define SHOCK_CLEAR       0

// HAL related to GSM communication module
#define GSM_RX  A3
#define GSM_TX  A2

// HAL related to status led
#define LED_PIN    		13  
#define LED_ON			HIGH
#define LED_OFF			LOW

// HAL related to Accelerometer
#define ACCEL_THRESHOLD 12.0

// HAL related to Communication
#define COMM_RX 9
#define COMM_TX 8
#define COMM_SPEED	9600
#define COMM_OK		1
#define COMM_NOT_OK	0
//###########################################

#endif

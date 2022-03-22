#ifndef _PIN_CONNECT_H_
#define _PIN_CONNECT_H_

// Pin TX (Bluetooth) connect to D2 (Arduino)
// Pin RX (Bluetooth) connect to D3 (Arduino)

/* -------------- L298 1st floor, for two wheels (BR) and (BL) -------------- */
#define MOTOR_BR_ENA 11
#define MOTOR_BR_IN1 A0
#define MOTOR_BR_IN2 A1
#define MOTOR_BL_IN3 A2
#define MOTOR_BL_IN4 A3
#define MOTOR_BL_ENB 10

/* -------------- L298 2nd floor, for two wheels (FR) and (FL) -------------- */
#define MOTOR_FR_ENA 6
#define MOTOR_FR_IN1 12
#define MOTOR_FR_IN2 9
#define MOTOR_FL_IN3 8
#define MOTOR_FL_IN4 7
#define MOTOR_FL_ENB 5

#endif

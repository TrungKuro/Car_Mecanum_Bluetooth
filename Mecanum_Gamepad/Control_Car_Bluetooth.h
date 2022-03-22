#ifndef _CONTROL_CAR_BLUETOOTH_H_
#define _CONTROL_CAR_BLUETOOTH_H_

/* -------------------------------------------------------------------------- */

#include "Arduino.h"
#include "Pin_Connect.h"

/* -------------------------------------------------------------------------- */
/*                                CONFIG MOTORS                               */
/* -------------------------------------------------------------------------- */

/* ----------------------- Motors are Stopped (Brakes) ---------------------- */
void motor_BR_stop();
void motor_BL_stop();
void motor_FR_stop();
void motor_FL_stop();

/* -------------------------------- Motor BR -------------------------------- */
void motor_BR_forward(int speed);
void motor_BR_backward(int speed);

/* -------------------------------- Motor BL -------------------------------- */
void motor_BL_forward(int speed);
void motor_BL_backward(int speed);

/* -------------------------------- Motor FR -------------------------------- */
void motor_FR_forward(int speed);
void motor_FR_backward(int speed);

/* -------------------------------- Motor FL -------------------------------- */
void motor_FL_forward(int speed);
void motor_FL_backward(int speed);

/* -------------------------------------------------------------------------- */
/*                                 CONFIG CAR                                 */
/* -------------------------------------------------------------------------- */

void stop();                        // Stop Car (motor not work!)

void go_forward(int speed);         // ⇧
void go_backward(int speed);        // ⇩

void go_left(int speed);            // ⇦
void go_right(int speed);           // ⇨

void go_left_forward(int speed);    // ⇖
void go_right_forward(int speed);   // ⇗

void go_left_backward(int speed);   // ⇙
void go_right_backward(int speed);  // ⇘

void turn_CW(int speed);            // ↻
void turn_CCW(int speed);           // ↺

/* -------------------------------------------------------------------------- */

#endif

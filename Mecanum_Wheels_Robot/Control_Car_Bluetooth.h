#ifndef _CONTROL_CAR_BLUETOOTH_H_
#define _CONTROL_CAR_BLUETOOTH_H_

// --------------------------------------------------------------------------------------------------------------------------------- //

#include "Arduino.h"
#include "Pin_Connect.h"

// --------------------------------------------------------------------------------------------------------------------------------- //

/* Hàm dừng từng Motor */
void motor_FR_stop();
void motor_FL_stop();
void motor_BR_stop();
void motor_BL_stop();

/* Hàm quay các Motor chiều kim đồng hồ (+ CW) */
void motor_FR_clockwise();
void motor_FL_clockwise();
void motor_BR_clockwise();
void motor_BL_clockwise();

/* Hàm quay các Motor ngược chiều kim đồng hồ (- CCW) */
void motor_FR_counter_clockwise();
void motor_FL_counter_clockwise();
void motor_BR_counter_clockwise();
void motor_BL_counter_clockwise();

// --------------------------------------------------------------------------------------------------------------------------------- //

void stop_car();            // Dừng xe (ko làm gì cả)

void go_forward();          // Xe đi về phía trước (chiều dọc)
void back_forward();        // Xe đi lùi về phía sau (chiều dọc)

void go_left();             // Xe đi sang trái (chiều ngang)
void go_right();            // Xe đi sang phải (chiều ngang)

void turn_CW();             // Xe quay chiều đồng hồ (CW)
void turn_CCW();            // Xe quay ngược chiều đồng hồ (CCW)

void go_left_forward();     // Xe đi thẳng về phía trái
void go_right_forward();    // Xe đi thẳng về phía phải

void back_left_forward();   // Xe đi lùi về phía trái
void back_right_forward();  // Xe đi lùi về phía phải

// --------------------------------------------------------------------------------------------------------------------------------- //

#endif

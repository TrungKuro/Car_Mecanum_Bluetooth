#include "Control_Car_Bluetooth.h"

// --------------------------------------------------------------------------------------------------------------------------------- //
// Hàm dừng từng Motor

void motor_FR_stop()
{
    digitalWrite(MOTOR_FR_IN1, LOW);
    digitalWrite(MOTOR_FR_IN2, LOW);
}

void motor_FL_stop()
{
    digitalWrite(MOTOR_FL_IN3, LOW);
    digitalWrite(MOTOR_FL_IN4, LOW);
}

void motor_BR_stop()
{
    digitalWrite(MOTOR_BR_IN1, LOW);
    digitalWrite(MOTOR_BR_IN2, LOW);
}

void motor_BL_stop()
{
    digitalWrite(MOTOR_BL_IN3, LOW);
    digitalWrite(MOTOR_BL_IN4, LOW);
}

// --------------------------------------------------------------------------------------------------------------------------------- //
// Hàm quay các Motor chiều kim đồng hồ (+ CW)

void motor_FR_clockwise()
{
    digitalWrite(MOTOR_FR_IN1, HIGH);
}

void motor_FL_clockwise()
{
    digitalWrite(MOTOR_FL_IN3, HIGH);
}

void motor_BR_clockwise()
{
    digitalWrite(MOTOR_BR_IN1, HIGH);
}

void motor_BL_clockwise()
{
    digitalWrite(MOTOR_BL_IN3, HIGH);
}

// --------------------------------------------------------------------------------------------------------------------------------- //
// Hàm quay các Motor ngược chiều kim đồng hồ (- CCW)

void motor_FR_counter_clockwise()
{
    digitalWrite(MOTOR_FR_IN2, HIGH);
}

void motor_FL_counter_clockwise()
{
    digitalWrite(MOTOR_FL_IN4, HIGH);
}

void motor_BR_counter_clockwise()
{
    digitalWrite(MOTOR_BR_IN2, HIGH);
}

void motor_BL_counter_clockwise()
{
    digitalWrite(MOTOR_BL_IN4, HIGH);
}

// --------------------------------------------------------------------------------------------------------------------------------- //

// Dừng xe (ko làm gì cả)
void stop_car()
{
    motor_FR_stop();
    motor_FL_stop();
    motor_BR_stop();
    motor_BL_stop();
}

// Xe đi về phía trước (chiều dọc)
void go_forward()
{
    motor_FR_clockwise();
    motor_FL_clockwise();
    motor_BR_clockwise();
    motor_BL_clockwise();
}
// Xe đi lùi về phía sau (chiều dọc)
void back_forward()
{
    motor_FR_counter_clockwise();
    motor_FL_counter_clockwise();
    motor_BR_counter_clockwise();
    motor_BL_counter_clockwise();
}

// Xe đi sang trái (chiều ngang)
void go_left()
{
    motor_FR_clockwise();
    motor_FL_counter_clockwise();
    motor_BR_counter_clockwise();
    motor_BL_clockwise();
}
// Xe đi sang phải (chiều ngang)
void go_right()
{
    motor_FR_counter_clockwise();
    motor_FL_clockwise();
    motor_BR_clockwise();
    motor_BL_counter_clockwise();
}

// Xe quay ngược chiều đồng hồ (CCW)
void turn_CCW()
{
    motor_FR_clockwise();
    motor_FL_counter_clockwise();
    motor_BR_clockwise();
    motor_BL_counter_clockwise();
}
// Xe quay chiều đồng hồ (CW)
void turn_CW()
{
    motor_FR_counter_clockwise();
    motor_FL_clockwise();
    motor_BR_counter_clockwise();
    motor_BL_clockwise();
}

// Xe đi thẳng về phía trái
void go_left_forward()
{
    motor_FR_clockwise();
    motor_FL_stop();
    motor_BR_stop();
    motor_BL_clockwise();
}
// Xe đi thẳng về phía phải
void go_right_forward()
{
    motor_FR_stop();
    motor_FL_clockwise();
    motor_BR_clockwise();
    motor_BL_stop();
}

// Xe đi lùi về phía trái
void back_left_forward()
{
    motor_FR_stop();
    motor_FL_counter_clockwise();
    motor_BR_counter_clockwise();
    motor_BL_stop();
}
// Xe đi lùi về phía phải
void back_right_forward()
{
    motor_FR_counter_clockwise();
    motor_FL_stop();
    motor_BR_stop();
    motor_BL_counter_clockwise();
}

// --------------------------------------------------------------------------------------------------------------------------------- //

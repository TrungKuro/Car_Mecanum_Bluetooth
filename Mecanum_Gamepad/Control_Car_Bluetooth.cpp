#include "Control_Car_Bluetooth.h"

/* -------------------------------------------------------------------------- */
/*                                CONFIG MOTORS                               */
/* -------------------------------------------------------------------------- */

/* ----------------------- Motors are Stopped (Brakes) ---------------------- */

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

/* -------------------------------- Motor BR -------------------------------- */

void motor_BR_forward(int speed)  // Turn Clockwise (CW)
{
  analogWrite(MOTOR_BR_ENA, speed);

  digitalWrite(MOTOR_BR_IN1, HIGH);
  digitalWrite(MOTOR_BR_IN2, LOW);
}

void motor_BR_backward(int speed) // Turn Counter-Clockwise (CCW)
{
  analogWrite(MOTOR_BR_ENA, speed);

  digitalWrite(MOTOR_BR_IN1, LOW);
  digitalWrite(MOTOR_BR_IN2, HIGH);
}

/* -------------------------------- Motor BL -------------------------------- */

void motor_BL_forward(int speed)  // Turn Counter-Clockwise (CCW)
{
  analogWrite(MOTOR_BL_ENB, speed);

  digitalWrite(MOTOR_BL_IN3, HIGH);
  digitalWrite(MOTOR_BL_IN4, LOW);
}

void motor_BL_backward(int speed) // Turn Clockwise (CW)
{
  analogWrite(MOTOR_BL_ENB, speed);

  digitalWrite(MOTOR_BL_IN3, LOW);
  digitalWrite(MOTOR_BL_IN4, HIGH);
}

/* -------------------------------- Motor FR -------------------------------- */

void motor_FR_forward(int speed)  // Turn Clockwise (CW)
{
  analogWrite(MOTOR_FR_ENA, speed);

  digitalWrite(MOTOR_FR_IN1, HIGH);
  digitalWrite(MOTOR_FR_IN2, LOW);
}

void motor_FR_backward(int speed) // Turn Counter-Clockwise (CCW)
{
  analogWrite(MOTOR_FR_ENA, speed);

  digitalWrite(MOTOR_FR_IN1, LOW);
  digitalWrite(MOTOR_FR_IN2, HIGH);
}

/* -------------------------------- Motor FL -------------------------------- */

void motor_FL_forward(int speed)  // Turn Counter-Clockwise (CCW)
{
  analogWrite(MOTOR_FL_ENB, speed);

  digitalWrite(MOTOR_FL_IN3, HIGH);
  digitalWrite(MOTOR_FL_IN4, LOW);
}

void motor_FL_backward(int speed) // Turn Clockwise (CW)
{
  analogWrite(MOTOR_FL_ENB, speed);

  digitalWrite(MOTOR_FL_IN3, LOW);
  digitalWrite(MOTOR_FL_IN4, HIGH);
}

/* -------------------------------------------------------------------------- */
/*                                 CONFIG CAR                                 */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- STOP! --------------------------------- */
void stop()
{
  motor_BR_stop();
  motor_BL_stop();
  motor_FR_stop();
  motor_FL_stop();
}

/* ----------------------------------- ⇧⇧⇧ ---------------------------------- */
void go_forward(int speed)
{
  motor_BR_forward(speed);
  motor_BL_forward(speed);
  motor_FR_forward(speed);
  motor_FL_forward(speed);
}

/* ----------------------------------- ⇩⇩⇩ ---------------------------------- */
void go_backward(int speed)
{
  motor_BR_backward(speed);
  motor_BL_backward(speed);
  motor_FR_backward(speed);
  motor_FL_backward(speed);
}

/* ----------------------------------- ⇦⇦⇦ ---------------------------------- */
void go_left(int speed)
{
  motor_BR_backward(speed);
  motor_BL_forward(speed);
  motor_FR_forward(speed);
  motor_FL_backward(speed);
}

/* ----------------------------------- ⇨⇨⇨ ---------------------------------- */
void go_right(int speed)
{
  motor_BR_forward(speed);
  motor_BL_backward(speed);
  motor_FR_backward(speed);
  motor_FL_forward(speed);
}

/* ----------------------------------- ⇖⇖⇖ ---------------------------------- */
void go_left_forward(int speed)
{
  motor_BR_stop();
  motor_BL_forward(speed);
  motor_FR_forward(speed);
  motor_FL_stop();
}

/* ----------------------------------- ⇗⇗⇗ ---------------------------------- */
void go_right_forward(int speed)
{
  motor_BR_forward(speed);
  motor_BL_stop();
  motor_FR_stop();
  motor_FL_forward(speed);
}

/* ----------------------------------- ⇙⇙⇙ ---------------------------------- */
void go_left_backward(int speed)
{
  motor_BR_backward(speed);
  motor_BL_stop();
  motor_FR_stop();
  motor_FL_backward(speed);
}

/* ----------------------------------- ⇘⇘⇘ ---------------------------------- */
void go_right_backward(int speed)
{
  motor_BR_stop();
  motor_BL_backward(speed);
  motor_FR_backward(speed);
  motor_FL_stop();
}

/* ----------------------------------- ↻↻↻ ---------------------------------- */
void turn_CW(int speed)
{
  motor_BR_backward(speed);
  motor_BL_forward(speed);
  motor_FR_backward(speed);
  motor_FL_forward(speed);
}

/* ----------------------------------- ↺↺↺ ---------------------------------- */
void turn_CCW(int speed)
{
  motor_BR_forward(speed);
  motor_BL_backward(speed);
  motor_FR_forward(speed);
  motor_FL_backward(speed);
}

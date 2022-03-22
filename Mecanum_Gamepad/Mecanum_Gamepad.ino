#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#include "Control_Car_Bluetooth.h"
#include "Pin_Connect.h"

void setup()
{
  Dabble.begin(9600);
}

void loop()
{
  Dabble.processInput();

  // Take value "Angle" and "Radius" from Joystick
  int a = GamePad.getAngle();
  int r = GamePad.getRadius();

  // This make Mapping from value "Radius" to value "PWM" for "max"
  // In there, "min" is always 0
  // Note, make sure "max" is always less than 6
  if(r>6) {r=6;}
  int max = map(r, 0, 6, 0, 255);

  // Maybe this is just a request to stop the car in "Joystick Mode"?
  // Or maybe it is in "Digital Mode"
  if(a == 0 && max == 0)
  {
    /* ---------------------------- Digital Mode ---------------------------- */
    if(GamePad.isLeftPressed())
    {
      if(GamePad.isSquarePressed())         {turn_CCW(255);}          // ↺
      else if(GamePad.isTrianglePressed())  {go_left_forward(255);}   // ⇖
      else if(GamePad.isCrossPressed())     {go_left_backward(255);}  // ⇙
      else                                  {go_left(255);}           // ⇦
    }
    else if(GamePad.isRightPressed())
    {
      if(GamePad.isCirclePressed())         {turn_CW(255);}           // ↻
      else if(GamePad.isTrianglePressed())  {go_right_forward(255);}  // ⇗
      else if(GamePad.isCrossPressed())     {go_right_backward(255);} // ⇘
      else                                  {go_right(255);}          // ⇨
    }
    else if(GamePad.isUpPressed())          {go_forward(255);}        // ⇧
    else if(GamePad.isDownPressed())        {go_backward(255);}       // ⇩
    else                                    {stop();}                 // Stop!
  }
  else
  {
    /* ---------------------------- Joystick Mode --------------------------- */
    if(GamePad.isCirclePressed())       {turn_CW(max);}   // ↻
    else if(GamePad.isSquarePressed())  {turn_CCW(max);}  // ↺
    else
    {
      switch(a)
      {
        // Angle from 0° - 45°
        case 0:
        case 15:
        case 30:  motor_BR_forward(max);
                  motor_BL_backward(map(a, 0, 45, max, 0));
                  motor_FR_backward(map(a, 0, 45, max, 0));
                  motor_FL_forward(max);
                  break;
        // Angle from 45° - 90°
        case 45:
        case 60:
        case 75:  motor_BR_forward(max);
                  motor_BL_forward(map(a, 45, 90, 0, max));
                  motor_FR_forward(map(a, 45, 90, 0, max));
                  motor_FL_forward(max);
                  break;
        // Angle from 90° - 135°
        case 90:
        case 105:
        case 120: motor_BR_forward(map(a, 90, 135, max, 0));
                  motor_BL_forward(max);
                  motor_FR_forward(max);
                  motor_FL_forward(map(a, 90, 135, max, 0));
                  break;
        // Angle from 135° - 180°
        case 135:
        case 150:
        case 165: motor_BR_backward(map(a, 135, 180, 0, max));
                  motor_BL_forward(max);
                  motor_FR_forward(max);
                  motor_FL_backward(map(a, 135, 180, 0, max));
                  break;
        // Angle from 180° - 225°
        case 180:
        case 195:
        case 210: motor_BR_backward(max);
                  motor_BL_forward(map(a, 180, 225, max, 0));
                  motor_FR_forward(map(a, 180, 225, max, 0));
                  motor_FL_backward(max);
                  break;
        // Angle from 225° - 270°
        case 225:
        case 240:
        case 255: motor_BR_backward(max);
                  motor_BL_backward(map(a, 225, 270, 0, max));
                  motor_FR_backward(map(a, 225, 270, 0, max));
                  motor_FL_backward(max);
                  break;
        // Angle from 270° - 315°
        case 270:
        case 285:
        case 300: motor_BR_backward(map(a, 270, 315, max, 0));
                  motor_BL_backward(max);
                  motor_FR_backward(max);
                  motor_FL_backward(map(a, 270, 315, max, 0));
                  break;
        // Angle from 315° - 360° = (0°)
        case 315:
        case 330:
        case 345: motor_BR_forward(map(a, 315, 360, 0, max));
                  motor_BL_backward(max);
                  motor_FR_backward(max);
                  motor_FL_forward(map(a, 315, 360, 0, max));
      }
    }
  }
}

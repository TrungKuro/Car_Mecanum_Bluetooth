/*
 *- Các tập lệnh AT cho HC-06 ----------------------------|
 *    AT            kiểm tra kết nối                      |
 *    AT+NAME...    thay đổi tên                          |--> name: Car_HC-06
 *    AT+BAUD...    với 1 set to 1200 bps                 |
 *                      2 set to 2400   bps               |
 *                      3 set to 4800   bps               |
 *                      4 set to 9600   bps (mặc định)    |--> baud rate: 9600 bps
 *                      5 set to 19200  bps               |
 *                      6 set to 38400  bps               |
 *                      7 set to 57600  bps               |
 *                      8 set to 115200 bps               |
 *    AT+PIN...   cài đặt mã PIN (mặc định: 1234)         |--> pass: 1234
 *--------------------------------------------------------|
 *
 *- Các tín hiệu gửi liên tục ------------------------------------|
 *    S       Ko làm gì (stop)  |   . Xe đứng yên                 |
 *    F       Tiến              |   . (Chiều dọc) - Đi tới        |
 *    B       Lùi               |   . (Chiều dọc) - Đi lùi        |
 *    L       Trái              |   . (Chiều ngang) - Đi qua trái |
 *    R       Phải              |   . (Chiều ngang) - Đi qua phải |
 *  --------------------------- KO QUAY XE -----------------------|
 *    G       Tiến + Trái       | . Đi hướng Tây-Bắc              |
 *    I       Tiến + Phải       | . Đi hướng Đông-Bắc             |
 *    H       Lùi  + Trái       | . Đi hướng Tây-Nam              |
 *    J       Lùi  + Phải       | . Đi hướng Đông-Nam             |
 *----------------------------------------------------------------|
 *
 *- Các tín hiệu gửi 1 lần -|
 *    0     Tốc độ MIN      |
 *    1     ...             |
 *    2     ...             |
 *    3     ...             |
 *    4     ...             |
 *    5     ...             |
 *    6     ...             |
 *    7     ...             |
 *    8     ...             |
 *    9     ...             |
 *    q     Tốc độ MAX      |
 *  ------------------------|
 *    W       Bật đèn trước |
 *    w       Tắt đèn trước |
 *    U       Bật đèn sau   |
 *    u       Tắt đèn sau   |
 *    V       Bật còi       |
 *    v       Tắt còi       |
 *  ------------------------|
 *    X       Bật cảnh báo  |
 *    x       Tắt cảnh báo  |
 *  ------------------------|-------------------|
 *    D       Tắt hết tất cả (stop everything)  |
 *----------------------------------------------|
 */

#include "Control_Car_Bluetooth.h"
#include "Pin_Connect.h"
#include <SoftwareSerial.h>

byte blue = 0;                  // Biến nhận dữ liệu qua bluetooth
bool warning = false;           // Mode "Mecanum Wheels Robot" (Mặc định)
SoftwareSerial mySerial(2, 3);  // RX, TX

// --------------------------------------------------------------------------------------------------------------------------------- //

void setup()
{
  mySerial.begin(9600);

  /*
   *  Chiều kim đồng hồ         : Clockwise           | CW  : 1
   *  Ngược chiều kim đồng hồ   : Counter-Clockwise   | CCW : 0
   * 
   *  !!! Đây là chiều quay của các Pin dưới đây khi kích "HIGH"
   */

  pinMode(MOTOR_FR_IN1, OUTPUT);  // Front - Right    | + CW  : 1
  pinMode(MOTOR_FR_IN2, OUTPUT);  //                  | - CCW : 0
  pinMode(MOTOR_FL_IN3, OUTPUT);  // Front - Left     | + CW  : 1
  pinMode(MOTOR_FL_IN4, OUTPUT);  //                  | - CCW : 0

  pinMode(MOTOR_BR_IN1, OUTPUT);  // Behind - Right   | + CW  : 1
  pinMode(MOTOR_BR_IN2, OUTPUT);  //                  | - CCW : 0
  pinMode(MOTOR_BL_IN3, OUTPUT);  // Behing - Left    | + CW  : 1
  pinMode(MOTOR_BL_IN4, OUTPUT);  //                  | - CCW : 0
}

/*
 *  SƠ ĐỒ HƯỚNG LẮP BÁNH CỦA XE
 * 
 *              ^
 *      FL      |      FR
 *       \      |      /
 *        \-----|-----/
 *        |\         /|
 *        |           |
 *        |           |
 *        |     .     |
 *        |           |
 *        |           |
 *        |/         \|
 *        /-----------\
 *       /             \
 *      BL             BR
 */

// --------------------------------------------------------------------------------------------------------------------------------- //

void processed()
{
  switch(blue)
  {
    case 'S': stop_car();           break;  // Dừng xe (ko làm gì cả)

    case 'F': go_forward();         break;  // Xe đi về phía trước (chiều dọc)
    case 'B': back_forward();       break;  // Xe đi lùi về phía sau (chiều dọc)

    case 'L': go_left();            break;  // Xe đi sang trái (chiều ngang)
    case 'R': go_right();           break;  // Xe đi sang phải (chiều ngang)

    case 'G': if(warning) turn_CCW();       // Xe quay ngược chiều đồng hồ (CCW)
              else go_left_forward();       // Xe đi thẳng về phía trái
              break;
    case 'I': if(warning) turn_CW();        // Xe quay chiều đồng hồ (CW)
              else go_right_forward();      // Xe đi thẳng về phía phải
              break;
    
    case 'H': if(warning) turn_CW();        // Xe quay chiều đồng hồ (CW)
              else back_left_forward();     // Xe đi lùi về phía trái
              break;
    case 'J': if(warning) turn_CCW();       // Xe quay ngược chiều đồng hồ (CCW)
              else back_right_forward();    // Xe đi lùi về phía phải
              break;
    
    case 'X': warning = true;   break;  // Mode "Normal"
    case 'x': warning = false;  break;  // Mode "Mecanum"
  }
}

// --------------------------------------------------------------------------------------------------------------------------------- //

void loop()
{
  if(mySerial.available()>0)  // Nếu có dữ liệu gửi về thì đọc
  {
    blue = mySerial.read();
    processed();              // Hàm xử lý các tín hiệu
  }
}

// --------------------------------------------------------------------------------------------------------------------------------- //

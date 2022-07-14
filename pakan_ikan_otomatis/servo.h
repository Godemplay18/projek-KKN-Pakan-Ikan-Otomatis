#ifndef SERVO_H
#define SERVO_H

#include <Servo.h>

Servo servo1; Servo servo2; //Servo servo3

int jumlah_ikan, berat_ikan, dly;

void servoSetup () {
  servo1.attach (8);
  servo2.attach (9);
  //servo3.attach (10);

  servo1.write (0);
  servo2.write (0);
}

void servoPakanOpen () {
  if (berat_ikan < 2) {
    if (jumlah_ikan < 700) {
      dly = 3000;
    }
    if (jumlah_ikan > 700) {
      dly = 5000;
    }
  }
  
  if (berat_ikan > 2) {
    if (jumlah_ikan < 700) {
      dly = 3000;
    }
    if (jumlah_ikan > 700) {
      dly = 5000;
    }
  }
  servo1.write (180);
  delay (dly);
  servo1.write (0);
}

void servoMixOpen () {
  servo2.write (180);
  delay (5000);
  servo2.write (0);
}


#endif

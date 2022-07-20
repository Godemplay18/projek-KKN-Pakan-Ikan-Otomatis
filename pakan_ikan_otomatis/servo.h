#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>
#include "bluetooth.h"

Servo servo1; Servo servo2;
int dly;

void servoSetup () {
  servo1.attach (32);
  servo2.attach (33);

  servo1.write (0);
  servo2.write (0);
}

void servoPakanOpen () {
  dly = (jumlah_pakan*1000);//bps
 
  servo1.write (90);
  delay (dly);
  servo1.write (0);
}

void servoMixOpen () {
  servo2.write (90);
  delay (5000);
  servo2.write (0);
}


#endif

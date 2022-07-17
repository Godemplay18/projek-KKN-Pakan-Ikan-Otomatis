#ifndef SERVO_H
#define SERVO_H

#include <Servo.h>

Servo servo1; Servo servo2;

int jumlah_ikan, berat_ikan, dly, berat_pakan;

void servoSetup () {
  servo1.attach (32);
  servo2.attach (33);

  servo1.write (0);
  servo2.write (0);
}

void servoPakanOpen () {
  dly = (berat_pakan*1000);//bps
 
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

#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>
#include "bluetooth.h"

Servo servo1; Servo servo2;
int dly;

int tutup_pakan = 60; 
int pinPakan = 32;
int pinMix = 33;

void servoSetup () {
  servo1.attach (pinPakan);
  servo2.attach (pinMix);

  servo1.write (tutup_pakan);
  servo2.write (0);
}

void servoPakanOpen () {
  dly = (jumlah_pakan*1000)/100;//bps
 
  servo1.write (150);
  delay (dly);
  servo1.write (tutup_pakan);
}

void servoMixOpen () {
  servo2.write (180);
  delay (5000);
  servo2.write (0);
}


#endif

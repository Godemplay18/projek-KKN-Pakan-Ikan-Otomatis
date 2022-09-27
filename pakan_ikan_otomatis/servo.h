#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>

Servo servo1; Servo servo2;
int dly;

const int pinPakan = 33; const int pinMix = 32;

void servoSetup () {
  servo1.attach (pinPakan);
  servo2.attach (pinMix);

  servo1.write (0);
  servo2.write (180);
}

void servoPakanOpen () {
  dly = (200 * 1000) / 150; //bps
  Serial.println("Servo Pakan Open");
  servo1.write (35);
  delay (dly);
  servo1.write (0);
  delay (1000);
  Serial.println("Servo Pakan Open");
}

void servoMixOpen () {
  Serial.println("Servo Mix Open");
  servo2.write (75);
  delay (2000);
  servo2.write (180);
  delay (2000);
  Serial.println("Servo Mix Tutup");
}


#endif

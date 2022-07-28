#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>

Servo servo1; Servo servo2;
int dly;

int pinPakan = 32; int tutup_pakan = 60;
int pinMix = 33; int tutup_mix = 45;

void servoSetup () {
  servo1.attach (pinPakan);
  servo2.attach (pinMix);

  servo1.write (tutup_pakan);
  servo2.write (tutup_mix);
}

void servoPakanOpen () {
  dly = (jumlah_pakan * 1000) / 100; //bps
  Serial.println("Servo Pakan Open");
  servo1.write (150);
  delay (dly);
  servo1.write (60);
  delay (1000);
}

void servoMixOpen () {
  Serial.println("Servo Mix Open");
  servo2.write (180);
  delay (2000);
  servo2.write (45);
  delay (2000);
  Serial.println("Servo Mix Tutup");
}


#endif

.#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>

Servo servo1; Servo servo2;
int dly;

int pinPakan = 33; int tutup_pakan = 180;
int pinMix = 32; int tutup_mix = 45;

void servoSetup () {
  servo1.attach (pinPakan);
  servo2.attach (pinMix);

  servo1.write (tutup_pakan);
  servo2.write (tutup_mix);
}

void servoPakanOpen () {
  dly = (jumlah_pakan * 1000) / 100; //bps
  Serial.println("Servo Pakan Open");
  servo1.write (0);
  delay (dly);
  servo1.write (tutup_pakan);
  delay (1000);
  Serial.println("Servo Pakan Open");
}

void servoMixOpen () {
  Serial.println("Servo Mix Open");
  servo2.write (180);
  delay (2000);
  servo2.write (tutup_mix);
  delay (2000);
  Serial.println("Servo Mix Tutup");
}


#endif

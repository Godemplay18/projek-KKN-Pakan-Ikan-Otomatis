#ifndef L298N_H
#define L298N_H
#include "servo.h"


int dly2;
int perisPin1 = 4;
int perisPin2 = 15;

void l298nSetup (){
  pinMode(perisPin1, OUTPUT);
  pinMode(perisPin2, OUTPUT);
}

void probPump (){
  dly2 = (jumlah_pakan*250)/10;//pbs;
  digitalWrite(perisPin1, LOW);
  digitalWrite(perisPin2, HIGH);
  delay(dly2);
  digitalWrite(perisPin1, LOW);
  digitalWrite(perisPin2, LOW);
}


#endif

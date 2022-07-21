#ifndef BTS_H
#define BTS_H
#include "btsmix.h"

// BTS7960
int M_en = 14; int Rpwm = 12; int Lpwm = 13;

void btsSetup (){
  pinMode(M_en, OUTPUT); pinMode(Rpwm, OUTPUT); pinMode(Lpwm, OUTPUT);

  ledcSetup(R_channel, R_freq, R_res);
  ledcSetup(L_channel, L_freq, L_res);
  ledcAttachPin(Rpwm, R_channel);
  ledcAttachPin(Lpwm, L_channel);
}

void lemparPakan (){
  
  digitalWrite(M_en, HIGH);
  ledcWrite(R_channel, 200);
  ledcWrite(L_channel, 0);
  delay(3000);
  digitalWrite(M_en, LOW);
}

#endif

#ifndef BTSMIX_H
#define BTSMIX_H

int M_en2 = 14; int Rpwm2 = 12; int Lpwm2 = 13;
const int R_freq2 = 30000; const int R_channel2 = 2; const int R_res2 = 8;
const int L_freq2 = 30000; const int L_channel2 = 3; const int L_res2 = 8;

void btsMixSetup (){
  pinMode(M_en2, OUTPUT); pinMode(Rpwm2, OUTPUT); pinMode(Lpwm2, OUTPUT);

  ledcSetup(R_channel2, R_freq2, R_res2);
  ledcSetup(L_channel2, L_freq2, L_res2);
  ledcAttachPin(Rpwm2, R_channel2);
  ledcAttachPin(Lpwm2, L_channel2);
}

void mixPakan (){
  digitalWrite(M_en2, HIGH);
  ledcWrite(R_channel2, 255);
  ledcWrite(L_channel2, 0);
  delay(180000);
  digitalWrite(M_en2, LOW);
  delay(900000);
}

#endif

#ifndef BTSMIX_H
#define BTSMIX_H

// BTS7960 (2)
int M_en2 = 17; int Rpwm2 = 15; int Lpwm2 = 16;

void btsMixSetup (){
  pinMode(M_en2, OUTPUT); pinMode(Rpwm2, OUTPUT); pinMode(Lpwm2, OUTPUT);

  ledcSetup(R_channel, R_freq, R_res);
  ledcSetup(L_channel, L_freq, L_res);
  ledcAttachPin(Rpwm2, R_channel);
  ledcAttachPin(Lpwm2, L_channel);
}

void mixPakan (){
  digitalWrite(M_en2, HIGH);
  ledcWrite(R_channel, 150);
  ledcWrite(L_channel, 0);
  delay(180000);
  digitalWrite(M_en2, LOW);
}

#endif

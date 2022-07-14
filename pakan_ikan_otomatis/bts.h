#ifndef BTS_H
#define BTS_H


// BTS7960
int M_en = 14; int Rpwm = 12; int Lpwm = 13;
const int R_freq = 30000; const int R_channel = 0; const int R_res = 8;
const int L_freq = 30000; const int L_channel = 1; const int L_res = 8;

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
  delay(5000);
  digitalWrite(M_en, LOW);
}

#endif

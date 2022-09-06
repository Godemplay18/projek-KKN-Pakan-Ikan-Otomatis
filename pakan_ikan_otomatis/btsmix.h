#ifndef BTSMIX_H
#define BTSMIX_H

int M_en2 = 5; int Rpwm2 = 18; int Lpwm2 = 19;
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
  Serial.println("Aduk Pakan");
  digitalWrite(M_en2, HIGH);
  ledcWrite(R_channel2, 0);
  ledcWrite(L_channel2, 300);
  delay(5000);
  digitalWrite(M_en2, LOW);
  delay(10000);
}

#endif

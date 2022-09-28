#ifndef L298N_H
#define L298N_H

//peristaltik;
int dly2;
int perisPin1 = 25;
int perisPin2 = 26;

//pelontar
const int M_en = 12; const int in3 = 27; const int in4 = 14;
const int R_freq = 60000; const int R_channel = 0; const int R_res = 8;
const int L_freq = 60000; const int L_channel = 1; const int L_res = 8;


void l298nSetup () {
  pinMode(perisPin1, OUTPUT);
  pinMode(perisPin2, OUTPUT);

  pinMode(M_en, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  ledcSetup(R_channel, R_freq, R_res);
  ledcSetup(L_channel, L_freq, L_res);
  ledcAttachPin(in3, R_channel);
  ledcAttachPin(in4, L_channel);
}

void probPump () {
  dly2 = (jumlah_pakan * 250) / 14.7; //pbs;
  Serial.println("Probiotik");
  digitalWrite(perisPin1, LOW);
  digitalWrite(perisPin2, HIGH);
  delay(dly2);
  digitalWrite(perisPin1, LOW);
  digitalWrite(perisPin2, LOW);
}

void lemparPakan () {
  Serial.println("Lempar Pakan");
  digitalWrite(M_en, HIGH);
  ledcWrite(R_channel, 50000);
  ledcWrite(L_channel, 0);
  delay(5000);
  digitalWrite(M_en, LOW);
  delay(2000);
}

#endif

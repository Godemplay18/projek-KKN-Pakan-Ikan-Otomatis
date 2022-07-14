#ifndef L298N_H
#define L298N_H

int perisPin1 = 27;
int perisPin2 = 26;
//int motor2Pin1 = 25;
//int motor2Pin2 = 33;

void l298nSetup (){
  pinMode(perisPin1, OUTPUT);
  pinMode(perisPin2, OUTPUT);
  //pinMode(motor2Pin1, OUTPUT);
  //pinMode(motor2Pin2, OUTPUT);
}

void probPump (){
  digitalWrite(perisPin1, LOW);
  digitalWrite(perisPin2, HIGH);
  //digitalWrite(motor2Pin1, HIGH);
  //digitalWrite(motor2Pin2, LOW);
  delay(10000);
  digitalWrite(perisPin1, LOW);
  digitalWrite(perisPin2, LOW);
}


#endif

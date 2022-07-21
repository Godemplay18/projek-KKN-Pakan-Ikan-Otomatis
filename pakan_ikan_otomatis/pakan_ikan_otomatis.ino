#include <Wire.h>
#include <EEPROM.h>
#include "bluetooth.h"
#include "bts.h"
#include "btsmix.h"
#include "l298n.h"
#include "rtc.h"
#include "servo.h"

unsigned long previousMillis = 0;

void setup() {
  Serial.begin (115200);
  btSetup();
  btsSetup();
  btsMixSetup();
  l298nSetup();
  rtcSetup();
  servoSetup();
  loadSetting();

}

void loop() {
  bacaInput();
  cetakJam();
  Serial.println (prefs.getInt("Pagi"));
  Serial.println (prefs.getInt("Siang"));
  Serial.println (prefs.getInt("Malam"));
  Serial.println (prefs.getInt("Jumlah Pakan"));
 
  
  for (int a = 0; a < 3; a++) {
    int waktu [] = {pagi, siang, malam};
    if (jam == waktu [a] && menit == 00) {
      servoPakanOpen ();
      probPump();
      mixPakan();

      unsigned long currentMillis = millis();
      if (previousMillis - currentMillis <= 900000) {
        previousMillis = currentMillis;
        if (previousMillis - currentMillis >= 60000) {
          previousMillis = currentMillis;
          servoMixOpen();
          delay (2000);
          lemparPakan();
        }
      }
    }
  }
}


////////////////////////////////////////////////////////////////////////////////
void loadSetting(){
  prefs.getInt("Pagi");
  prefs.getInt("Siang");
  prefs.getInt("Malam");
  prefs.getInt("Jumlah Pakan");
  
}

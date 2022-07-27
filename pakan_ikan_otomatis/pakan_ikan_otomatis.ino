#include <Wire.h>
#include <EEPROM.h>
#include "bluetooth.h"
#include "bts.h"
#include "btsmix.h"
#include "l298n.h"
#include "rtc.h"
#include "servo.h"

unsigned long previousMillis = 0;
int x = true;

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
  /*
    Serial.println (prefs.getInt("Pagi"));
    Serial.println (prefs.getInt("Siang"));
    Serial.println (prefs.getInt("Malam"));
    Serial.println (prefs.getInt("Jumlah Pakan"));
  */
  Serial.println (pagi); Serial.println (siang);
  Serial.println (malam); Serial.println (jumlah_pakan);



  for (int a = 0; a < 3; a++) {
    int waktu [] = {pagi, siang, malam};
    if (jam == waktu [a] && menit == 20 ) {
      if (x == true) {
        servoPakanOpen ();
        probPump();
        mixPakan();
        x = false;
      }

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

    else {
      x = true;
    }
  }
}


////////////////////////////////////////////////////////////////////////////////
void loadSetting() {
  pagi = prefs.getInt("Pagi");
  siang = prefs.getInt("Siang");
  malam = prefs.getInt("Malam");
  jumlah_pakan = prefs.getInt("Jumlah Pakan");

}

#include <Wire.h>
#include <EEPROM.h>
#include "bluetooth.h"
#include "btsmix.h"
#include "l298n.h"
#include "rtc.h"
#include "servo.h"

unsigned long previousMillis = 0;
int x = true;


void setup() {
  Serial.begin (115200);
  btSetup();
  btsMixSetup();
  l298nSetup();
  rtcSetup();
  servoSetup();
  loadSetting();

}

void loop() {
  bacaInput();
  cetakJam();

  Serial.println (pagi); Serial.println (siang);
  Serial.println (malam); Serial.println (jumlah_pakan);


  int waktu [] = {pagi, siang, malam};
  for (int a = 0; a < 3; a++) {
    if (jam == waktu [a] && menit == 00) {

      servoPakanOpen ();
      probPump();
      mixPakan();

      unsigned long checkpoint_15 = millis ();
      while (millis () - checkpoint_15 <=  60 * 1000) {
        unsigned long checkpoint_1 = millis ();

        servoMixOpen();
        lemparPakan();
        while (millis () - checkpoint_1 <= 10000) {

        }
      }
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

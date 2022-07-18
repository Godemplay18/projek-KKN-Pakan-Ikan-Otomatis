#include <Wire.h>
#include <EEPROM.h>
#include "bts.h"
#include "btsmix.h"
#include "l298n.h"
#include "rtc.h"
#include "servo.h"



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
  lcd.clear();
  bacaInput();
  if (siang == 0) {
    siang = false;
  }
  cetakJam();
  saveSetting();
  loadSetting();
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
void saveSetting () {
  //EEPROM.put (8, bulan_ikan);
  //EEPROM.put (9, berat_ikan);
  EEPROM.put (10, jumlah_pakan);
  EEPROM.put (11, pagi);
  EEPROM.put (12, siang);
  EEPROM.put (13, malam);
}

void loadSetting() {
  //EEPROM.get (8, bulan_ikan);
  //EEPROM.get (9, berat_ikan);
  EEPROM.get (10, jumlah_pakan);
  EEPROM.get (11, pagi);
  EEPROM.get (12, siang);
  EEPROM.get (13, malam);
}

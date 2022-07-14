#include <Wire.h>
#include <EEPROM.h>
#include "bluetooth.h"
#include "bts.h"
#include "btsmix.h"
#include "l298n.h"
#include "rtc.h"
#include "servo.h"


int bulan_ikan;
int pagi, siang, malam;

void setup() {
  Serial.begin (115200);
  btsSetup();
  l298nSetup();
  btsMixSetup();
  servoSetup();

  loadSetting();

}

void loop() {
  lcd.clear();
  /*
    codingan buat ngambil data dari aplikasi
    (jumlah_ikan, berat_ikan, bulan_ikan, pagi, siang, malam)
  */

  cetakJam();
  saveSetting();
  loadSetting();
  if (bulan_ikan <= 1) {
    for (int a = 0; a < 2; a++) {
      int waktu1 [] = {pagi, malam};
      if (jam == waktu1 [a] && menit == 00) {
        unsigned long currentMillis = millis();
        if (previousMillis - currentMillis <= 900000) {
          previousMillis = currentMillis;
          if (previousMillis - currentMillis < 60000) {
            servoPakanOpen ();
            delay (2000);
            servoMixOpen();
            delay (2000);
            lemparPakan();
          }
        }
      }
    }
  }

  if (bulan_ikan > 1) {
    for (int a = 0; a < 3; a++) {
      int waktu2 [] = {pagi, siang, malam};
      if (jam == waktu2 [a] && menit == 00) {
        unsigned long currentMillis = millis();
        if (previousMillis - currentMillis <= 900000) {
          previousMillis = currentMillis;
          if (previousMillis - currentMillis < 60000) {
            servoPakanOpen ();
            delay (2000);
            servoMixOpen();
            delay (2000);
            lemparPakan();
          }
        }
      }
    }
  }

}
////////////////////////////////////////////////////////////////////////////////
void saveSetting () {
  EEPROM.write (8, bulan_ikan);
  EEPROM.write (9, berat_ikan);
  EEPROM.write (10, jumlah_ikan);
  EEPROM.write (11, pagi);
  EEPROM.write (12, siang);
  EEPROM.write (13, malam);
}


void loadSetting() {
  bulan_ikan = EEPROM.read (8);
  berat_ikan = EEPROM.read (9);
  jumlah_ikan = EEPROM.read (10);
  pagi = EEPROM.read (11);
  siang = EEPROM.read (12);
  malam = EEPROM.read (13);
}

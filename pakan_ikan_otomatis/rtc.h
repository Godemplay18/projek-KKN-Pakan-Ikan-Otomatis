#ifndef RTC_H
#define RTC_H

#include "Arduino.h"
#include <Wire.h>
#include "uRTCLib.h"

// uRTCLib rtc;
uRTCLib rtc(0x68);

int jam, menit, detik;

void rtcSetup() {
  Serial.println("Serial OK");

#ifdef ARDUINO_ARCH_ESP8266
  URTCLIB_WIRE.begin(0, 2); // D3 and D4 on ESP8266
#else
  URTCLIB_WIRE.begin();
#endif

  //rtc.set(0, 15, 15, 2, 26, 7, 22);
  //  RTCLib::set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
}

void cetakJam() {
  rtc.refresh();
  //tahun = rtc.year();
  //bulan = rtc.month();
  //hari = rtc.day();

  jam = rtc.hour();
  menit = rtc.minute();
  detik = rtc.second();

  Serial.print(jam);
  Serial.print(':');
  Serial.print(menit);
  Serial.print(':');
  Serial.println(detik);
  Serial.println();
  SerialBT.println(String(rtc.hour()) + ":" + String (rtc.minute()));
  delay(1000);
}

#endif

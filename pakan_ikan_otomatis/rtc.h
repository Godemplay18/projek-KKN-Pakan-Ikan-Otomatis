#ifndef RTC_H
#define RTC_H

#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>
// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(6, 7, 8); //PIN (CLK, DATE, RST)

LiquidCrystal_I2C lcd(0x27, 16, 2);

int menit, jam, tanggal, bulan, tahun;

const long interval = 1000;
unsigned long previousMillis = 0;

void rtcSetup()  {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0); lcd.print("PAKAN IKAN");
  lcd.setCursor(1, 1); lcd.print("OTOMATIS");
  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
  myRTC.setDS1302Time(00, 16, 13, 4, 14, 7, 2022);
}

void cetakJam()  {
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();
  menit = myRTC.minutes; jam = myRTC.hours;
  tanggal = myRTC.dayofmonth; bulan = myRTC.month; tahun = myRTC.year;
  unsigned long currentMillis = millis ();

  if (currentMillis - previousMillis == interval) {
    previousMillis = currentMillis;
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print(jam); lcd.print(":"); lcd.print(menit);
    //lcd.print(":");
    //lcd.print(myRTC.seconds);
    Serial.print(jam); Serial.print(":"); Serial.print(menit);
    //Serial.print(":");
    //Serial.println(myRTC.seconds);

    lcd.setCursor(3, 1);
    lcd.print(tanggal); lcd.print("/"); lcd.print(bulan);
    lcd.print("/"); lcd.print(tahun);
    Serial.print(tanggal); Serial.print("/");
    Serial.print(bulan);  Serial.print("/");
    Serial.print(tahun); Serial.println("  ");
  }
}

#endif

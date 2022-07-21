#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothSerial.h"
#include <Preferences.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
Preferences prefs;

String cmd, str_P, str_S, str_M, str_J;
int pagi, siang, malam, jumlah_pakan;

void btSetup() {
  SerialBT.begin("MAKAN"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  prefs.begin("pakan");
}

void saveSetting () {
  prefs.putInt("Pagi", pagi);
  prefs.putInt("Siang", siang);
  prefs.putInt("Malam", malam);
  prefs.putInt("Jumlah Pakan", jumlah_pakan);
}

void bacaInput() {
  if (SerialBT.available () == 0) {
    return;
  }

  while (SerialBT.available()) {
    cmd = SerialBT.readString();
  }

  Serial.println(cmd);

  int prefix_1 = cmd.indexOf("p");
  int prefix_2 = cmd.indexOf("s");
  int prefix_3 = cmd.indexOf("m");
  int prefix_4 = cmd.lastIndexOf("j");

  str_P = cmd.substring (0, prefix_1);
  str_S = cmd.substring (prefix_1 + 1, prefix_2);
  str_M = cmd.substring (prefix_2 + 1, prefix_3);
  str_J = cmd.substring (prefix_3 + 1, prefix_4);

  pagi = str_P.toInt();
  siang = str_S.toInt();
  malam = str_M.toInt();
  jumlah_pakan = str_J.toInt();
  saveSetting ();
  /*Serial.println("");
    Serial.println("===========================");
    Serial.print("Pagi : ");
    Serial.println(pagi);
    Serial.print("Siang : ");
    Serial.println(siang);
    Serial.print("Malam : ");
    Serial.println(malam);
    Serial.print("Jumlah Pakan : ");
    Serial.println(jumlah_pakan);
    Serial.println("===========================");*/
  delay (1000);
}



#endif

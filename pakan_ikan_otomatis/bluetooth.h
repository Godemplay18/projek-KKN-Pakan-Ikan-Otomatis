#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void btSetup() {
  Serial.begin(115200);
  SerialBT.begin("PAKAN IKAN"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void bacaInput() {
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}


#endif

#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial bluetoothSerial;

void setup() {
    bluetoothSerial.begin("M5Stack Device");
    Serial.begin(115200);
}

void loop() {
    if (Serial.available()) {
        bluetoothSerial.write(Serial.read());
    }
    if (bluetoothSerial.available()) {
        Serial.write(bluetoothSerial.read());
    }
}
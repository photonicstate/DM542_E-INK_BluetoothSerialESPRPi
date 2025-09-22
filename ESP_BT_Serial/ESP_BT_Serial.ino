#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
unsigned long lastSend = 0;

void setup() {
  Serial.begin(115200);

  if (!SerialBT.begin("ESP32_BT")) {   // Назва пристрою
    Serial.println("Помилка ініціалізації Bluetooth!");
    while (true);
  }

  Serial.println("✅ ESP32 готовий до з’єднання");
}

void loop() {
  // 1️⃣ Прийом даних з Raspberry Pi
  if (SerialBT.available()) {
    String msg = SerialBT.readStringUntil('\n');
    Serial.print("📩 Отримано від Raspberry Pi: ");
    Serial.println(msg);

    // Відповідь у консоль
    SerialBT.println("ESP32 отримав: " + msg);
  }

  // 2️⃣ Відправка даних із Serial Monitor на Raspberry Pi
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    SerialBT.println("ESP32 каже: " + msg);
  }
}
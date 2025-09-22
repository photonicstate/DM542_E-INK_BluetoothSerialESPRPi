# E-Ink Display

- Приклад роботи з ним, також pinout є в **GxEPD2_HelloWorld_test\\GxEPD2_HelloWorld_test.ino**
- Необхідна бібліотека: <https://github.com/ZinggJM/GxEPD2> (можна скачати в Arduino IDE через Library Manager)

# DM542 with STM32

- Приклад роботи з ним, також pinout є в **STM32F411CEU6_DM542\\Core\\src\\main.c**
- Схема підключення (без врахування потенціометра):  
  
![Reference image](/_images/dm542_stm32.png)  
  
**якщо MCU має 5-ти вольтову логіку, то конвертора логічних рівнів не треба**

# Bluetooth ESP32<->RaspberryPi
- Код для ESP32 **ESP_BT_Serial\\ESP_BT_Serial.ino**
- Код для Raspberry Pi **RPi_BT_Serial\\RPi_BT_Serial.py**
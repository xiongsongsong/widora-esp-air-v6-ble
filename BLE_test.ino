/*
  Deep Sleep with Touch Wake Up
  =====================================
  This code displays how to use deep sleep with
  a touch as a wake up source and how to store data in
  RTC memory to use it over reboots

  This code is under Public Domain License.

  Author:
  Pranav Cherukupalli <cherukupallip@gmail.com>
*/

#define Threshold 45 /* Greater the value, more the sensitivity */
#include "ESP32BleAdvertise.h"

RTC_DATA_ATTR int bootCount = 0;

void callback() {
  
}

void setup() {
  Serial.begin(921600);
  Serial.println("Boot number: " + String(  ++bootCount  ));

  SimpleBLE ble;
  ble.begin("3ab87438");
  ble.advertise(String(bootCount));
  delay(1000);
  touchAttachInterrupt(GPIO_NUM_15, callback, Threshold);
  esp_deep_sleep_enable_touchpad_wakeup();

  Serial.println("Going to sleep now");
  esp_deep_sleep_start();
  Serial.println("This will never be printed");
}

void loop() {
  //This will never be reached
}

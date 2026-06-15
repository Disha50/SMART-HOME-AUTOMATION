#include <WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID "YOUR_WIFI"
#define WIFI_PASS "YOUR_PASSWORD"

#define APP_KEY "YOUR_APP_KEY"
#define APP_SECRET "YOUR_APP_SECRET"

#define LIGHT_PIN 23
#define FAN_PIN 22
#define CHARGER_PIN 21

bool onPowerState(const String &deviceId, bool &state) {

  if (deviceId == "LIGHT_ID")
    digitalWrite(LIGHT_PIN, state);

  if (deviceId == "FAN_ID")
    digitalWrite(FAN_PIN, state);

  if (deviceId == "CHARGER_ID")
    digitalWrite(CHARGER_PIN, state);

  return true;
}

void setup() {

  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(CHARGER_PIN, OUTPUT);

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  SinricProSwitch &light = SinricPro["LIGHT_ID"];
  light.onPowerState(onPowerState);

  SinricProSwitch &fan = SinricPro["FAN_ID"];
  fan.onPowerState(onPowerState);

  SinricProSwitch &charger = SinricPro["CHARGER_ID"];
  charger.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
}

void loop() {
  SinricPro.handle();
}

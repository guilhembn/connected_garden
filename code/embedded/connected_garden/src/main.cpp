#include <Arduino.h>
#include <WiFiHandler.h>
#include <Datetime.h>

WiFiHandler wifi;
Datetime datetime;
void setup() {
  Serial.begin(115200);
  wifi = WiFiHandler("MywifiSSID", "Mywificode");
}

void loop() {
  if (wifi.isWiFiNetworkAvailable()){
    Serial.println("network available");
    wifi.connect();
    time_t now = datetime.now();
    Serial.print("Formatted Time: ");
    Serial.println(datetime.toStr(now));
  }
  delay(500000000);
}
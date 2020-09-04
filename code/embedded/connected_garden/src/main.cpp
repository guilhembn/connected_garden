#include <Arduino.h>
#include <WiFiHandler.h>

WiFiHandler wifi;
void setup() {
  Serial.begin(115200);
  wifi = WiFiHandler("MywifiSSID", "Mywificode");
}

void loop() {
  if (wifi.isWiFiNetworkAvailable()){
    Serial.println("network available");
    wifi.connect();
  }
  delay(500000000);
}
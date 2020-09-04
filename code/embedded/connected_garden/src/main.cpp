#include <Arduino.h>
#include <WiFiHandler.h>
#include <Datetime.h>
#include <EEPROMManager.h>
#include <StoredData.h>

WiFiHandler wifi;
Datetime datetime;
EEPROMManager eepromManager;


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

    //eepromManager.clearStoredData();

    //StoredData data1 = {.timestamp = now, .temperature = -10};
    //StoredData data2 = {.timestamp = now + 3600, .temperature = 50};
    //eepromManager.saveData(&data1);
    //eepromManager.saveData(&data2);

    StoredData dataLoaded[50];
    unsigned int n = eepromManager.loadData(dataLoaded);
    for (unsigned int i = 0; i < n; i++){
      Serial.println("Loaded data: ");
      Serial.print(datetime.toStr(dataLoaded[i].timestamp));
      Serial.print(" @ ");
      Serial.print(dataLoaded[i].temperature);
      Serial.println();
    }

  }
  ESP.deepSleep(5 * 1000000);
  delay(500000000);
}
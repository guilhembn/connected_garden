#include <Arduino.h>
#include <Config.h>
#include <WiFiHandler.h>
#include <Datetime.h>
#include <EEPROMManager.h>
#include <StoredData.h>
#include <DHT11.h>

WiFiHandler wifi;
Datetime datetime;
EEPROMManager eepromManager;
DHT11 dht11;


void setup() {
  Serial.begin(115200);
  wifi = WiFiHandler(NETWORK_SSID, NETWORK_PASSWORD);
  dht11.setup(D1);
}

void loop() {
  if (wifi.isWiFiNetworkAvailable()){
    Serial.println("network available");
    wifi.connect();
    time_t now = datetime.now();
    Serial.print("Formatted Time: ");
    Serial.println(datetime.toStr(now));

    //eepromManager.clearStoredData();

    uint16_t temp, hum;
    if (!dht11.measure(&hum, &temp)){
      Serial.println("Error while reading DHT11");
      ESP.deepSleep(5 * 1000000);
    }

    Serial.println("DHT11 read:");
    Serial.print(temp);
    Serial.print("°C and ");
    Serial.print(hum);
    Serial.println("% humidity");

    StoredData data = {.timestamp = now, .temperature = temp, .humidity = hum};
    //StoredData data2 = {.timestamp = now + 3600, .temperature = 50};
    eepromManager.saveData(&data);
    //eepromManager.saveData(&data2);

    StoredData dataLoaded[50];
    unsigned int n = eepromManager.loadData(dataLoaded);
    for (unsigned int i = 0; i < n; i++){
      Serial.println("Loaded data: ");
      Serial.print(datetime.toStr(dataLoaded[i].timestamp));
      Serial.print(" @ ");
      Serial.print(dataLoaded[i].temperature);
      Serial.print("°C and humidity: ");
      Serial.print(dataLoaded[i].humidity);
      Serial.println("%");
    }

  }
  ESP.deepSleep(5 * 1000000);
  delay(500000000);
}
#include <Arduino.h>
#include <Config.h>
#include <WiFiHandler.h>
#include <Datetime.h>
#include <EEPROMManager.h>
#include <StoredData.h>
#include <DHT11.h>
#include <ServerInterface.h>

WiFiHandler wifi;
Datetime datetime;
EEPROMManager eepromManager;
DHT11 dht11;
ServerInterface server;


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
      ESP.deepSleep(30 * 60 * 1000000);
    }

    Serial.println("DHT11 read:");
    Serial.print(temp);
    Serial.print("°C and ");
    Serial.print(hum);
    Serial.println("% humidity");

    /*StoredData data = {.timestamp = now, .temperature = temp, .humidity = hum};
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
    }*/
    server.sendMeasurement(now, temp, hum);

    // We have wifi! Let's try to send the data we saved to the server
    bool success = true;
    time_t times[50];
    uint16_t temps[50], hums[50];
    bool estStamps[50];
    unsigned int nLoaded = eepromManager.loadData(times, temps, hums, estStamps);
    for (unsigned int i = 0; i < nLoaded; i++){
      if (!server.sendMeasurement(times[i], temps[i], hums[i])){
        // Some data did not make it to the server... We will try again next time
        success = false;
        break;
      }
  }
    if (success){
      // All stored data sent. We can clear our memory
      eepromManager.clearStoredData();
    }
    if (!server.sendMeasurement(now, temp, hum)){
      eepromManager.saveData(now, temp, hum, false);
    }
}
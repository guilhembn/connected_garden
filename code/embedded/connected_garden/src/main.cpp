#include <Arduino.h>
#include <Config.h>
#include <WiFiHandler.h>
#include <Datetime.h>
#include <EEPROMManager.h>
#include <DHT11.h>
#include <ServerInterface.h>
#include <Params.h>

WiFiHandler wifi;
Datetime datetime;
EEPROMManager eepromManager;
DHT11 dht11;
ServerInterface server;

Params defaultParams;


void setup() {
  Serial.begin(115200);
  wifi = WiFiHandler(NETWORK_SSID, NETWORK_PASSWORD);
  dht11.setup(D1);
  defaultParams = {.sleepDuration = 32*60};
}

void loop() {
  time_t now;
  if (wifi.isWiFiNetworkAvailable() && wifi.connect()){
    Serial.println("network available");

    bool isTimeEstimated = false;
    now = datetime.now();
    if (now <= 0.0){
      time_t lastSleepTime;
      unsigned long lastSleepDuration;
      eepromManager.loadLastSleep(&lastSleepTime, &lastSleepDuration);
      now = datetime.estimatedNow(lastSleepTime, lastSleepDuration);
      isTimeEstimated = true;
    }
    Serial.print("Formatted Time: ");
    Serial.println(datetime.toStr(now));

    //eepromManager.clearStoredData();

    uint16_t temp, hum;
    if (!dht11.measure(&hum, &temp)){
      Serial.println("Error while reading DHT11");
      eepromManager.saveLastSleep(now, defaultParams.sleepDuration);
      ESP.deepSleep(defaultParams.sleepDuration * 1000000);
    }

    Serial.println("DHT11 read:");
    Serial.print(temp);
    Serial.print("°C and ");
    Serial.print(hum);
    Serial.println("% humidity");

    // We have wifi! Let's try to send the data we saved to the server
    bool success = true;
    time_t times[50];
    uint16_t temps[50], hums[50];
    bool estStamps[50];
    unsigned int nLoaded = eepromManager.loadData(times, temps, hums, estStamps);
    for (unsigned int i = 0; i < nLoaded; i++){
      if (!server.sendMeasurement(times[i], temps[i], hums[i], estStamps[i])){
        // Some data did not make it to the server... We will try again next time
        success = false;
        break;
      }
    }
    if (success){
      // All stored data sent. We can clear our memory
      eepromManager.clearStoredData();
    }
    if (!server.sendMeasurement(now, temp, hum, isTimeEstimated)){
      eepromManager.saveData(now, temp, hum, isTimeEstimated);
    }
  }else{
    time_t lastSleepTime;
    unsigned long lastSleepDuration;
    eepromManager.loadLastSleep(&lastSleepTime, &lastSleepDuration);
    now = datetime.estimatedNow(lastSleepTime, lastSleepDuration);
    uint16_t temp, hum;
    if (!dht11.measure(&hum, &temp)){
      Serial.println("Error while reading DHT11");
      eepromManager.saveLastSleep(now, defaultParams.sleepDuration);
      ESP.deepSleep(defaultParams.sleepDuration * 1000000);
    }
    eepromManager.saveData(now, temp, hum, true);
  }
  eepromManager.saveLastSleep(now, defaultParams.sleepDuration);
  ESP.deepSleep(defaultParams.sleepDuration * 1000000);
}
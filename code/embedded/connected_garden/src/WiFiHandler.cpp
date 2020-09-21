#include <WiFiHandler.h>
#include <ESP8266WiFi.h>


WiFiHandler::WiFiHandler(String networkName, String networkPwd): _networkName(networkName), _networkPwd(networkPwd){

}

bool WiFiHandler::isWiFiNetworkAvailable(const uint8_t maxRetries){
    for (unsigned int retries = 0; retries < maxRetries; retries++){
        int n = WiFi.scanNetworks();
        for (int i = 0; i < n; i++){
            if (WiFi.SSID(i) == _networkName){
                return true;
            }
        }
        delay(WIFI_SCAN_DELAY);
    }
    return false;
}

bool WiFiHandler::connect(const uint8_t maxRetries){
    uint8_t retries = 0;
    WiFi.mode(WIFI_STA); 
    WiFi.begin(_networkName, _networkPwd);
    while (WiFi.status() != WL_CONNECTED) {
        if (retries > maxRetries){
            return false;
        }
        delay(WIFI_CONNECT_DELAY);
        Serial.print(".");
        retries++;
    }
    Serial.println("\nConnected.");
    return true;
}
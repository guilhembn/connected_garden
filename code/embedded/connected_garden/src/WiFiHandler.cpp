#include <WiFiHandler.h>
#include <ESP8266WiFi.h>


WiFiHandler::WiFiHandler(String networkName, String networkPwd): _networkName(networkName), _networkPwd(networkPwd){

}

bool WiFiHandler::isWiFiNetworkAvailable(){
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; i++){
        if (WiFi.SSID(i) == _networkName){
            return true;
        }
    }
    return false;
}

bool WiFiHandler::connect(){
    WiFi.mode(WIFI_STA); 
    WiFi.begin(_networkName, _networkPwd);   //your password
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected.");
    return true;
}
#ifndef WIFI_H
#define WIFI_H

#include <WString.h>

class WiFiHandler{
    protected:
    static const uint8_t WIFI_CONNECT_MAX_RETRIES = 15;
    static const unsigned int WIFI_CONNECT_DELAY = 500;  // Time between retries, ms
    static const uint8_t WIFI_SCAN_MAX_RETRIES = 5;
    static const unsigned int WIFI_SCAN_DELAY = 100;  // ms
    String _networkName;
    String _networkPwd;

    public:
    WiFiHandler(){};
    WiFiHandler(String networkName, String networkPwd);

    bool isWiFiNetworkAvailable(const uint8_t maxRetries = WIFI_SCAN_MAX_RETRIES);
    bool connect(const uint8_t maxRetries = WIFI_CONNECT_MAX_RETRIES);
};

#endif /* WIFI_H */

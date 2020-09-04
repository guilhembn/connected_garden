#ifndef WIFI_H
#define WIFI_H

#include <WString.h>

class WiFiHandler{
    protected:
    String _networkName;
    String _networkPwd;

    public:
    WiFiHandler(){};
    WiFiHandler(String networkName, String networkPwd);

    bool isWiFiNetworkAvailable();
    bool connect();
};

#endif /* WIFI_H */

#ifndef DATETIME_H
#define DATETIME_H

#include <TimeLib.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
class Datetime{
    private:
    WiFiUDP _ntpUDP;
    NTPClient _timeClient;

    public:
    Datetime(): _ntpUDP(), _timeClient(_ntpUDP, "pool.ntp.org"){   
        _timeClient.begin();
        _timeClient.setTimeOffset(0);
    };
    time_t now();

    String toStr(time_t time);


};
#endif /* DATETIME_H */

#ifndef DATETIME_H
#define DATETIME_H

#include <TimeLib.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
class Datetime{
    private:
    static const unsigned short NTP_MAX_RETRIES = 5;

    WiFiUDP _ntpUDP;
    NTPClient _timeClient;

    public:
    Datetime(): _ntpUDP(), _timeClient(_ntpUDP, "pool.ntp.org"){   
        _timeClient.begin();
        _timeClient.setTimeOffset(0);
    };
    time_t now();
    time_t estimatedNow(const time_t sleepTime, const unsigned long sleepDuration);

    String toStr(time_t time);


};
#endif /* DATETIME_H */

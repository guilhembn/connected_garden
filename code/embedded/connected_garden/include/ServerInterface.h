#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include <TimeLib.h>

class ServerInterface{
    public:
    ServerInterface();
    bool sendMeasurement(const time_t timestamp, const uint16_t temperature, const uint16_t humidity, const bool isTimestampEstimated);
};

#endif /* SERVERINTERFACE_H */

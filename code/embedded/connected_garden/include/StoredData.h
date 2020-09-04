#ifndef STOREDDATA_H
#define STOREDDATA_H

#include <TimeLib.h>

struct StoredData{
    time_t timestamp;
    float temperature;
}  __attribute__((packed));

union uStoredData
{
    StoredData data;
    uint8_t bytes[];
} __attribute__((packed));


#endif /* STOREDDATA_H */

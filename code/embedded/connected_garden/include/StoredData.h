#ifndef STOREDDATA_H
#define STOREDDATA_H

#include <TimeLib.h>

struct StoredData{
    time_t timestamp;
    uint16_t temperature;
    uint16_t humidity;
    uint8_t attributes;   // | 1 << 7 -> is timestamp estimated? 
}  __attribute__((packed));

union uStoredData
{
    StoredData data;
    uint8_t bytes[sizeof(StoredData)];
} __attribute__((packed));

#endif /* STOREDDATA_H */

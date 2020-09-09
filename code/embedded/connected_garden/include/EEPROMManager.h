#ifndef EEPROMMANAGER_H
#define EEPROMMANAGER_H

#include <StoredData.h>

class EEPROMManager{
    private:
    const static unsigned int EEPROM_SIZE = 512;
    const static unsigned int STORED_DATA_LAST_SLEEP_ADDRESS = 0;
    const static unsigned int STORED_DATA_SIZE_ADDRESS = STORED_DATA_LAST_SLEEP_ADDRESS + sizeof(LastSleep);
    const static unsigned int STORED_DATA_ADDRESS = STORED_DATA_SIZE_ADDRESS + sizeof(unsigned int);
    const static unsigned int MAX_DATA = (EEPROM_SIZE - STORED_DATA_ADDRESS) / sizeof(StoredData);

    const static uint8_t TIMESTAMP_ESTIMATED_BIT = 0b10000000;
    unsigned int _storedDataSize;

    public:
    EEPROMManager();
    bool clearStoredData();
    bool saveData(const time_t timestamp, const uint16_t temperature, const uint16_t humidity, const bool timestampEstimated);
    unsigned int loadData(time_t* timestamps, uint16_t* temperatures, uint16_t* humidities, bool* timestampEstimated);
    bool saveLastSleep(const time_t lastSleepTime, const unsigned long lastSleepDuration);
    bool loadLastSleep(time_t* lastSleepTime, unsigned long* lastSleepDuration);
};

#endif /* EEPROMMANAGER_H */

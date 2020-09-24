#include <EEPROMManager.h>

#include <EEPROM.h>

EEPROMManager::EEPROMManager(){
    EEPROM.begin(EEPROM_SIZE);

    uint8_t dataSize = EEPROM.read(STORED_DATA_SIZE_ADDRESS);

    _storedDataSize = dataSize > MAX_DATA ? 0 : dataSize;
}

bool EEPROMManager::clearStoredData(){
    for (unsigned int i=STORED_DATA_ADDRESS; i < EEPROM_SIZE; i++){
        EEPROM.write(i, 0);
    }
    EEPROM.write(STORED_DATA_SIZE_ADDRESS, 0);
    if (EEPROM.commit()){
        _storedDataSize = 0;
        return true;
    }
    return false;
}

bool EEPROMManager::saveData(const time_t timestamp, const uint16_t temperature, const uint16_t humidity, const bool timestampEstimated){
    uStoredData uData;
    if (_storedDataSize >= MAX_DATA){
        return false;
    }
    uData.data.timestamp = timestamp;
    uData.data.temperature = temperature;
    uData.data.humidity = humidity;
    uData.data.attributes = 0;
    if (timestampEstimated){
        uData.data.attributes |= TIMESTAMP_ESTIMATED_BIT;
    }
    int start_address = STORED_DATA_ADDRESS + _storedDataSize * sizeof(StoredData);
    for (unsigned int i = 0; i < sizeof(StoredData); i++){
        EEPROM.write(start_address + i, uData.bytes[i]);
    }
    if (!EEPROM.commit()){
        return false;
    }
    _storedDataSize++;
    EEPROM.write(STORED_DATA_SIZE_ADDRESS, _storedDataSize);
    if (!EEPROM.commit()){
        return false;
    }
    return true;
}

unsigned int EEPROMManager::loadData(time_t* timestamps, uint16_t* temperatures, uint16_t* humidities, bool* timestampEstimated){
    uStoredData uData;
    unsigned int beginningAddress;
    if (_storedDataSize > MAX_DATA){
        // Data is corrupted
        clearStoredData();
        return 0;
    }
    for (unsigned int i = 0; i < _storedDataSize; i++){
        beginningAddress = STORED_DATA_ADDRESS + i * sizeof(StoredData);
        for (unsigned int j = 0; j < sizeof(StoredData); j++){
            uData.bytes[j] = EEPROM.read(beginningAddress + j);
        }
        timestamps[i] = uData.data.timestamp;
        temperatures[i] = uData.data.temperature;
        humidities[i] = uData.data.humidity;
        timestampEstimated[i] = uData.data.attributes & TIMESTAMP_ESTIMATED_BIT;
    }
    return _storedDataSize;
}

bool EEPROMManager::saveLastSleep(const time_t lastSleepTime, const unsigned long lastSleepDuration){
    uLastSleep uSleep;
    uSleep.data = {.lastSleepTime = lastSleepTime, .lastSleepDuration = lastSleepDuration};
    for (unsigned int i = 0; i < sizeof(LastSleep); i++){
        EEPROM.write(STORED_DATA_LAST_SLEEP_ADDRESS + i, uSleep.bytes[i]);
    }
    if (!EEPROM.commit()){
        return false;
    }
    return true;
}

bool EEPROMManager::loadLastSleep(time_t* lastSleepTime, unsigned long* lastSleepDuration){
    uLastSleep uSleep;
    for (unsigned int i = 0; i < sizeof(LastSleep); i++){
        uSleep.bytes[i] = EEPROM.read(STORED_DATA_LAST_SLEEP_ADDRESS + i);
    }
    *lastSleepTime = uSleep.data.lastSleepTime;
    *lastSleepDuration = uSleep.data.lastSleepDuration;
    return true;
}
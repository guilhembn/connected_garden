#include <EEPROMManager.h>

#include <EEPROM.h>

EEPROMManager::EEPROMManager(){
    EEPROM.begin(EEPROM_SIZE);

    uint8_t dataSize = EEPROM.read(STORED_DATA_SIZE_ADDRESS);

    _storedDataSize = dataSize > MAX_DATA ? 0 : dataSize;
}

bool EEPROMManager::clearStoredData(){
    for (int i=STORED_DATA_ADDRESS; i < EEPROM_SIZE; i++){
        EEPROM.write(i, 0);
    }
    EEPROM.write(STORED_DATA_SIZE_ADDRESS, 0);
    if (EEPROM.commit()){
        _storedDataSize = 0;
        return true;
    }
    return false;
}

bool EEPROMManager::saveData(const StoredData* data){
    uStoredData uData;
    if (_storedDataSize >= MAX_DATA){
        return false;
    }
    uData.data = *data;
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

unsigned int EEPROMManager::loadData(StoredData* data){
    uStoredData uData;
    unsigned int beginningAddress;
    for (unsigned int i = 0; i < _storedDataSize; i++){
        beginningAddress = STORED_DATA_ADDRESS + i * sizeof(StoredData);
        for (unsigned int j = 0; j < sizeof(StoredData); j++){
            uData.bytes[j] = EEPROM.read(beginningAddress + j);
        }
        data[i] = uData.data;
    }
    return _storedDataSize;
}
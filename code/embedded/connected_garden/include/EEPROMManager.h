#ifndef EEPROMMANAGER_H
#define EEPROMMANAGER_H

#include <StoredData.h>

class EEPROMManager{
    private:
    const static unsigned int EEPROM_SIZE = 512;
    const static unsigned int STORED_DATA_SIZE_ADDRESS = 0;
    const static unsigned int STORED_DATA_ADDRESS = STORED_DATA_SIZE_ADDRESS + sizeof(unsigned int);
    const static unsigned int MAX_DATA = (EEPROM_SIZE - STORED_DATA_ADDRESS) / sizeof(StoredData);
    unsigned int _storedDataSize;

    public:
    EEPROMManager();
    bool clearStoredData();
    bool saveData(const StoredData* data);
    unsigned int loadData(StoredData* data);


};

#endif /* EEPROMMANAGER_H */

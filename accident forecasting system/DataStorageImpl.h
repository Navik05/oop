#pragma once  
#include "DataStorage.h"  

class DataStorageImpl : public DataStorage {
public:
    bool saveData(SensorData data) override;
    string retrieveData(const string& query) override;
};
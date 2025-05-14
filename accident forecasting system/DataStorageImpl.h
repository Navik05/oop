#pragma once  
#include "DataStorage.h"  

class DataStorageImpl : public DataStorage {
public:
    bool saveData(const string& data) override;
    string retrieveData(const string& query) override;
};
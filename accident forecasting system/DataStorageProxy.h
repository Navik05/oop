#pragma once  
#include "DataStorage.h"  
#include <map>
#include <memory> 

class DataStorageProxy : public DataStorage {
private:
    shared_ptr<DataStorage> realStorage;
    map<string, string> cache;

public:
    explicit DataStorageProxy(shared_ptr<DataStorage> storage);
    bool saveData(const string& data) override;
    string retrieveData(const string& query) override;
};
#pragma once  
#include <string>
#include <iostream>  

using namespace std;

class DataStorage {
public:
    virtual ~DataStorage() = default;
    virtual bool saveData(const string& data) = 0;
    virtual string retrieveData(const string& query) = 0;
};
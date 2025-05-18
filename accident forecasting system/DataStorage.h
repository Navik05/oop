#pragma once  
#include <string>
#include "Sensor.h"

using namespace std;

class DataStorage {
public:
    virtual ~DataStorage() = default;
    virtual bool saveData(SensorData data) = 0;
    virtual string retrieveData(const string& query) = 0;
};
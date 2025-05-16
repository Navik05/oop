#pragma once  
#include <string>
#include "Sensor.h"
#include "IDataAdapter.h"

class DataReceiver {
public:
    bool receiveData(IDataAdapter& adapter);
    bool validateData(SensorData data);
    SensorData formatData(SensorData data);
};
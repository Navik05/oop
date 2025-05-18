#pragma once  
#include <string>
#include "Sensor.h"

class DataReceiver {
public:
    bool receiveData(SensorData data);
    bool validateData(SensorData data);
    SensorData formatData(SensorData data);
};
#pragma once
#include <string>
#include "Sensor.h"

using namespace std;

class IDataAdapter{
public:
    virtual ~IDataAdapter() = default;
    virtual SensorData convertToSensorData() = 0;
};
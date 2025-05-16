#pragma once  
#include "Sensor.h"  

class TemperatureSensor : public Sensor {
public:
    void collData() override;
    vector<SensorData> sendData() override;
};
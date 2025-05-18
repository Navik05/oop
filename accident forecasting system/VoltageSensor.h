#pragma once  
#include "Sensor.h"  

class VoltageSensor : public Sensor {
public:
    void collData() override;
    vector<SensorData> sendData() override;
};
#pragma once  
#include "Sensor.h"  

class TemperatureSensor : public Sensor {
public:
    string collData() override;
    void sendData(const string& data) override;
};
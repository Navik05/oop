#pragma once  
#include "Sensor.h"  

class PressureSensor : public Sensor {
public:
    string collData() override;
    void sendData(const string& data) override;
};
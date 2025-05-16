#pragma once  
#include "Sensor.h"  

class PressureSensor : public Sensor {
public:
    void collData() override;
    SensorData sendData() override;
};
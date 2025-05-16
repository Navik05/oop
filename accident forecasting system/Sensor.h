#pragma once  
#include <iostream>

using namespace std;

struct SensorData {
    string type;
    int sensor_id;
    double value;
    string unit;
};

class Sensor {
public:
    SensorData data;
    virtual void collData() = 0;
    virtual SensorData sendData() = 0;
    virtual ~Sensor() = default;
};
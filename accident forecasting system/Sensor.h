#pragma once  
#include <vector>
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
    virtual vector<SensorData> sendData() = 0;
    virtual void add(shared_ptr<Sensor> sensor) {}
    virtual ~Sensor() = default;
};
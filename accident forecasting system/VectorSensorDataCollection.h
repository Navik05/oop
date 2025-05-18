#pragma once
#include "SensorDataCollection.h"
#include <vector>

class VectorSensorDataCollection : public SensorDataCollection {
private:
    vector<SensorData> data;
public:
    VectorSensorDataCollection(const vector<SensorData>& data);
    shared_ptr<SensorDataIterator> createIterator() const override;
};
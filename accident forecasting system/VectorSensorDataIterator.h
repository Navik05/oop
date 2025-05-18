#pragma once
#include "SensorDataIterator.h"

class VectorSensorDataIterator : public SensorDataIterator {
private:
    vector<SensorData> data;
    size_t current = 0;
public:
    VectorSensorDataIterator(const vector<SensorData>& data);
    bool hasNext() const override;
    SensorData next() override;
};

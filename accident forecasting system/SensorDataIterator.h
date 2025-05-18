#pragma once
#include "Sensor.h"
#include <memory>

class SensorDataIterator {
public:
    virtual ~SensorDataIterator() = default;
    virtual bool hasNext() const = 0;
    virtual SensorData next() = 0;
};
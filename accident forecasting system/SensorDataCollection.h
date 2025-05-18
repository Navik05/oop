#pragma once
#include "SensorDataIterator.h"

class SensorDataCollection {
public:
    virtual ~SensorDataCollection() = default;
    virtual shared_ptr<SensorDataIterator> createIterator() const = 0;
};
#include "VectorSensorDataIterator.h"

VectorSensorDataIterator::VectorSensorDataIterator(const vector<SensorData>& data)
    : data(data) {
}

bool VectorSensorDataIterator::hasNext() const {
    return current < data.size();
}

SensorData VectorSensorDataIterator::next() {
    return data[current++];
}
#include "VectorSensorDataCollection.h"
#include "VectorSensorDataIterator.h"

VectorSensorDataCollection::VectorSensorDataCollection(const vector<SensorData>& data)
    : data(data) {
}

shared_ptr<SensorDataIterator> VectorSensorDataCollection::createIterator() const {
    return make_shared<VectorSensorDataIterator>(data);
}
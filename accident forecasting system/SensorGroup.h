#pragma once
#include "Sensor.h"

class SensorGroup : public Sensor {
private:
    vector<shared_ptr<Sensor>> sensors;
    string groupName;

public:
    explicit SensorGroup(const std::string& name);
    void add(std::shared_ptr<Sensor> sensor) override;
    void collData() override;
    vector<SensorData> sendData() override;
};
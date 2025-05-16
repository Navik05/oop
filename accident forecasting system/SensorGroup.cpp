#include "SensorGroup.h"

SensorGroup::SensorGroup(const string& name) : groupName(name) {}

void SensorGroup::add(shared_ptr<Sensor> sensor) {
    sensors.push_back(sensor);
}

void SensorGroup::collData() {
    cout << "\nСбор данных для группы " << groupName << endl;
    for (auto& sensor : sensors) {
        sensor->collData();
    }
}

vector<SensorData> SensorGroup::sendData() {
    cout << "\nПередача данных группы " << groupName << " серверу" << endl;
    vector<SensorData> allData;

    for (auto& sensor : sensors) {
        vector<SensorData> sensorData = sensor->sendData();
        allData.insert(allData.end(), sensorData.begin(), sensorData.end());
    }

    return allData;
}
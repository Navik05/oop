#include "SensorGroup.h"

SensorGroup::SensorGroup(const string& name) : groupName(name) {}

void SensorGroup::add(shared_ptr<Sensor> sensor) {
    sensors.push_back(sensor);
}

void SensorGroup::collData() {
    cout << "\n���� ������ ��� ������ " << groupName << endl;
    for (auto& sensor : sensors) {
        sensor->collData();
    }
}

vector<SensorData> SensorGroup::sendData() {
    cout << "\n�������� ������ ������ " << groupName << " �������" << endl;
    vector<SensorData> allData;

    for (auto& sensor : sensors) {
        vector<SensorData> sensorData = sensor->sendData();
        allData.insert(allData.end(), sensorData.begin(), sensorData.end());
    }

    return allData;
}
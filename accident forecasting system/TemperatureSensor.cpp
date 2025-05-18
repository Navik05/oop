#include "TemperatureSensor.h"

void TemperatureSensor::collData() {
    // ��������� ������ �����������
    data.type = "temperature";
    data.sensor_id = 1;
    data.value = 20.0 + (rand() % 200) / 10.0;    //20.0-39.9
    data.unit = "C";
    cout << "��������� ������� " + data.type << data.sensor_id << ": " << data.value << " " << data.unit << endl;
}

vector<SensorData> TemperatureSensor::sendData() {
    cout << "�������� ������ � ����������� �������" << endl;
    return { data };
}
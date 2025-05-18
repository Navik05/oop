#include "VoltageSensor.h"

void VoltageSensor::collData() {
    // ��������� ������ ����������
    data.type = "voltage";
    data.sensor_id = 1;
    data.value = 1.0 + (rand() % 100) / 10.0;     // 1.0-10.9
    data.unit = "V";
    cout << "��������� ������� " + data.type << data.sensor_id << ": " << data.value << " " << data.unit << endl;
}

vector<SensorData> VoltageSensor::sendData() {
    cout << "�������� ������� ������ � ����������"  << endl;
    return { data };
}
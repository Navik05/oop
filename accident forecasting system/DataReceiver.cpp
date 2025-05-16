#include "DataReceiver.h"

bool DataReceiver::receiveData(IDataAdapter& adapter) {
    SensorData data = adapter.convertToSensorData();
    if (!validateData(data)) {
        cerr << "�������� �������� ������" << endl;
        return false;
    }
    SensorData formatted = formatData(data);
    return true;
}

bool DataReceiver::validateData(SensorData data) {
    // �������� ������
    if (data.value < 0 || data.sensor_id < 1 || empty(data.unit))
        return false;
    else   
        return true;
}

SensorData DataReceiver::formatData(SensorData data) {
    cout << "������ �������� � ���������������" << endl;
    return data;
}
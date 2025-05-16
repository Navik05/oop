#include "DataReceiver.h"

bool DataReceiver::receiveData(IDataAdapter& adapter) {
    SensorData data = adapter.convertToSensorData();
    if (!validateData(data)) {
        cerr << "Получены неверные данные" << endl;
        return false;
    }
    SensorData formatted = formatData(data);
    return true;
}

bool DataReceiver::validateData(SensorData data) {
    // Проверка данных
    if (data.value < 0 || data.sensor_id < 1 || empty(data.unit))
        return false;
    else   
        return true;
}

SensorData DataReceiver::formatData(SensorData data) {
    cout << "Данные получены и отформатированы" << endl;
    return data;
}
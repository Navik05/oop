#include "TemperatureSensor.h"

void TemperatureSensor::collData() {
    // Генерация данных температуры
    data.type = "temperature";
    data.sensor_id = 1;
    data.value = 20.0 + (rand() % 200) / 10.0;    //20.0-39.9
    data.unit = "C";
    cout << "\nПоказания датчика " + data.type << data.sensor_id << ": " << data.value << " " << data.unit << endl;
}

SensorData TemperatureSensor::sendData() {
    cout << "Передача данных о температуре серверу" << endl;
    return data;
}
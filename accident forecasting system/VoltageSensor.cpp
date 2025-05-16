#include "VoltageSensor.h"

void PressureSensor::collData() {
    // Генерация данных напряжения
    data.type = "voltage";
    data.sensor_id = 1;
    data.value = 1.0 + (rand() % 100) / 10.0;     // 1.0-10.9
    data.unit = "V";
    cout << "\nПоказания датчика " + data.type << data.sensor_id << ": " << data.value << " " << data.unit << endl;
}

SensorData PressureSensor::sendData() {
    cout << "Передача серверу данных о напряжении"  << endl;
    return data;
}
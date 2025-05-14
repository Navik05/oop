#define _CRT_SECURE_NO_WARNINGS
#include "TemperatureSensor.h"
#include <ctime>
#include <iomanip>
#include <sstream>

string TemperatureSensor::collData() {
    // Генерация тестовых данных температуры
    double temperature = 20.0 + (rand() % 200) / 10.0;

    time_t now = time(nullptr);
    tm tm = *gmtime(&now);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");

    ostringstream data;
    data << R"({"sensor_id":"temp_1","type":"temperature","value":)"
        << temperature << R"(,"unit":"C","timestamp":")"
        << oss.str() << "\"}";

    return data.str();
}

void TemperatureSensor::sendData(const string& data) {
    cout << "Данные о температуре: " << data << endl;
}
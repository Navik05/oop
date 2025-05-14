#define _CRT_SECURE_NO_WARNINGS
#include "PressureSensor.h"
#include <ctime>
#include <sstream>
#include <iomanip>

string PressureSensor::collData() {
    // Генерация тестовых данных давления
    double pressure = 1.0 + (rand() % 100) / 10.0;

    time_t now = time(nullptr);
    tm tm = *gmtime(&now);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");

    ostringstream data;
    data << R"({"sensor_id":"press_1","type":"pressure","value":)"
        << pressure << R"(,"unit":"V","timestamp":")"
        << oss.str() << "\"}";

    return data.str();
}

void PressureSensor::sendData(const string& data) {
    cout << "Данные о напряжении: " << data << endl;
}
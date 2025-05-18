#include "SensorAdapter.h"

SensorAdapter::SensorAdapter(unique_ptr<HumiditySensor> sensor): adaptee(move(sensor)) {}

void SensorAdapter::collData()
{
    data.type = "humidity";
    data.sensor_id = 1;
    data.value = adaptee->getDate();
    data.unit = "P";
    cout << "Показания датчика " + data.type << data.sensor_id << ": " << data.value << " " << data.unit << endl;
}

vector<SensorData> SensorAdapter::sendData()
{
    adaptee->send();
    return { data };
}
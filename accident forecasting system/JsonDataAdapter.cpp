#include "JsonDataAdapter.h"

JsonDataAdapter::JsonDataAdapter(SensorData json)
{
	jsonData = json;
}

SensorData JsonDataAdapter::convertToSensorData()
{
	cout << "�������������� ������ JSON" << endl;
	SensorData data = jsonData;
	return data;
}

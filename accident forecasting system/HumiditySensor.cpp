#include "HumiditySensor.h"

double HumiditySensor::getDate() const
{
	return 13.0;
}

void HumiditySensor::send() const
{
	cout << "Передача данных о влажности серверу" << endl;
}
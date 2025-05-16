#pragma once
#include <vector>
#include "IDataAdapter.h"

// ���������� ������� ��� JSON ������
class JsonDataAdapter : public IDataAdapter {
    SensorData jsonData;
public:
    JsonDataAdapter(SensorData json);
    SensorData convertToSensorData() override;
};
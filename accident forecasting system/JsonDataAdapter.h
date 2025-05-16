#pragma once
#include <vector>
#include "IDataAdapter.h"

// Конкретный адаптер для JSON данных
class JsonDataAdapter : public IDataAdapter {
    SensorData jsonData;
public:
    JsonDataAdapter(SensorData json);
    SensorData convertToSensorData() override;
};
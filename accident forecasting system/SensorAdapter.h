#include "sensor.h"
#include "HumiditySensor.h"

class SensorAdapter : public Sensor {
private:
    unique_ptr<HumiditySensor> adaptee;
    SensorData date;
public:
    explicit SensorAdapter(unique_ptr<HumiditySensor> sensor);
    void collData() override;
    vector<SensorData> sendData() override;
};

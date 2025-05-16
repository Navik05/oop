#pragma once  
#include "Sensor.h"
#include <string>

using namespace std;

class AnalyticsModule {
    struct AnalysisResult {
        string message;
        bool isCritical;
    } result;
public:
    AnalysisResult analyzeData(SensorData data);
    AnalysisResult predictFailures(SensorData data);
};
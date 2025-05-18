#pragma once  
#include "SensorDataCollection.h"
#include "Sensor.h"
#include <string>

using namespace std;

class AnalyticsModule {
public:
    struct AnalysisResult {
        string message;
        bool isCritical;
    } result;
    AnalysisResult analyzeData(SensorData data);
    AnalysisResult predictFailures(SensorData data);
    vector<AnalysisResult> analyzeAllData(shared_ptr<SensorDataCollection> collection);
    vector<AnalysisResult> predictAllFailures(shared_ptr<SensorDataCollection> collection);
};
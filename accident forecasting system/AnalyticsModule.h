#pragma once  
#include <string>
#include <iostream>

using namespace std;

struct AnalysisResult {
    string message;
    bool isCritical;
};

class AnalyticsModule {
public:
    AnalysisResult analyzeData(const string& data);
    AnalysisResult predictFailures(const string& data);
};
#pragma once  
#include <string>
#include <iostream>

using namespace std;

class AnalyticsModule {
    struct AnalysisResult {
        string message;
        bool isCritical;
    } result;
public:
    AnalysisResult getResult();
    void analyzeData(const string& data);
    void predictFailures(const string& data);
};
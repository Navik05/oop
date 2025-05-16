#include "AnalyticsModule.h"

AnalyticsModule::AnalysisResult AnalyticsModule::analyzeData(SensorData data) {
    result.message = "�����";
    result.isCritical = false;
    
    cout << "������ ������ � ������� " << data.type << data.sensor_id  << endl;
    if (data.type == "temperature" && data.value > 20.0) { //20.0-39.9
        result.message = "��������������! ���������� ������� ����������� (" + to_string(data.value) + data.unit+")";
    }

    else if (data.type == "voltage" && data.value > 5.0) { // 1.0-10.9
        result.message = "��������������! ���������� ������� ���������� (" + to_string(data.value) + data.unit + ")";
    }
    return result;
}

AnalyticsModule::AnalysisResult AnalyticsModule::predictFailures(SensorData data) {
    result.message = "�����";
    result.isCritical = false;

    cout << "��������������� ������� ������� " << data.type << data.sensor_id << endl;
    if (data.type == "temperature" && data.value > 30.0) {
        result.message = "������! ������� ���� ���������";
    }
    else if (data.type == "voltage" && data.value > 7.5) {
        result.message = "������! ������� ���� ������ ����������";
    }
    return result;
}

vector<AnalyticsModule::AnalysisResult> AnalyticsModule::analyzeAllData(
    shared_ptr<SensorDataCollection> collection
) {
    vector<AnalysisResult> results;
    auto iterator = collection->createIterator();
    while (iterator->hasNext()) {
        results.push_back(analyzeData(iterator->next()));
    }
    return results;
}

vector<AnalyticsModule::AnalysisResult> AnalyticsModule::predictAllFailures(
    shared_ptr<SensorDataCollection> collection
) {
    vector<AnalysisResult> results;
    auto iterator = collection->createIterator();
    while (iterator->hasNext()) {
        results.push_back(predictFailures(iterator->next()));
    }
    return results;
}
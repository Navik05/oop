#include "AnalyticsModule.h"
#include <single_include/nlohmann/json.hpp>

using json = nlohmann::json;

AnalysisResult AnalyticsModule::analyzeData(const string& data) {
    AnalysisResult result;
    result.message = "�����";
    result.isCritical = false;

    try {
        json j = json::parse(data);
        cout << "������ ������ � �������: " << j["sensor_id"] << endl;

        if (j["type"] == "temperature" && j["value"] > 20.0) { //20.0-39.9
            result.message = "��������������! ���������� ������� ����������� (" + to_string(j["value"]) + " C)";
        }

        else if (j["type"] == "pressure" && j["value"] > 5.0) { // 1.0-10.9
            result.message = "��������������! ���������� ������� ���������� (" + to_string(j["value"]) + " V)";
        }
    }
    catch (const json::parse_error& e) {
        result.message = "������ ������� JSON � ������ ���������: " + std::string(e.what());
        result.isCritical = true;
    }

    return result;
}

AnalysisResult AnalyticsModule::predictFailures(const string& data) {
    AnalysisResult result;
    result.message = "�����";
    result.isCritical = false;

    try {
        json j = json::parse(data);
        cout << "��������������� ������� �������: " << j["sensor_id"] << endl;

        if (j["type"] == "temperature" && j["value"] > 30.0) {
            result.message = "������! ������� ���� ���������";
        }
        else if (j["type"] == "pressure" && j["value"] > 7.5) {
            result.message = "������! ������� ���� ������ ����������";
        }
    }
    catch (const json::parse_error& e) {
        result.message = "������ ������� JSON � ������ ���������������: " + std::string(e.what());
        result.isCritical = true;
    }

    return result;
}
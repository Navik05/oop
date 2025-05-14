#include "AnalyticsModule.h"
#include <single_include/nlohmann/json.hpp>

using json = nlohmann::json;

AnalysisResult AnalyticsModule::analyzeData(const string& data) {
    AnalysisResult result;
    result.message = "Норма";
    result.isCritical = false;

    try {
        json j = json::parse(data);
        cout << "Анализ данных с датчика: " << j["sensor_id"] << endl;

        if (j["type"] == "temperature" && j["value"] > 20.0) { //20.0-39.9
            result.message = "ПРЕДУПРЕЖДЕНИЕ! Обнаружена высокая температура (" + to_string(j["value"]) + " C)";
        }

        else if (j["type"] == "pressure" && j["value"] > 5.0) { // 1.0-10.9
            result.message = "ПРЕДУПРЕЖДЕНИЕ! Обнаружено высокое напряжение (" + to_string(j["value"]) + " V)";
        }
    }
    catch (const json::parse_error& e) {
        result.message = "Ошибка анализа JSON в модуле аналитики: " + std::string(e.what());
        result.isCritical = true;
    }

    return result;
}

AnalysisResult AnalyticsModule::predictFailures(const string& data) {
    AnalysisResult result;
    result.message = "Норма";
    result.isCritical = false;

    try {
        json j = json::parse(data);
        cout << "Прогнозирование отказов датчика: " << j["sensor_id"] << endl;

        if (j["type"] == "temperature" && j["value"] > 30.0) {
            result.message = "ОПАСНО! Высокий риск перегрева";
        }
        else if (j["type"] == "pressure" && j["value"] > 7.5) {
            result.message = "ОПАСНО! Высокий риск скачка напряжения";
        }
    }
    catch (const json::parse_error& e) {
        result.message = "Ошибка анализа JSON в модуле прогнозирования: " + std::string(e.what());
        result.isCritical = true;
    }

    return result;
}
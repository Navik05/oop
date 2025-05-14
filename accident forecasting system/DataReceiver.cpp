#include "DataReceiver.h"
#include <regex>
#include <single_include/nlohmann/json.hpp>

using json = nlohmann::json;

bool DataReceiver::receiveData(const string& data) {
    if (!validateData(data)) {
        cerr << "�������� �������� ������" << endl;
        return false;
    }

    string formatted = formatData(data);
    cout << "������ �������� � ���������������: " << formatted << endl;
    return true;
}

bool DataReceiver::validateData(const string& data) {
    try {
        json j = json::parse(data);

        // �������� ������� ���� �����
        if (!j.contains("sensor_id") || !j.contains("type") ||
            !j.contains("value") || !j.contains("unit") || !j.contains("timestamp")) {
            return false;
        }

        // �������� ������� timestamp
        regex time_regex(R"(^\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}Z$)");
        if (!regex_match(j["timestamp"].get<string>(), time_regex)) {
            return false;
        }

        return true;
    }
    catch (const json::parse_error& e) {
        cerr << "������ ����������� JSON: " << e.what() << endl;
        return false;
    }
}

string DataReceiver::formatData(const string& data) {
    return data;
}
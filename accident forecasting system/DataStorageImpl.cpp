#include "DataStorageImpl.h"   

bool DataStorageImpl::saveData(SensorData data) {
    cout << "������ ��������� � ���� ������\n" << endl;
    return true;
}

string DataStorageImpl::retrieveData(const string& query) {
    cout << "���������� ������ �� �������: " << query << endl;
    return "������ �� ���� ������ �� �������: " + query;
}
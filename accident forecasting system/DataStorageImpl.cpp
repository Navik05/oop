#include "DataStorageImpl.h"   

bool DataStorageImpl::saveData(const string& data) {
    cout << "������ ��������� � ���� ������: " << data << endl;
    return true;
}

string DataStorageImpl::retrieveData(const string& query) {
    cout << "���������� ������ �� �������: " << query << endl;
    return "������ �� ���� ������ �� �������: " + query;
}
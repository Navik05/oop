#include "DataStorageProxy.h"  

DataStorageProxy::DataStorageProxy(shared_ptr<DataStorage> storage)
    : realStorage(storage) {
}

// ������� ��� ��� ���������� ����� ������
bool DataStorageProxy::saveData(SensorData data) {
    cache.clear();
    return realStorage->saveData(data);
}

// ��������� ��� ����� ���������� � ��������� ���������
string DataStorageProxy::retrieveData(const string& query) {

    if (cache.find(query) != cache.end()) {
        cout << "������� ������������ ������ ��� �������: " << query << endl;
        return cache[query];
    }

    string data = realStorage->retrieveData(query);
    cache[query] = data;
    return data;
}
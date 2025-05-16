#include "DataStorageImpl.h"   

bool DataStorageImpl::saveData(SensorData data) {
    cout << "Данные сохранены в базе данных\n" << endl;
    return true;
}

string DataStorageImpl::retrieveData(const string& query) {
    cout << "Извлечение данных по запросу: " << query << endl;
    return "Данные из базы данных по запросу: " + query;
}
#include "DataStorageImpl.h"   

bool DataStorageImpl::saveData(const string& data) {
    cout << "Данные сохранены в базе данных: " << data << endl;
    return true;
}

string DataStorageImpl::retrieveData(const string& query) {
    cout << "Извлечение данных по запросу: " << query << endl;
    return "Данные из базы данных по запросу: " + query;
}
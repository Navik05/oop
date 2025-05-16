#include "DataStorageProxy.h"  

DataStorageProxy::DataStorageProxy(shared_ptr<DataStorage> storage)
    : realStorage(storage) {
}

// Очищаем кэш при сохранении новых данных
bool DataStorageProxy::saveData(SensorData data) {
    cache.clear();
    return realStorage->saveData(data);
}

// Проверяем кэш перед обращением к реальному хранилищу
string DataStorageProxy::retrieveData(const string& query) {

    if (cache.find(query) != cache.end()) {
        cout << "Возврат кэшированных данных для запроса: " << query << endl;
        return cache[query];
    }

    string data = realStorage->retrieveData(query);
    cache[query] = data;
    return data;
}
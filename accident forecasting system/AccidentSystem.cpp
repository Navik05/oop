#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include "TemperatureSensor.h"
#include "PressureSensor.h"
#include "DataReceiver.h"
#include "DataStorageImpl.h"
#include "DataStorageProxy.h"
#include "AnalyticsModule.h"
#include "EmailNotifier.h"
#include "SMSNotifier.h"
#include <single_include/nlohmann/json.hpp>

void simulateSystem();
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Создание случайных чисел для генерации тестовых данных
    srand(time(nullptr));

    try {
        simulateSystem();
    }
    catch (const exception& e) {
        cerr << "Ошибка в работе системы: " << e.what() << endl;
        return 1;
    }

    return 0;
}

// Функция для симуляции работы системы в реальном времени
void simulateSystem() {
    cout << "\n=== Инициализация системы мониторинга ===\n" << endl;

    // 1. Инициализация датчиков
    vector<unique_ptr<Sensor>> sensors;
    sensors.push_back(make_unique<TemperatureSensor>());
    sensors.push_back(make_unique<PressureSensor>());
    cout << "Датчики инициализированы: 1 температурный, 1 датчик давления\n" << endl;

    // 2. Инициализация компонентов обработки данных
    DataReceiver receiver;
    auto storageImpl = make_shared<DataStorageImpl>();
    DataStorageProxy storageProxy(storageImpl);
    cout << "Система приема и хранения данных готова к работе\n" << endl;

    // 3. Инициализация аналитического модуля
    AnalyticsModule analytics;
    cout << "Аналитический модуль активирован\n" << endl;

    // 4. Инициализация системы оповещения
    EmailNotifier emailNotifier;
    SMSNotifier smsNotifier;
    cout << "Система оповещения готова (Email и SMS)\n" << endl;

    cout << "=== Запуск цикла мониторинга ===\n" << endl;

    // 5. Основной цикл работы системы
    for (int i = 0; i < 1; ++i) {
        cout << "\nЦикл мониторинга #" << i + 1 << endl;
        cout << "----------------------------" << endl;

        for (auto& sensor : sensors) {
            // 5.1 Сбор данных с датчиков
            string data = sensor->collData();
            cout << "\nДанные с датчика: " << data << endl;

            // 5.2 Отправка данных на сервер
            sensor->sendData(data);

            // 5.3 Прием и проверка данных
            if (receiver.receiveData(data)) {
                cout << "Данные прошли валидацию" << endl;

                // 5.4 Сохранение данных (с кэшированием через прокси)
                if (storageProxy.saveData(data)) {
                    cout << "Данные успешно сохранены в хранилище" << endl;
                }

                // 5.5 Анализ данных и проверка на критические события
                analytics.analyzeData(data);
                auto  analyze = analytics.getResult();

                analytics.predictFailures(data);
                auto predictions = analytics.getResult();

                // 5.6 Отправка уведомлений при необходимости
                if (!analyze.isCritical && analyze.message != "Норма")
                    emailNotifier.sendAlert(analyze.message);
                else if(analyze.message != "Норма")
                    emailNotifier.sendAlert(analyze.message);

                if (!predictions.isCritical && predictions.message != "Норма")
                    smsNotifier.sendAlert(predictions.message);
                else if (predictions.message != "Норма")
                    smsNotifier.sendAlert(predictions.message);
            }
            else {
                cerr << "Ошибка: Данные не прошли валидацию" << endl;
            }
        }
    }

    // 6. Демонстрация работы кэширующего прокси
    cout << "\n=== Тестирование кэширующего прокси ===\n" << endl;

    string query1 = "SELECT * FROM sensor_data WHERE type='temperature'";
    cout << "Первый запрос: " << query1 << endl;
    cout << storageProxy.retrieveData(query1) << "\n" << endl;

    cout << "Второй запрос (должен быть из кэша): " << query1 << endl;
    cout << storageProxy.retrieveData(query1) << "\n" << endl;

    cout << "=== Завершение работы системы ===\n" << endl;
}
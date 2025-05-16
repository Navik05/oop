#include <iostream>
#include <vector>
#include "TemperatureSensor.h"
#include "VoltageSensor.h"
#include "DataReceiver.h"
#include "DataStorageImpl.h"
#include "DataStorageProxy.h"
#include "AnalyticsModule.h"
#include "EmailNotifier.h"
#include "SMSNotifier.h"

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
    cout << "Датчики инициализированы: 1 температурный, 1 датчик давления" << endl;

    // 2. Инициализация компонентов обработки данных
    DataReceiver receiver;
    auto storageImpl = make_shared<DataStorageImpl>();
    DataStorageProxy storageProxy(storageImpl);
    cout << "Система приема и хранения данных готова к работе" << endl;

    // 3. Инициализация аналитического модуля
    AnalyticsModule analytics;
    cout << "Аналитический модуль активирован" << endl;

    // 4. Инициализация системы оповещения
    EmailNotifier emailNotifier;
    SMSNotifier smsNotifier;
    cout << "Система оповещения готова (Email и SMS)\n" << endl;

    cout << "=== Запуск цикла мониторинга ===" << endl;

    // 5. Основной цикл работы системы
    for (int i = 0; i < 1; ++i) {
        cout << "\nЦикл мониторинга #" << i + 1 << endl;
        cout << "----------------------------" << endl;

        for (auto& sensor : sensors) {
            // 5.1 Сбор данных с датчиков
            sensor->collData();

            // 5.2 Отправка данных на сервер
            auto data = sensor->sendData();

            // 5.3 Прием и проверка данных
            if (receiver.receiveData(data)) {

                // 5.4 Сохранение данных (с кэшированием через прокси)
                storageProxy.saveData(data);

                // 5.5 Анализ данных и проверка на критические события
                auto  analyze = analytics.analyzeData(data);
                auto predictions = analytics.predictFailures(data);

                // 5.6 Отправка уведомлений при необходимости
                if (!analyze.isCritical && analyze.message != "Норма")
                    emailNotifier.sendAlert(analyze.message);
                else if (analyze.message != "Норма")
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
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
#include "JsonDataAdapter.h"
#include "LoggingNotifierDecorator.h"
#include "SensorGroup.h"
#include "VectorSensorDataCollection.h"

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

    // Создаем отдельные датчики (5-6)
    auto tempSensor = make_shared<TemperatureSensor>();
    auto voltageSensor = make_shared<VoltageSensor>();

    // Создаем группу датчиков (5-6)
    auto sensorGroup = make_shared<SensorGroup>("*Основные датчики*");
    sensorGroup->add(tempSensor);
    sensorGroup->add(voltageSensor);

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

    // Создание декорированных уведомителей (5-6)
    auto smsNotifier = make_unique<LoggingNotifierDecorator>(
        make_unique<SMSNotifier>()
    );

    cout << "Система оповещения готова (Email и SMS)\n" << endl;

    cout << "=== Запуск цикла мониторинга ===" << endl;

    // Собираем данные со всей группы (5-6)
    sensorGroup->collData();

    // Отправляем данные всей группы на сервер (5-6)
    vector<SensorData> data = sensorGroup->sendData();

    for (int i = 0; i < data.size(); ++i)
    {
        // Преобразование данных из JSON формата в SensorData (5-6)
        JsonDataAdapter jsonAdapter(data[i]);

        // 5.3 Прием и проверка данных
        if (receiver.receiveData(jsonAdapter)) {

            // 5.4 Сохранение данных (с кэшированием через прокси)
            storageProxy.saveData(data[i]);
        }
        else {
            cerr << "Ошибка: Данные не прошли валидацию" << endl;
        }
    }

    // Создаем коллекцию на основе вектора
    auto collection = make_shared<VectorSensorDataCollection>(data);

    // Анализируем все данные и проверка на критические события
    cout << "\n--- Анализ всех данные ---" << endl;
    auto  analyze = analytics.analyzeAllData(collection);
    for (const auto& result : analyze) {
        if (!result.isCritical && result.message != "Норма")
            emailNotifier.sendAlert(result.message);
        else if (result.message != "Норма")
            emailNotifier.sendAlert(result.message);
    }

    cout << "\n--- Прогнозирование всех отказов ---" << endl;
    auto predictions = analytics.predictAllFailures(collection);
    for (const auto& prediction : predictions) {
        if (!prediction.isCritical && prediction.message != "Норма")
            smsNotifier->sendAlert(prediction.message);
        else if (prediction.message != "Норма")
            smsNotifier->sendAlert(prediction.message);
    }
}
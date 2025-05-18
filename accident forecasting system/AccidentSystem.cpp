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
#include "LoggingNotifierDecorator.h"
#include "SensorGroup.h"
#include "VectorSensorDataCollection.h"
#include "HumiditySensor.h"
#include "SensorAdapter.h"

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

    // Создаём датчик влажности
    auto thirdPartySensor = make_unique<HumiditySensor>();
    auto humiditySensor = make_unique<SensorAdapter>(move(thirdPartySensor));

    // Создаем отдельные датчики
    auto tempSensor1 = make_shared<TemperatureSensor>();
    auto tempSensor2 = make_shared<TemperatureSensor>();
    auto voltageSensor1 = make_shared<VoltageSensor>();
    auto voltageSensor2 = make_shared<VoltageSensor>();

    // Создаем группы датчиков
    auto sensorGroup1 = make_shared<SensorGroup>("*2 датчика*");
    sensorGroup1->add(tempSensor1);
    sensorGroup1->add(voltageSensor1);
    sensorGroup1->add(shared_ptr<Sensor>(move(humiditySensor)));

    // Объединяем группы
    auto sensorGroup2 = make_shared<SensorGroup>("*Все датчики*");
    sensorGroup2->add(tempSensor2);
    sensorGroup2->add(voltageSensor2);
    sensorGroup2->add(sensorGroup1);

    cout << "Датчики инициализированы: 2 температурных, 2 давления, 1 влажности" << endl;

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

    // Собираем данные со всей группы
    sensorGroup2->collData();

    // Отправляем данные всей группы на сервер (5-6)
    vector<SensorData> data = sensorGroup2->sendData();

    for (int i = 0; i < data.size(); ++i)
    {
        // 5.3 Прием и проверка данных
        if (receiver.receiveData(data[i])) {

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
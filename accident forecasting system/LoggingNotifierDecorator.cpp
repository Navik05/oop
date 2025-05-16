#include "LoggingNotifierDecorator.h"

LoggingNotifierDecorator::LoggingNotifierDecorator(unique_ptr<NotificationSystem> notifier)
    : notifier(move(notifier)) {
}

void LoggingNotifierDecorator::sendAlert(const string& message) {
    // Логирование перед отправкой
    cout << "[LOG] Начало отправки уведомления" << endl;

    // Делегирование отправки оригинальному объекту
    notifier->sendAlert(message);

    // Логирование после отправки
    cout << "[LOG] Уведомление отправлено" << endl;
}
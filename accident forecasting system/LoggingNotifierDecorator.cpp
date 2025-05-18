#include "LoggingNotifierDecorator.h"

LoggingNotifierDecorator::LoggingNotifierDecorator(unique_ptr<NotificationSystem> notifier)
    : notifier(move(notifier)) {
}

void LoggingNotifierDecorator::sendAlert(const string& message) {
    // ����������� ����� ���������
    cout << "[LOG] ������ �������� �����������" << endl;

    // ������������� �������� ������������� �������
    notifier->sendAlert(message);

    // ����������� ����� ��������
    cout << "[LOG] ����������� ����������" << endl;
}
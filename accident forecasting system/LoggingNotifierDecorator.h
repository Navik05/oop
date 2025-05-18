#pragma once
#include "NotificationSystem.h"
#include <memory>

class LoggingNotifierDecorator : public NotificationSystem {
private:
    unique_ptr<NotificationSystem> notifier;
public:
    LoggingNotifierDecorator(std::unique_ptr<NotificationSystem> notifier);
    void sendAlert(const string& message) override;
};
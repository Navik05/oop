#pragma once  
#include "NotificationSystem.h"  

class SMSNotifier : public NotificationSystem {
public:
    void sendAlert(const string& message) override;
};
#pragma once  
#include "NotificationSystem.h"  

class EmailNotifier : public NotificationSystem {
public:
    void sendAlert(const string& message) override;
};
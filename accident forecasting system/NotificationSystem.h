#pragma once  
#include <string>  
#include <iostream> 

using namespace std;

class NotificationSystem {
public:
    virtual ~NotificationSystem() = default;
    virtual void sendAlert(const string& message) = 0;
};
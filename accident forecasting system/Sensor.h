#pragma once  
#include <iostream>
#include <string>

using namespace std;

class Sensor {
public:
    virtual string collData() = 0;
    virtual void sendData(const string& data) = 0;
    virtual ~Sensor() = default;
};
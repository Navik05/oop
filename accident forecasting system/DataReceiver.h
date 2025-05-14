#pragma once  
#include <iostream>
#include <string>

using namespace std;

class DataReceiver {
public:
    bool receiveData(const string& data);
    bool validateData(const string& data);
    string formatData(const string& data);
};
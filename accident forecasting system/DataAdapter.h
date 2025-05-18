#pragma once  
#include <iostream>
#include <string>

using namespace std;

class DataAdapter
{
public:
    virtual ~DataAdapter() = default;
    virtual void convertToJson() = 0;
};
#pragma once
#include <iostream>
#include <string>

using namespace std;

class HumiditySensor
{
public:
	double getDate() const;
	void send() const;
};
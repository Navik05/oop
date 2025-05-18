#pragma once
#include "DataAdapter.h"

class XmlToJsonAdapter : public DataAdapter {
public:
    void convertToJson() override;
};
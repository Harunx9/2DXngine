#pragma once
#include <Utils/Macros/PropertyMacro.h>

class PropTestClass
{
public:
    PropTestClass() {}
    ~PropTestClass() {}
    PROPERTY(int, number)
    PROPERTY(bool, logical)
    PROPERTY(double, floating)
};


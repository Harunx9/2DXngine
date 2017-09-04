#pragma once
#include <string>
#include "../../../Utils/Macros/PropertyMacro.h"

class Property
{
public:
    Property(std::string name, std::string type,std::string value):
        _name(name), _type(type), _value(value){}
    Property():_name(""), _type(""), _value("") {}
    ~Property() {}

    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(std::string, type)
    READONLY_PROPERTY(std::string, value)
};


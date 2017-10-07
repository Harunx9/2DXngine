#pragma once
#include <string>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "../../../Graphics/Color.h"

enum class PropertyType
{
    STRING,
    INT,
    FLOAT,
    BOOL,
    COLOR,
    FILE
};

class Property
{
public:
    Property(std::string name, std::string type, std::string value) :
        _name(name), _type(type), _value(value) {}
    Property() :_name(""), _type(""), _value("") {}
    ~Property() {}

    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(std::string, type)
    READONLY_PROPERTY(std::string, value)

    bool is_ofType(PropertyType type)
    {
        switch (type)
        {
        case PropertyType::STRING:
            return this->_type.compare("string") == 0;
        case PropertyType::INT:
            return this->_type.compare("int") == 0;
        case PropertyType::FLOAT:
            return this->_type.compare("float") == 0;
        case PropertyType::BOOL:
            return this->_type.compare("bool") == 0;
        case PropertyType::COLOR:
            return this->_type.compare("color") == 0;
        case PropertyType::FILE:
            return this->_type.compare("file") == 0;
        default:
            return false;
        }
    }

    bool empty() noexcept
    {
        return this->_value.empty();
    }

    int as_int() noexcept
    {
        return std::stoi(this->_value);
    }

    std::string as_string() noexcept
    {
        return this->_value;
    }

    float as_float() noexcept
    {
        return std::stof(this->_value);
    }

    bool as_bool() noexcept
    {
        return (bool) std::stoi(this->_value);
    }

    Color as_color() noexcept
    {
        return Color(this->_value);
    }
};


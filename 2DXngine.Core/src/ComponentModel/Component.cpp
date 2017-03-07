#include "Component.h"

Component::Component(const char* name): 
    _name(name),
    _isInitialized(false)
{
}

Component::~Component()
{
}

std::string Component::get_Name() const
{
    return this->_name;
}

bool Component::get_isInitialized() const
{
    return this->_isInitialized;
}

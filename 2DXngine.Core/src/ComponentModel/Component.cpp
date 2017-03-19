#include "Component.h"

Component::Component(const char* name): 
    _name(name),
    _isInitialized(false),
    _isDependenciesResovled(false),
    _owner(nullptr)
{
}

Component::~Component()
{
}

std::string Component::get_name() const
{
    return this->_name;
}

bool Component::get_isInitialized() const
{
    return this->_isInitialized;
}

void Component::add_owner(GameObject * owner)
{
    this->_owner = owner;
}

void Component::remove_owner()
{
    this->_owner = nullptr;
}

GameObject * Component::get_owner() const
{
    return this->_owner;
}

bool Component::has_onwer()
{
    return (this->_owner == nullptr) == false;
}

bool Component::get_isDependenciesResovled() const
{
    return this->_isDependenciesResovled;
}

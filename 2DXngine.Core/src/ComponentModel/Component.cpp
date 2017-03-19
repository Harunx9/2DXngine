#include "Component.h"

Component::Component(const char* name): 
    _name(name),
    _isInitialized(false),
    _isDependenciesResovled(false),
    _isTerminated(false),
    _owner(nullptr)
{
}

Component::~Component()
{
}

void Component::baseInitialize(bool force)
{
    this->initialize();
    this->_isInitialized = true;
}

void Component::baseTerminate()
{
    this->terminate();
    this->_isTerminated = true;
}

void Component::baseResolveDependencies(bool force)
{
    this->resolveDependencies(force);
    this->_isDependenciesResovled = true;
}

std::string Component::get_name() const
{
    return this->_name;
}

bool Component::get_isInitialized() const
{
    return this->_isInitialized;
}

bool Component::get_isTerminated() const
{
    return false;
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

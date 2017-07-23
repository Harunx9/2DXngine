#include "UpdateableComponent.h"



UpdateableComponent::UpdateableComponent(const char* name): 
    Component(name),
    _isActive(false)
{
}

UpdateableComponent::~UpdateableComponent()
{
}

void UpdateableComponent::deactivate()
{
    this->_isActive = false;
}

void UpdateableComponent::activate()
{
    this->_isActive = true;
}

bool UpdateableComponent::get_isActive() const
{
    return this->_isActive;
}

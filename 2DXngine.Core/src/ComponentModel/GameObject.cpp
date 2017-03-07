#include "GameObject.h"



GameObject::GameObject(const char * name, bool isPersistant):
    _name(name),
    _isPersistant(isPersistant),
    _isActive(true),
    _isVisible(true)
{
}


GameObject::~GameObject()
{
}

void GameObject::initialize()
{
}

void GameObject::terminate()
{
}

bool GameObject::get_isActive() const
{
    return this->_isActive;
}

void GameObject::activate()
{
    _isActive = true;
}

void GameObject::deactivate()
{
    _isActive = false;
}

bool GameObject::get_isVisible() const
{
    return this->_isVisible;
}

void GameObject::show()
{
    this->_isVisible = true;
}

void GameObject::hide()
{
    _isVisible = false;
}

bool GameObject::get_isPersistant() const
{
    return this->_isPersistant;
}

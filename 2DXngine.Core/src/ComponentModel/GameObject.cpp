#include "GameObject.h"
#include <algorithm>



GameObject::GameObject(const char * name, bool isPersistant) :
    _name(name),
    _isPersistant(isPersistant),
    _isActive(true),
    _isVisible(true),
    _parent(nullptr)
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

GameObject* GameObject::addComponent(Component * component)
{
    this->_components.push_back(component);
    return this;
}

void GameObject::addChild(GameObject * child)
{
    if (hasChild(child->get_name()) == false)
    {
        this->_childern.push_back(child);
        child->_parent = this;
    }
}

void GameObject::removeChild(const char * name)
{
    if (hasChild(name))
    {
        
        this->_childern.erase(
            std::remove_if(
                this->_childern.begin(),
                this->_childern.end(),
                [name](GameObject* go) { return std::strcmp(go->get_name(), name) == 0; }));
    }
}

GameObject* GameObject::findChild(const char * name)
{
    if (this->_childern.empty() == false)
    {
        for (auto child : this->_childern)
        {
            if (strcmp(name, child->get_name()) == 0)
                return child;
        }
    }
    return nullptr;
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

bool GameObject::get_isEmpty() const
{
    return _components.empty();
}

const char * GameObject::get_name()
{
    return this->_name.c_str();
}

GameObject * GameObject::get_parent()
{
    return this->_parent;
}

bool GameObject::hasChild(const char * name)
{
    if (this->_childern.empty() == false)
    {
        for (auto& child : this->_childern)
        {
            if (strcmp(name, child->get_name()) == 0)
                return true;
        }
    }
    return false;
}

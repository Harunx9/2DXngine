#include "GameObject.h"
#include <algorithm>



GameObject::GameObject(const char * name, bool isPersistant) :
    _name(name),
    _isPersistant(isPersistant),
    _isActive(true),
    _isVisible(true),
    _isInitiaized(false),
    _isTerminated(true),
    _parent(nullptr)
{
 
}

GameObject::~GameObject()
{
    for (auto& component : this->_components)
    {
        if (component->get_isTerminated())
        {
            delete component;
        }
    }

    for (auto& child : this->_childern)
    {
        if (child->get_isTerminated())
        {
            delete child;
        }
    }
}

void GameObject::initialize(bool force)
{
    this->resolveComponentsDependencies(force);
    this->initializeComponents(force);
    this->initializeChildren(force);
    this->_isInitiaized = true;
}

void GameObject::terminate()
{
    this->terminateComponents();
    this->terminateChildren();
    this->_isTerminated = true;
}

GameObject* GameObject::addComponent(Component * component)
{
    this->_components.push_back(component);
    component->add_owner(this);
    return this;
}

GameObject* GameObject::addChild(GameObject * child)
{
    if (hasChild(child->get_name()) == false)
    {
        this->_childern.push_back(child);
        child->_parent = this;
    }

    return this;
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
        for (auto& child : this->_childern)
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

bool GameObject::get_isInitialized() const
{
    return this->_isInitiaized;
}

bool GameObject::get_isTerminated() const
{
    return this->_isTerminated;
}

const char * GameObject::get_name()
{
    return this->_name.c_str();
}

GameObject * GameObject::get_parent()
{
    return this->_parent;
}

void GameObject::set_tag(const char * tag)
{
    this->_tag = tag;
}

const char * GameObject::get_tag() const
{
    return this->_tag.c_str();
}

components_list * GameObject::get_components()
{
    return &this->_components;
}

gameobject_list * GameObject::get_childern()
{
    return &this->_childern;
}

void GameObject::resolveComponentsDependencies(bool force)
{
    for (auto& component : this->_components)
    {
        if (component->get_isDependenciesResovled() == false || force)
            component->baseResolveDependencies(force);
    }
}

void GameObject::initializeComponents(bool force)
{
    for (auto& component : this->_components)
    {
        if (component->get_isInitialized() == false || force)
            component->baseInitialize(force);
    }
}

void GameObject::initializeChildren(bool force)
{
    for (auto& child : this->_childern)
    {
        if (child->get_isInitialized() == false || force)
            child->initialize(force);
    }
}

void GameObject::terminateComponents()
{
    for (auto& component : this->_components)
    {
        component->baseTerminate();
    }
}

void GameObject::terminateChildren()
{
    for (auto& child : this->_childern)
    {
        child->terminate();
    }
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

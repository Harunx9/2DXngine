#include "GameObject.h"
#include <algorithm>



GameObject::GameObject(const char * name, bool isPersistant) :
    _name(name),
    _isPersistant(isPersistant),
    _isActive(true),
    _isVisible(true),
    _isInitialized(false),
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
    this->_isInitialized = true;
}

void GameObject::terminate()
{
    if (this->_isPersistant == false)
    {
        this->terminateComponents();
        this->terminateChildren();
        this->_isTerminated = true;
    }
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
                [name](GameObject* go) { return go->get_name() == name; }));
    }
}

GameObject* GameObject::findChild(const char * name)
{
    if (this->_childern.empty() == false)
    {
        for (auto& child : this->_childern)
        {
            if (name == child->get_name())
                return child;
        }
    }
    return nullptr;
}

void GameObject::activate()
{
    _isActive = true;
}

void GameObject::deactivate()
{
    _isActive = false;
}

void GameObject::show()
{
    this->_isVisible = true;
}

void GameObject::hide()
{
    _isVisible = false;
}

bool GameObject::haveChildern() const
{
    return this->_childern.empty() == false;
}

components_list& GameObject::get_components()
{
    return this->_components;
}

gameobject_list& GameObject::get_childern()
{
    return this->_childern;
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
        if (child->get_isInitialized()== false || force)
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

bool GameObject::hasChild(std::string name)
{
    if (this->_childern.empty() == false)
    {
        for (auto& child : this->_childern)
        {
            if (name == child->get_name())
                return true;
        }
    }
    return false;
}

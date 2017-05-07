#pragma once
#include <string>
#include <vector>
#include "Component.h"
#include "../TypeInformation/TypeInfo.h"
#include "../Utils/Macros/PropertyMacro.h"
class GameObject;

typedef std::vector<Component*> components_list;
typedef std::vector<GameObject*> gameobject_list;

class GameObject
{
public:
    GameObject(const char * name, bool isPersistant = false);
    ~GameObject();

    void initialize(bool force = false);
    void terminate();
    GameObject* addComponent(Component * component);

    template<typename TComponent>
    TComponent* findFirstComponentOfType(bool exactType = true);

    template<typename TComponent>
    std::vector<TComponent*> findAllComponentsOfType(bool exactType = true);

    GameObject* addChild(GameObject* child);
    void removeChild(const char* name);
    GameObject* findChild(const char* name);

    READONLY_PROPERTY(bool, isActive)
    void activate();
    void deactivate();

    READONLY_PROPERTY(bool, isVisible)
    void show();
    void hide();

    inline bool get_isEmpty() const
    {
        return this->_components.empty();
    }

    READONLY_PROPERTY(bool, isPersistant)
    READONLY_PROPERTY(bool, isInitialized)
    READONLY_PROPERTY(bool, isTerminated)

    bool haveChildern() const;

    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(GameObject*, parent)

    PROPERTY(std::string, tag)

    components_list& get_components();
    gameobject_list& get_childern();
private:
    void resolveComponentsDependencies(bool force = false);
    void initializeComponents(bool force = false);
    void initializeChildren(bool force = false);

    void terminateComponents();
    void terminateChildren();

    bool hasChild(std::string name);
    components_list _components;
    gameobject_list _childern;
};

template<typename TComponent>
inline TComponent * GameObject::findFirstComponentOfType(bool exactType)
{
    if (exactType)
    {
        for (auto component : this->_components)
        {
            if (TypeInfo::get<TComponent>() == component->getType())
                return (TComponent *)component;
        }
    }
    else
    {
        for (auto component : this->_components)
        {
            if (component->getType().get_hasBaseTypeOf(TypeInfo::get<TComponent>()))
                return (TComponent *)component;
        }
    }

    return nullptr;
}

template<typename TComponent>
inline std::vector<TComponent*> GameObject::findAllComponentsOfType(bool exactType)
{
    std::vector<TComponent*> matchedComponentList;

    if (exactType)
    {
        for (auto component : this->_components)
        {
            if (TypeInfo::get<TComponent>() == component->getType())
                matchedComponentList.push_back((TComponent *)component);
        }
    }
    else
    {
        for (auto component : this->_components)
        {
            if (component->getType().get_hasBaseTypeOf(TypeInfo::get<TComponent>()))
                matchedComponentList.push_back((TComponent *)component);
        }
    }

    return matchedComponentList;
}

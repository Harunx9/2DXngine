#pragma once
#include <string>
#include <vector>
#include "Component.h"
#include "../TypeInformation/TypeInfo.h"
class GameObject;

typedef std::vector<Component*> components_list;
typedef std::vector<GameObject*> gameobject_list;

class GameObject
{
public:
    GameObject(const char * name, bool isPersistant = false);
    ~GameObject();

    void initialize();
    void terminate();
    GameObject* addComponent(Component * component);

    template<typename TComponent>
    TComponent* findFirstComponentOfType(bool exactType = true);

    template<typename TComponent>
    std::vector<TComponent*> findAllComponentsOfType(bool exactType = true);

    void addChild(GameObject* child);
    void removeChild(const char* name);
    GameObject* findChild(const char* name);

    bool get_isActive() const;
    void activate();
    void deactivate();

    bool get_isVisible() const;
    void show();
    void hide();

    bool get_isPersistant() const;
    bool get_isEmpty() const;

    const char* get_name();

    GameObject* get_parent();

private:
    bool hasChild(const char* name);
    GameObject* _parent;
    std::string _name;
    bool _isActive;
    bool _isVisible;
    bool _isPersistant;
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

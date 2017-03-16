#pragma once
#include <string>
#include <vector>
#include "Component.h"
#include "../TypeInformation/TypeInfo.h"

typedef std::vector<Component*> components_list;

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


    bool get_isActive() const;
    void activate();
    void deactivate();

    bool get_isVisible() const;
    void show();
    void hide();

    bool get_isPersistant() const;
    bool get_isEmpty() const;
private:
    std::string _name;
    bool _isActive;
    bool _isVisible;
    bool _isPersistant;
    components_list _components;
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
            if(component->getType().get_hasBaseTypeOf(TypeInfo::get<TComponent>()))
                return (TComponent *)component;
        }
    }
    return nullptr;
}

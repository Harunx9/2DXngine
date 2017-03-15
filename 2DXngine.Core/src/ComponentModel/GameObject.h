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
    TComponent* findComponentByType();

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
inline TComponent * GameObject::findComponentByType()
{
    for (auto component : this->_components)
    { 
        auto T1 = TypeInfo::get<TComponent>();
        auto T2 = TypeInfo::get((TComponent *)component);

        if (T1 == T2)
            return (TComponent *)component;
    }
    return nullptr;
}

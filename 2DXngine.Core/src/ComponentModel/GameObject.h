#pragma once
#include <string>
#include <vector>
#include "Component.h"

typedef std::vector<Component*> components_list;

class GameObject
{
public:
    GameObject(const char * name, bool isPersistant = false);
    ~GameObject();

    void initialize();
    void terminate();
    void addComponent(Component * component);

    template<typename TComponent>
    TComponent* findComponent();

    bool get_isActive() const;
    void activate();
    void deactivate();

    bool get_isVisible() const;
    void show();
    void hide();

    bool get_isPersistant() const;
private:
    std::string _name;
    bool _isActive;
    bool _isVisible;
    bool _isPersistant;
    components_list _components;
};

template<typename TComponent>
inline TComponent * GameObject::findComponent()
{
    return NULL;
}

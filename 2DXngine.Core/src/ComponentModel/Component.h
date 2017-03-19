#pragma once
#include <string>
#include "../TypeInformation/TypeMetaInfo.h"
class GameObject;

class Component
{
public:
    ADD_TYPE_META_INFO()
    Component(const char* name = "Component");
    virtual ~Component();

    virtual void initialize(bool force = false) = 0;
    virtual void terminate() = 0;
    virtual void resolveDependencies(bool force = false) = 0;

    std::string get_name() const;
    bool get_isInitialized() const;

    void add_owner(GameObject* owner);
    void remove_owner();
    GameObject* get_owner() const;
    bool has_onwer();
    bool get_isDependenciesResovled() const;
protected:
    std::string _name;
    bool _isDependenciesResovled;
    bool _isInitialized;
    GameObject* _owner;
};
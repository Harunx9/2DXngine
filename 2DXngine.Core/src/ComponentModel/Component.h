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

    virtual void initialize() = 0;
    virtual void terminate() = 0;
    virtual void resolveDependencies() = 0;

    std::string get_Name() const;
    bool get_isInitialized() const;

    void add_owner(GameObject* owner);
    void remove_owner();
    GameObject* get_owner();
    bool has_onwer();
protected:
    std::string _name;
    bool _isInitialized;
    GameObject* _owner;
};
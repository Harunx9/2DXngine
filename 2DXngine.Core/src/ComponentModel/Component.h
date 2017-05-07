#pragma once
#include <string>
#include "../TypeInformation/TypeMetaInfo.h"
#include "../Utils/Macros/PropertyMacro.h"
class GameObject;


class Component
{
public:
    ADD_TYPE_META_INFO()
    Component(const char* name = "Component");
    virtual ~Component();

    void baseInitialize(bool force = false);
    void baseTerminate();
    void baseResolveDependencies(bool force = false);

    virtual void initialize(bool force = false) = 0;
    virtual void terminate() = 0;
    virtual void resolveDependencies(bool force = false) {}

    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(bool, isInitialized)
    READONLY_PROPERTY(bool, isTerminated)
    READONLY_PROPERTY(bool, isDependenciesResovled)

    void add_owner(GameObject* owner);
    void remove_owner();
    GameObject* get_owner() const;
    bool has_onwer();
protected:
    GameObject* _owner;
};
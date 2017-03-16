#pragma once
#include <string>
#include "../TypeInformation/TypeMetaInfo.h"

class Component
{
public:
    ADD_TYPE_META_INFO()
    Component(const char* name = "Component");
    virtual ~Component();

    virtual void initialize() = 0;
    virtual void terminate() = 0;

    std::string get_Name() const;
    bool get_isInitialized() const;
protected:
    std::string _name;
    bool _isInitialized;
};
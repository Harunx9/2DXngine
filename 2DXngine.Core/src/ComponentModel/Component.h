#pragma once
#include <string>

class Component
{
public:
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
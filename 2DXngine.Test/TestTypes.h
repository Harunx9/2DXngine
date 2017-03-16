#pragma once
#include <ComponentModel\GameObject.h>
#include <TypeInformation\TypeMetaInfo.h>
class TestComponent : public Component
{
public:
    ADD_TYPE_META_INFO()

    TestComponent(const char* name) : Component(name)
    {

    }

    // Inherited via Component
    virtual void initialize() override
    {
    }
    virtual void terminate() override
    {
    }
};

class TestComponent2 : public Component
{
public:
    ADD_TYPE_META_INFO()

    TestComponent2(const char* name) : Component(name)
    {

    }

    // Inherited via Component
    virtual void initialize() override
    {
    }
    virtual void terminate() override
    {
    }
};

DECLARE_TYPE_INFO_VARIANTS(Component, "")
DECLARE_TYPE_INFO_VARIANTS(TestComponent, Component)
DECLARE_TYPE_INFO_VARIANTS(TestComponent2, Component)
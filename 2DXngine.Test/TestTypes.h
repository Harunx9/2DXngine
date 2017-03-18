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

    virtual void initialize() override{}
    virtual void terminate() override{}
    virtual void resolveDependencies() override {}
};

class TestComponent2 : public Component
{
public:
    ADD_TYPE_META_INFO()

    TestComponent2(const char* name) : Component(name)
    {

    }

    virtual void initialize() override{}
    virtual void terminate() override{}
    virtual void resolveDependencies() override {}
};

DECLARE_TYPE_INFO_VARIANTS(Component, "")
DECLARE_TYPE_INFO_VARIANTS(TestComponent, Component)
DECLARE_TYPE_INFO_VARIANTS(TestComponent2, Component)
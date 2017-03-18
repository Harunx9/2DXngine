#pragma once
#include <ComponentModel\GameObject.h>
#include <ComponentModel\DrawableComponent.h>
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

class TestDrawableComponent1 : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()

    TestDrawableComponent1(const char* name) : DrawableComponent(name)
    {

    }

    virtual void initialize() override {}
    virtual void terminate() override {}
    virtual void draw(Renderer* renderer, float deltaTime) override {}
    virtual void resolveDependencies() override {}
};

class  TestDrawableComponent2 : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()

    TestDrawableComponent2(const char* name) : DrawableComponent(name)
    {

    }

    virtual void initialize() override {}
    virtual void terminate() override {}
    virtual void draw(Renderer* renderer, float deltaTime) override {}
    virtual void resolveDependencies() override {}
};

DECLARE_TYPE_INFO_VARIANTS(Component, "")
DECLARE_TYPE_INFO_VARIANTS(TestComponent, Component)
DECLARE_TYPE_INFO_VARIANTS(TestComponent2, Component)
DECLARE_TYPE_INFO_VARIANTS(DrawableComponent, Component)
DECLARE_TYPE_INFO_VARIANTS(TestDrawableComponent1, DrawableComponent)
DECLARE_TYPE_INFO_VARIANTS(TestDrawableComponent2, DrawableComponent)
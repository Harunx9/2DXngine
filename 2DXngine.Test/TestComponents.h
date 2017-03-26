#pragma once
#include <ComponentModel\UpdateableComponent.h>
#include <ComponentModel\DrawableComponent.h>
#include <TypeInformation\TypeMetaInfo.h>

class PlayerControllerComponentTest : public UpdateableComponent
{
public:
    ADD_TYPE_META_INFO()
    PlayerControllerComponentTest() {}
    ~PlayerControllerComponentTest() {}

    // Inherited via UpdateableComponent
    virtual void initialize(bool force = false) override {}
    virtual void terminate() override {}
    virtual void resolveDependencies(bool force = false) override {}
    virtual void update(float deltaTime) override {}
};

class PlayerDrawableComponentTest : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()
    PlayerDrawableComponentTest() {}
    ~PlayerDrawableComponentTest() {}

    // Inherited via DrawableComponent
    virtual void initialize(bool force = false) override {}
    virtual void terminate() override {}
    virtual void resolveDependencies(bool force = false) override {}
    virtual void draw(Renderer * renderer, float deltaTime) override {}
};

class SwordControllerComponentTest : public UpdateableComponent
{
public:
    ADD_TYPE_META_INFO()
    SwordControllerComponentTest() {}
    ~SwordControllerComponentTest() {}

    // Inherited via UpdateableComponent
    virtual void initialize(bool force = false) override {}
    virtual void terminate() override {}
    virtual void resolveDependencies(bool force = false) override {}
    virtual void update(float deltaTime) override {}
};

class SwordDrawableComponentTest : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()
    SwordDrawableComponentTest() {}
    ~SwordDrawableComponentTest() {}

    // Inherited via DrawableComponent
    virtual void initialize(bool force = false) override {}
    virtual void terminate() override {}
    virtual void resolveDependencies(bool force = false) override {}
    virtual void draw(Renderer * renderer, float deltaTime) override {}
};

DECLARE_TYPE_INFO_VARIANTS(Component, "")
DECLARE_TYPE_INFO_VARIANTS(DrawableComponent, Component)
DECLARE_TYPE_INFO_VARIANTS(UpdateableComponent, Component)
DECLARE_TYPE_INFO_VARIANTS(PlayerControllerComponentTest, UpdateableComponent)
DECLARE_TYPE_INFO_VARIANTS(PlayerDrawableComponentTest, DrawableComponent)
DECLARE_TYPE_INFO_VARIANTS(SwordControllerComponentTest, UpdateableComponent)
DECLARE_TYPE_INFO_VARIANTS(SwordDrawableComponentTest, DrawableComponent)
#pragma once
#include <ComponentModel\UpdateableComponent.h>
#include <ComponentModel\DrawableComponent.h>
#include <TypeInformation\TypeMetaInfo.h>
#include <Scenes\SceneLayer.h>

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
        PlayerDrawableComponentTest() : DrawableComponent(DefaultLayers::GAMEPLAY_LAYER, "drawable_gameplay") {}
    ~PlayerDrawableComponentTest() {}

    // Inherited via DrawableComponent
    virtual void initialize(bool force = false) override {}
    virtual void terminate() override {}
    virtual void resolveDependencies(bool force = false) override {}
    virtual void draw(Renderer * renderer, Camera* camera, float deltaTime) override {}
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
        SwordDrawableComponentTest() : DrawableComponent(DefaultLayers::GAMEPLAY_LAYER, "drawable_gameplay") {}
    ~SwordDrawableComponentTest() {}

    // Inherited via DrawableComponent
    virtual void initialize(bool force = false) override {}
    virtual void terminate() override {}
    virtual void resolveDependencies(bool force = false) override {}
    virtual void draw(Renderer * renderer, Camera* camera, float deltaTime) override {}
};



DECLARE_TYPE_INFO_VARIANTS(PlayerControllerComponentTest, UpdateableComponent)
DECLARE_TYPE_INFO_VARIANTS(PlayerDrawableComponentTest, DrawableComponent)
DECLARE_TYPE_INFO_VARIANTS(SwordControllerComponentTest, UpdateableComponent)
DECLARE_TYPE_INFO_VARIANTS(SwordDrawableComponentTest, DrawableComponent)
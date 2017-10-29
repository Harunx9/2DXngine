#pragma once
#include "../../ComponentModel/DrawableComponent.h"
#include "SpriteComponent.h"
#include "../Behaviors/ParticleSystem/ParticleSystemBehavior.h"

class ParticleSystemDrawableComponent : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()
    ParticleSystemDrawableComponent();
    ParticleSystemDrawableComponent(SceneLayer layer);
    ParticleSystemDrawableComponent(SceneLayer layer, TextureFilter filter, TextureWrap wrap);
    ~ParticleSystemDrawableComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void draw(Renderer * renderer, Camera* camera, float deltaTime) override;
private:
    SpriteComponent * _spriteComponent;
    ParticleSystemBehavior * _behavior;
    TextureFilter _filter;
    TextureWrap _wrap;
};


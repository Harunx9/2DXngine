#pragma once
#include "../../ComponentModel/DrawableComponent.h"
class AnimationComponent;
class Transform;
class SpriteComponent;

class AnimationDrawableComponent : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()
        AnimationDrawableComponent(TextureWrap wrap, TextureFilter filter, SceneLayer layer);
    AnimationDrawableComponent(TextureWrap wrap, TextureFilter filter);
    AnimationDrawableComponent(SceneLayer layer);
    AnimationDrawableComponent();
    ~AnimationDrawableComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void draw(Renderer * renderer, Camera * camera, float deltaTime) override;
    virtual void resolveDependencies(bool force = false) override;

    PROPERTY(FlipEffect, flip)
private:
    AnimationComponent* _animation;
    Transform* _transform;
    SpriteComponent* _sprite;
    TextureWrap _wrap;
    TextureFilter _filter;
};


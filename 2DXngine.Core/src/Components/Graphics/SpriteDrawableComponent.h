#pragma once
#include "../../ComponentModel/DrawableComponent.h"
#include "../../ContentManagement/DefaultAssets/Texture.h"
#include "../../Graphics/SamplerState.h"
class SpriteComponent;
class Transform;

class SpriteDrawableComponent : DrawableComponent
{
public:
    ADD_TYPE_META_INFO()
        SpriteDrawableComponent(TextureWrap wrap, TextureFilter filter, SceneLayer layer);
    SpriteDrawableComponent(SceneLayer layer);
    SpriteDrawableComponent();
    ~SpriteDrawableComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void resolveDependencies(bool force = false) override;
    virtual void draw(Renderer * renderer, Camera* camera, float deltaTime) override;

private:
    SpriteComponent * _sprite;
    Transform * _transform;
    TextureWrap _wrap;
    TextureFilter _filter;
};


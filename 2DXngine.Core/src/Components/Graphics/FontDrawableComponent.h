#pragma once
#include "../../ComponentModel/DrawableComponent.h"

class FontDrawableComponent : public DrawableComponent
{
public:
    ADD_TYPE_META_INFO()
    FontDrawableComponent(SceneLayer layer);
    FontDrawableComponent();
    ~FontDrawableComponent();


    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void draw(Renderer * renderer, Camera * camera, float deltaTime) override;

};


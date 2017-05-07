#pragma once
#include "Component.h"
#include "../TypeInformation/TypeMetaInfo.h"
#include "../Graphics/Renderer.h"
class DrawableComponent :
    public Component
{
public:
    ADD_TYPE_META_INFO()

    DrawableComponent(const char* name = "Drawable");
    virtual ~DrawableComponent();

    virtual void drawDebug(Renderer * renderer, float deltaTime) {}
    virtual void draw(Renderer * renderer, float deltaTime) = 0;

    void hide();
    void show();
    READONLY_PROPERTY(bool, isVisible)
};


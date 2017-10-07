#pragma once
#include "Component.h"
#include "../TypeInformation/TypeMetaInfo.h"
#include "../Graphics/Renderer.h"
#include "../Scenes/SceneLayer.h"
class Camera;

class DrawableComponent :
    public Component
{
public:
    ADD_TYPE_META_INFO()

        DrawableComponent(SceneLayer layer, const char* name = "Drawable");
    virtual ~DrawableComponent();

    virtual void drawDebug(Renderer * renderer, Camera* camera, float deltaTime) {}
    virtual void draw(Renderer * renderer, Camera* camera, float deltaTime) = 0;

    void hide();
    void show();
    READONLY_PROPERTY(bool, isVisible)
    READONLY_PROPERTY(SceneLayer, layer)
};


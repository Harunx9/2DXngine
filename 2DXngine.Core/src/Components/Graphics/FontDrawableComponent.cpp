#include "FontDrawableComponent.h"

FontDrawableComponent::FontDrawableComponent(SceneLayer layer) : DrawableComponent(layer, "FontDrawableComponent")
{
}

FontDrawableComponent::FontDrawableComponent() : DrawableComponent(DefaultLayers::GUI_LAYER, "FontDrawableComponent")
{

}

FontDrawableComponent::~FontDrawableComponent()
{

}

void FontDrawableComponent::initialize(bool force)
{
}

void FontDrawableComponent::terminate()
{
}

void FontDrawableComponent::draw(Renderer * renderer, Camera * camera, float deltaTime)
{
}

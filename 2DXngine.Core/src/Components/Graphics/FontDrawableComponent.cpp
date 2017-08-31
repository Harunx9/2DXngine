#include "FontDrawableComponent.h"
#include "Transform.h"
#include "../Data/FontComponent.h"
#include "../Data/TextComponent.h"
#include "../../ContentManagement/DefaultAssets/TTFont.h"
#include "../../Graphics/Camera.h"

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
    this->_font = nullptr;
    this->_transform = nullptr;
    this->_text = nullptr;
}

void FontDrawableComponent::draw(Renderer * renderer, Camera * camera, float deltaTime)
{
    this->_font->get_font()->draw(
        renderer->get_batch(),
        this->_text->get_text(),
        this->_transform->get_position(),
        this->_font->get_color(),
        camera->get_viewMatrix());
}

void FontDrawableComponent::resolveDependencies(bool force)
{
    this->_transform = this->_owner->findFirstComponentOfType<Transform>();
    this->_font = this->_owner->findFirstComponentOfType<FontComponent>();
    this->_text = this->_owner->findFirstComponentOfType<TextComponent>();
}

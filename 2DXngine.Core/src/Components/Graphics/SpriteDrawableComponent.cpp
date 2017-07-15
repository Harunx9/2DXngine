#include "SpriteDrawableComponent.h"
#include "../../Graphics/Camera.h"
#include "SpriteComponent.h"
#include "../../ComponentModel/GameObject.h"
#include "Transform.h"

SpriteDrawableComponent::SpriteDrawableComponent(
    TextureWrap wrap,
    TextureFilter filter,
    SceneLayer layer) : DrawableComponent(layer, "SpriteDrawableComponent"),
    _wrap(wrap),
    _filter(filter)
{
}

SpriteDrawableComponent::SpriteDrawableComponent(SceneLayer layer) : SpriteDrawableComponent(TextureWrap::CLAMP_TO_EDGE, TextureFilter::LINEAR_FILTER, layer)
{
}

SpriteDrawableComponent::SpriteDrawableComponent(): SpriteDrawableComponent(DefaultLayers::GAMEPLAY_LAYER)
{
}


SpriteDrawableComponent::~SpriteDrawableComponent()
{

}

void SpriteDrawableComponent::initialize(bool force)
{

}

void SpriteDrawableComponent::terminate()
{
    this->_sprite = nullptr;
    this->_transform = nullptr;
}

void SpriteDrawableComponent::resolveDependencies(bool force)
{
    this->_transform = this->get_owner()->findFirstComponentOfType<Transform>();
    this->_sprite = this->get_owner()->findFirstComponentOfType<SpriteComponent>();
}

void SpriteDrawableComponent::draw(Renderer * renderer, Camera* camera, float deltaTime)
{
    renderer->get_batch()->begin(nullptr, this->_wrap, this->_filter, camera->get_viewMatrix());

    renderer->get_batch()->draw(this->_sprite->get_texture(),
        this->_transform->get_position(),
        nullptr,
        Colors::white,
        this->_transform->get_rotation(),
        this->_transform->get_origin(),
        this->_transform->get_scale(),
        FlipEffect::NONE_FLIP,
        this->_transform->get_drawOrder());

    renderer->get_batch()->end();
}

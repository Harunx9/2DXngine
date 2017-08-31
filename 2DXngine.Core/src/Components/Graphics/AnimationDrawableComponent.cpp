#include "AnimationDrawableComponent.h"
#include "../../ComponentModel/GameObject.h"
#include "../../Graphics/Camera.h"
#include "../../Graphics/SpriteBatch.h"
#include "SpriteComponent.h"
#include "AnimationComponent.h"
#include "Transform.h"

AnimationDrawableComponent::AnimationDrawableComponent() : AnimationDrawableComponent(DefaultLayers::GAMEPLAY_LAYER)
{
}

AnimationDrawableComponent::AnimationDrawableComponent(TextureWrap wrap, TextureFilter filter, SceneLayer layer) :
    DrawableComponent(layer, "AnimationDrawableComponent"),
    _wrap(wrap),
    _filter(filter)
{
}

AnimationDrawableComponent::AnimationDrawableComponent(SceneLayer layer) : AnimationDrawableComponent(TextureWrap::CLAMP_TO_EDGE, TextureFilter::LINEAR_FILTER, layer)
{
}

AnimationDrawableComponent::~AnimationDrawableComponent()
{
}

void AnimationDrawableComponent::initialize(bool force)
{
}

void AnimationDrawableComponent::terminate()
{
}

void AnimationDrawableComponent::draw(Renderer * renderer, Camera * camera, float deltaTime)
{
    renderer->get_batch()->begin(nullptr, this->_wrap, this->_filter, camera->get_viewMatrix());
    auto frame = this->_animation->get_currentFrame();
    renderer->get_batch()->draw(this->_sprite->get_texture(),
        this->_transform->get_position(),
        &frame,
        Colors::white,
        this->_transform->get_rotation(),
        this->_transform->get_origin(),
        this->_transform->get_scale(),
        this->get_flip(),
        this->_transform->get_drawOrder());

    renderer->get_batch()->end();
}

void AnimationDrawableComponent::resolveDependencies(bool force)
{
    this->_animation = this->_owner->findFirstComponentOfType<AnimationComponent>();
    this->_transform = this->_owner->findFirstComponentOfType<Transform>();
    this->_sprite = this->_owner->findFirstComponentOfType<SpriteComponent>();
}

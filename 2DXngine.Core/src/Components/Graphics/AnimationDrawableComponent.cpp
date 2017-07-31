#include "AnimationDrawableComponent.h"
#include "../../ComponentModel/GameObject.h"
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

}

void AnimationDrawableComponent::resolveDependencies(bool force)
{
    this->_animation = this->_owner->findFirstComponentOfType<AnimationComponent>();
    this->_transform = this->_owner->findFirstComponentOfType<Transform>();
}

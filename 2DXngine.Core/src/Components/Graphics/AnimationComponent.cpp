#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(animations_dict animations) :
     UpdateableComponent("AnimationComponent"),
    _animations(animations),
    _currentAnimation(nullptr)
{
}

AnimationComponent::~AnimationComponent()
{
    for (auto& pair : this->_animations)
    {
        delete pair.second;
    }

    this->_animations.clear();
}

void AnimationComponent::initialize(bool force)
{
    this->activate();
}

void AnimationComponent::terminate()
{
    this->deactivate();
}

void AnimationComponent::update(float deltaTime)
{
    if (this->_currentAnimation != nullptr)
        this->_currentAnimation->update(deltaTime);
}   

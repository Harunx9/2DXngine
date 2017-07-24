#pragma once
#include <string>
#include <map>
#include "../../ComponentModel/UpdateableComponent.h"
#include "../../Utils/Math/RectangleI.h"
#include "AnimationFactory/Animation.h"

typedef std::map<std::string, Animation*> animations_dict;

class AnimationComponent : public UpdateableComponent
{
public:
    ADD_TYPE_META_INFO()
        AnimationComponent(animations_dict animations);
    ~AnimationComponent();

    void play_animation(std::string animationName, bool loop = false)
    {
        this->_currentAnimation = _animations[animationName];
        this->_currentAnimation->start(loop);
    }

    void stop()
    {
        this->_currentAnimation->stop();
    }

    RectangleI get_currentFrame()
    {
        return this->_currentAnimation->get_currentFrame();
    }

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void update(float deltaTime) override;
private:
    Animation* _currentAnimation;
    animations_dict _animations;
};


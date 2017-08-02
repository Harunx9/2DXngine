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
        if (this->_currentAnimation != nullptr)
        {
            if (this->_currentAnimation->get_isPlaying() &&
                this->_currentAnimation->get_name() != animationName)
            {
                this->_currentAnimation->stop();
            }
        }

        this->_currentAnimation = _animations[animationName];
        this->_currentAnimation->start(loop);
    }

    void stop_animation()
    {
        this->_currentAnimation->stop();
    }

    void pause_animation()
    {
        this->_currentAnimation->pause();
    }

    RectangleI* get_currentFrame()
    {
        return &this->_currentAnimation->get_currentFrame();
    }

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void update(float deltaTime) override;
private:
    Animation* _currentAnimation;
    animations_dict _animations;
};


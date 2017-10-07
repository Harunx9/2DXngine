#pragma once
#include <string>
#include "../../../Utils/Macros/PropertyMacro.h"
#include "../../../Utils/Math/RectangleI.h"

class Animation
{
public:
    Animation(std::string name, int framesPerSecond, int framesCount, RectangleI* frames);
    ~Animation();

    void update(float deltaTime);

    void start(bool looped = false)
    {
        this->_isLooped = looped;
        this->_isPlaying = true;
    }

    void pause()
    {
        this->_isPlaying = false;
        this->_isLooped = false;
    }

    void stop()
    {
        this->_currentFrame = 0;
        this->_currentFrameTime = 0.f;
        this->_isPlaying = false;
        this->_isLooped = false;
    }

    RectangleI get_currentFrame() const
    {
        return this->_frames[this->_currentFrame];
    }

    READONLY_PROPERTY(bool, isLooped)
    READONLY_PROPERTY(bool, isPlaying)
    READONLY_PROPERTY(std::string, name)
    READONLY_PROPERTY(int, framesPerSecond)
    READONLY_PROPERTY(int, framesCount)
private:
    float _frameTime;
    float _currentFrameTime;
    int _currentFrame;
    RectangleI* _frames;
};

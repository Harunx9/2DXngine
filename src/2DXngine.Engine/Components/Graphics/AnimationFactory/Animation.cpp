#include "Animation.h"

Animation::Animation(std::string name, int framesPerSecond, int framesCount, RectangleI* frames) :
    _name(name),
    _framesPerSecond(framesPerSecond),
    _framesCount(framesCount),
    _frameTime(1.f / framesPerSecond),
    _currentFrame(0),
    _currentFrameTime(0.f)
{
    this->_frames = frames;
}

Animation::~Animation()
{
    delete this->_frames;
}

void Animation::update(float deltaTime)
{
    if (this->_isPlaying)
    {
        this->_currentFrameTime += deltaTime;
        
        if (this->_currentFrameTime >= this->_frameTime)
        {
            this->_currentFrame += 1;
            this->_currentFrameTime = 0;
        }

        if (this->_currentFrame >= this->_framesCount)
        {
            if (this->_isLooped == false)
            {
                this->stop();
            }
            this->_currentFrame = 0;
        }
    }
}

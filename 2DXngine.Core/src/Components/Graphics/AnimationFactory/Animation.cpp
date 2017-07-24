#include "Animation.h"

Animation::Animation(std::string name, int framesPerSecond, int framesCount, RectangleI frames[]) :
    _name(name), _framesPerSecond(framesPerSecond), _framesCount(framesCount)
{
    this->_frames = frames;
}

Animation::~Animation()
{

}

void Animation::update(float deltaTime)
{
    this->_currentFrameTime += deltaTime;
}

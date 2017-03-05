#include "Timer.h"

Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::timerStart()
{
    this->_timePrev = stopwatch::now();
}


float Timer::getDeltaTime()
{
    auto timeCurrent = stopwatch::now();
    auto deltaTime = time_diff(timeCurrent - _timePrev);
    this->_timePrev = timeCurrent;
    return deltaTime.count();
}

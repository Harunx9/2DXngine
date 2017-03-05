#pragma once
#include <chrono>

typedef std::chrono::time_point<std::chrono::high_resolution_clock> timespan;
typedef std::chrono::high_resolution_clock stopwatch;
typedef std::chrono::duration<float> time_diff;

class Timer
{
public:
    Timer();
    Timer(const Timer& other) = delete;
    virtual ~Timer();
    void timerStart();
    float getDeltaTime();
private:
    timespan _timePrev;
};


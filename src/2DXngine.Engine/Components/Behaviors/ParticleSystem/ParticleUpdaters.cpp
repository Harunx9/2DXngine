#include "ParticleUpdaters.h"

//ConstAccelerationUpdater
ConstAccelerationUpdater::ConstAccelerationUpdater(glm::vec2 globalVelocity)
    : ParticleUpdater(),
    _globalVelocity(globalVelocity)
{
}

ConstAccelerationUpdater::~ConstAccelerationUpdater()
{
}

void ConstAccelerationUpdater::update(float dt, ParticlesData *data)
{
    float localDt = dt;
    size_t particleCount = data->countActive;
    for (size_t particle = 0; particle < particleCount; particle++)
    {
        data->positions[particle] += this->_globalVelocity * dt;
    }
}

//TimeUpdater
TimeUpdater::TimeUpdater()
    : ParticleUpdater()
{
}

TimeUpdater::~TimeUpdater()
{
}

void TimeUpdater::update(float dt, ParticlesData *data)
{
    float localDt = dt;
    size_t particleCount = data->countActive;
    for (size_t particle = 0; particle < particleCount; particle++)
    {
        if (data->aliveTimes[particle] <= 0.f)
        {
            data->kill(particle);
            continue;
        }

        data->aliveTimes[particle] -= dt;
    }
}

//AccelerationUpdater
AccelerationUpdater::AccelerationUpdater()
    : ParticleUpdater()
{
}

AccelerationUpdater::~AccelerationUpdater()
{
}

void AccelerationUpdater::update(float dt, ParticlesData *data)
{
    float localDt = dt;
    size_t particleCount = data->countActive;
    for (size_t particle = 0; particle < particleCount; particle++)
    {
        data->positions[particle] += data->speedes[particle] * dt;
    }
}
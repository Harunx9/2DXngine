#include "ParticleUpdaters.h"
#include "../../../Graphics/Camera.h"
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

//OnScreenUpdater
OnScreenUpdater::OnScreenUpdater(Camera* camera)
    : ParticleUpdater(), _camera(camera)
{
}

OnScreenUpdater::~OnScreenUpdater()
{
    _camera = nullptr;
}

void OnScreenUpdater::update(float dt, ParticlesData *data)
{
    size_t particleCount = data->countActive;
    for (size_t particle = 0; particle < particleCount; particle++)
    {
        auto pos = data->positions[particle];
        auto texRect = data->textureFrames[particle];
        if (this->_camera->isInCamera({(int) pos.x, (int)pos.y, texRect.get_width(), texRect.get_height() }) == false)
        {
            data->kill(particle);
        }
    }
}

//AccelerationUpdater
DistanceUpdater::DistanceUpdater(float maxDist, int maxParticleCount)
    : ParticleUpdater(), _maxDist(maxDist), _maxParticleCount(maxParticleCount)
{
    this->_distances = new float[maxParticleCount];
    for (size_t particle = 0; particle < maxParticleCount; particle++)
    {
        this->_distances[particle] = 0.f;
    }
}

DistanceUpdater::~DistanceUpdater()
{
    delete this->_distances;
}

void DistanceUpdater::update(float dt, ParticlesData *data)
{
    size_t particleCount = data->countActive;
    for (size_t particle = 0; particle < particleCount; particle++)
    {
        auto dist = glm::length( data->speedes[particle] * dt);
        this->_distances[particle] += dist;
        if (this->_distances[particle] > this->_maxDist)
        {
            data->kill(particle);
            std::swap(this->_distances[particle], this->_distances[_maxParticleCount - 1]);
        }
    }
}
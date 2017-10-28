#include "BaseTypes.h"
#include <glm/glm.hpp>

class Camera;

class ConstAccelerationUpdater : public ParticleUpdater
{
public:
    ConstAccelerationUpdater(glm::vec2 globalVelocity);
    ~ConstAccelerationUpdater();

    virtual void update(float dt, ParticlesData *data) override;
private:
    glm::vec2 _globalVelocity;
};


class TimeUpdater : public ParticleUpdater
{
public:
    TimeUpdater();
    ~TimeUpdater();

    virtual void update(float dt, ParticlesData *data) override;
};


class AccelerationUpdater : public ParticleUpdater
{
public:
    AccelerationUpdater();
    ~AccelerationUpdater();

    virtual void update(float dt, ParticlesData *data) override;
};

class OnScreenUpdater: public ParticleUpdater
{
public:
    OnScreenUpdater(Camera* camera);
    ~OnScreenUpdater();

    virtual void update(float dt, ParticlesData *data) override;
private:
    Camera* _camera;
};


class DistanceUpdater: public ParticleUpdater
{
public:
    DistanceUpdater(float maxDist, int maxParticleCount);
    ~DistanceUpdater();

    virtual void update(float dt, ParticlesData *data) override;
private:
    float* _distances;
    float _maxDist;
    int _maxParticleCount;
};

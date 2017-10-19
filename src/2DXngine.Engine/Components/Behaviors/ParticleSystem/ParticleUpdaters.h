#include "BaseTypes.h"
#include <glm/glm.hpp>

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

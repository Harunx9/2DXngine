#pragma once
#include "../../ComponentModel/UpdateableComponent.h"
#include "../Graphics/SpriteSheetComponent.h"
#include "../Graphics/Transform.h"
#include "ParticleSystem\BaseTypes.h"
#include <vector>

class ParticleSystemBehavior : public UpdateableComponent
{
public:
    ADD_TYPE_META_INFO()
    ParticleSystemBehavior(ParticleEmiter * emiter,
        std::vector<ParticleUpdater *> updaters,
        size_t maxParticles = 100);
    ~ParticleSystemBehavior();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void update(float deltaTime) override;
    
    inline ParticlesData* get_particles()
    {
        return &this->_data;
    }
    
    READONLY_PROPERTY(Transform *, transform)
    READONLY_PROPERTY(SpriteSheetComponent*, spriteSheet)
private:
    size_t _maxParticles;
    ParticlesData _data; 
    ParticleEmiter * _emiter;
    std::vector<ParticleUpdater *> _updaters;
};


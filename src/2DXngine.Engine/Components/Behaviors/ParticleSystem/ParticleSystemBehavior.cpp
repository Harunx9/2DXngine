#include "ParticleSystemBehavior.h"
#include "../../../ComponentModel/GameObject.h"
ParticleSystemBehavior::ParticleSystemBehavior(
    ParticleEmiter * emiter,
    std::vector<ParticleUpdater *> updaters,
    size_t maxParticles) : UpdateableComponent("ParticleSystemBehavior"),
    _emiter(emiter),
    _updaters(updaters),
    _maxParticles(maxParticles)
{
}

ParticleSystemBehavior::~ParticleSystemBehavior()
{
    delete this->_emiter;

    for (auto& up : this->_updaters)
        delete up;

    this->_updaters.clear();
}

void ParticleSystemBehavior::initialize(bool force)
{
    this->_data.generate(this->_maxParticles);
    this->_emiter->initialize(this);
    this->activate();
}

void ParticleSystemBehavior::terminate()
{
    this->deactivate();
    this->_spriteSheet = nullptr;
    this->_transform = nullptr;
}

void ParticleSystemBehavior::update(float deltaTime)
{
    this->_emiter->emit(deltaTime, &this->_data);

    for (auto& up : this->_updaters)
        up->update(deltaTime, &this->_data);
}

void ParticleSystemBehavior::resolveDependencies(bool force)
{
    this->_spriteSheet = this->_owner->findFirstComponentOfType<SpriteSheetComponent>();
    this->_transform = this->_owner->findFirstComponentOfType<Transform>();
}
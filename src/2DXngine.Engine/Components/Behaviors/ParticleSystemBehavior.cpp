#include "ParticleSystemBehavior.h"

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
}

void ParticleSystemBehavior::terminate()
{

}

void ParticleSystemBehavior::update(float deltaTime)
{
    this->_emiter->emit(deltaTime, &this->_data);

    for (auto& up : this->_updaters)
        up->update(deltaTime, &this->_data);
}
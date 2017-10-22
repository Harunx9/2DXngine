#include "BaseTypes.h"
#include <algorithm>
#include "../../../Services/ServiceLocator.h"
#include "../../../Utils/Logger/LoggerService.h"
void ParticlesData::generate(size_t maxSize)
{
    this->count = maxSize;
    this->countActive = 0;

    this->positions = new glm::vec2[maxSize];
    this->speedes = new glm::vec2[maxSize];
    this->accelerations = new glm::vec2[maxSize];
    this->colors = new Color[maxSize];
    this->textureFrames = new RectangleI[maxSize];
    this->aliveTimes = new float[maxSize];
    this->active = new bool[maxSize];
}

void ParticlesData::kill(size_t id)
{
    if (this->countActive > 0)
    {
        this->active[id] = false;
        this->swapData(id, this->countActive - 1);
        this->countActive--;
    }
}

void ParticlesData::wake(size_t id)
{
    if (this->countActive < this->count)
    {
        this->active[id] = true;
        this->swapData(id, this->countActive);
        this->countActive++;
    }
}

void ParticlesData::swapData(size_t src, size_t dest)
{
    std::swap(this->positions[src], this->positions[dest]);
    std::swap(this->speedes[src], this->speedes[dest]);
    std::swap(this->accelerations[src], this->accelerations[dest]);
    std::swap(this->colors[src], this->colors[dest]);
    std::swap(this->textureFrames[src], this->textureFrames[dest]);
    std::swap(this->aliveTimes[src], this->aliveTimes[dest]);
    std::swap(this->active[src], this->active[dest]);
}

ParticleEmiter::ParticleEmiter(std::vector<ParticleGenerator*> generators, float emitRate) :
    _generators(generators),
    _emitRate(emitRate)
{
}

ParticleEmiter::~ParticleEmiter()
{
    for (auto & gen : this->_generators)
        delete gen;

    this->_generators.clear();
}

void ParticleEmiter::initialize(ParticleSystemBehavior * component)
{
    for (auto& gen : this->_generators)
        gen->initialize(component);

    this->_isInitialized = true;
    this->_logger = ServiceLocator::get<LoggerService>("LoggerService");
}

void ParticleEmiter::emit(float dt, ParticlesData * data)
{
    const size_t maxNewParticles = static_cast<size_t>(dt* this->_emitRate);
    const size_t startId = data->countActive;
    const size_t endId = (std::min)(startId + maxNewParticles, data->count - 1);

    if (endId != 0)
    {
        this->_logger->info("EndId : %l", endId);
    }

    for (auto & gen : this->_generators)
        gen->generate(dt, data, startId, endId);

    for (size_t i = startId; i < endId; ++i)
    {
        data->wake(i);
    }
}
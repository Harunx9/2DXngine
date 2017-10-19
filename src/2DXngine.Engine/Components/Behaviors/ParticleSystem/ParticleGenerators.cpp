#include "ParticleGenerators.h"
#include "../../Graphics/Transform.h"
#include <glm/gtc/random.hpp>
#include "../ParticleSystemBehavior.h"

// AreaParticleGenerator

AreaParticleGenerator::AreaParticleGenerator() : ParticleGenerator()
{
}

AreaParticleGenerator::~AreaParticleGenerator(){
    this->_transform = nullptr;
}

void AreaParticleGenerator::initialize(ParticleSystemBehavior * component)
{
    this->_transform = component->get_transform();
    this->_isInitialized = true;
}

void AreaParticleGenerator::generate(float dt, ParticlesData *data, size_t startId, size_t endId)
{
    glm::vec2 minPosition{ this->_transform->get_x(), this->_transform->get_y() };
    glm::vec2 maxPosition{
        this->_transform->get_x() + this->_transform->get_width(),
        this->_transform->get_y() + this->_transform->get_heihgt() };

    for (size_t particle = startId; particle < endId; particle++)
    {
        data->positions[particle] = glm::linearRand(minPosition, maxPosition);
    }
}

//AllFrameRectsGenerator

AllFrameRectsGenerator::AllFrameRectsGenerator(int maxRects) 
    : ParticleGenerator(),
    _maxRects(maxRects)
{
}

AllFrameRectsGenerator::~AllFrameRectsGenerator() {}

void AllFrameRectsGenerator::initialize(ParticleSystemBehavior * component) 
{
    this->_rects = component
        ->get_spriteSheet()
        ->get_allFrames();

    this->_maxRects = component
        ->get_spriteSheet()
        ->get_sheetSize();
}

void AllFrameRectsGenerator::generate(float dt, ParticlesData *data, size_t startId, size_t endId) 
{
    for (size_t particle = startId; particle < endId; particle++)
    {
        int rect = glm::linearRand(0, this->_maxRects);
        data->textureFrames[particle] = this->_rects[rect];
    }
}

//FilteredFrameRectsGenerator

FilteredFrameRectsGenerator::FilteredFrameRectsGenerator(std::function<bool(std::pair<std::string, RectangleI>)> predicate)
    : ParticleGenerator(),
    _predicate(predicate)
{
}

FilteredFrameRectsGenerator::~FilteredFrameRectsGenerator() {}

void FilteredFrameRectsGenerator::initialize(ParticleSystemBehavior * component)
{
    this->_rects = component
        ->get_spriteSheet()
        ->filterFrames(this->_predicate);
    this->_rectCount = this->_rects.size();
}

void FilteredFrameRectsGenerator::generate(float dt, ParticlesData *data, size_t startId, size_t endId)
{
    for (size_t particle = startId; particle < endId; particle++)
    {
        int rect = glm::linearRand(0, this->_rectCount);
        data->textureFrames[particle] = this->_rects[rect];
    }
}

// LinearConstVelocityGenerator

LinearConstVelocityGenerator::LinearConstVelocityGenerator(glm::vec2 velocity) 
    : ParticleGenerator(),
    _velocity(velocity)
{
}

LinearConstVelocityGenerator::~LinearConstVelocityGenerator(){}

void LinearConstVelocityGenerator::generate(float dt, ParticlesData *data, size_t startId, size_t endId)
{
    for (size_t particle = startId; particle < endId; particle++)
    {
        data->accelerations[particle] = this->_velocity;
    }
}


// LinearVelocityGenerator

LinearVelocityGenerator::LinearVelocityGenerator(glm::vec2 velocityMin, glm::vec2 velocityMax)
    : ParticleGenerator(),
    _velocityMin(velocityMin),
    _velocityMax(velocityMax)
{
}

LinearVelocityGenerator::~LinearVelocityGenerator() {}

void LinearVelocityGenerator::generate(float dt, ParticlesData *data, size_t startId, size_t endId)
{
    
    glm::vec2 acc = glm::linearRand(this->_velocityMin, this->_velocityMax);

    for (size_t particle = startId; particle < endId; particle++)
    {
        data->accelerations[particle] = acc;
    }
}

// AliveTimeGenerator

AliveTimeGenerator::AliveTimeGenerator(float minAliveTime, float maxAliveTime)
    : ParticleGenerator(),
    _minAliveTime(minAliveTime),
    _maxAliveTime(maxAliveTime)
{
}

AliveTimeGenerator::~AliveTimeGenerator() {}

void AliveTimeGenerator::generate(float dt, ParticlesData *data, size_t startId, size_t endId)
{
    float time = this->_maxAliveTime;
    if (this->_minAliveTime > 0.f)
        float time = glm::linearRand(this->_minAliveTime, this->_maxAliveTime);

    for (size_t particle = startId; particle < endId; particle++)
    {
        data->aliveTimes[particle] = time;
    }
}
#pragma once
#include <glm\glm.hpp>
#include <vector>
#include "../../../Graphics/Color.h"
#include "../../../Utils/Math/RectangleI.h"
class ParticleSystemBehavior;

class ParticlesData
{
public:
    ParticlesData(const ParticlesData &) = delete;
    ParticlesData &operator=(const ParticlesData &) = delete;

    ParticlesData() {}
    explicit ParticlesData(size_t maxParticles) { generate(maxParticles); }
    ~ParticlesData() 
    {
        delete positions;
        delete speedes;
        delete accelerations;
        delete colors;
        delete textureFrames;
        delete active;
    };

    void generate(size_t maxSize);
    void kill(size_t id);
    void wake(size_t id);
    void swapData(size_t src, size_t dest);
    
    glm::vec2 * positions;
    glm::vec2 * speedes;
    glm::vec2 * accelerations;
    Color * colors;
    RectangleI * textureFrames;
    float * aliveTimes;
    bool * active;

    size_t countActive{ 0 };
    size_t count{ 0 };
};

class ParticleGenerator
{
public:
    ParticleGenerator(){}
    ~ParticleGenerator(){}
    
    virtual void initialize(ParticleSystemBehavior * component) { this->_isInitialized = true; };
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) = 0;

    bool get_isInitialized() const
    {
        return this->_isInitialized;
    }
protected:
    bool _isInitialized{ false };
};

class ParticleUpdater
{
public:
    ParticleUpdater(){}
    ~ParticleUpdater(){}

    virtual void update(float dt, ParticlesData *data) = 0;
};

class ParticleEmiter
{
public:
    explicit ParticleEmiter(std::vector<ParticleGenerator*> generators, float emitRate);
    ~ParticleEmiter();
    
    void initialize(ParticleSystemBehavior * component);
    void emit(float dt, ParticlesData *data);

    bool get_isInitialized() const
    {
        return this->_isInitialized;
    }
protected:
    bool _isInitialized{ false };

private:
    std::vector<ParticleGenerator*> _generators;
    float _emitRate;
};
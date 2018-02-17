#pragma once
#include <functional>
#include <vector>
#include "BaseTypes.h"
#include <glm/glm.hpp>
class Transform;

class AreaParticleGenerator : public ParticleGenerator
{
public:
    AreaParticleGenerator();
    ~AreaParticleGenerator();
    virtual void initialize(ParticleSystemBehavior * component) override;
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) override;
private:
    Transform * _transform{ nullptr };
};

class AllFrameRectsGenerator : public ParticleGenerator
{
public:
    AllFrameRectsGenerator();
    ~AllFrameRectsGenerator();
    virtual void initialize(ParticleSystemBehavior * component) override;
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) override;
private:
    RectangleI * _rects{ nullptr };
    int _maxRects;
};

class FilteredFrameRectsGenerator : public ParticleGenerator
{
public:
    FilteredFrameRectsGenerator(std::function<bool(std::pair<std::string, RectangleI>)> predicate);
    ~FilteredFrameRectsGenerator();
    virtual void initialize(ParticleSystemBehavior * component) override;
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) override;
private:
    std::function<bool(std::pair<std::string, RectangleI>)> _predicate;
    int _rectCount;
    std::vector<RectangleI> _rects;
};

class LinearConstVelocityGenerator : public ParticleGenerator
{
public:
    LinearConstVelocityGenerator(glm::vec2 velocity);
    ~LinearConstVelocityGenerator();
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) override;
private:
    glm::vec2 _velocity;
};

class LinearVelocityGenerator : public ParticleGenerator
{
public:
    LinearVelocityGenerator(glm::vec2 velocityMin, glm::vec2 velocityMax);
    ~LinearVelocityGenerator();
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) override;
private:
    glm::vec2 _velocityMin;
    glm::vec2 _velocityMax;
};

class AliveTimeGenerator : public ParticleGenerator
{
public:
    AliveTimeGenerator(float minAliveTime, float maxAliveTime);
    ~AliveTimeGenerator();
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) override;
private:
    float _maxAliveTime;
    float _minAliveTime;
};

class ColorGenerator : public ParticleGenerator
{
public:
    ColorGenerator(Color color);
    ~ColorGenerator();
    virtual void generate(float dt, ParticlesData *data, size_t startId, size_t endId) override;
private:
    Color _color;
};
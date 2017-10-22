#include "ParticleSystemDrawable.h"
#include "../../ComponentModel/GameObject.h"
#include "../../Graphics/Camera.h"

ParticleSystemDrawableComponent::ParticleSystemDrawableComponent() :
    ParticleSystemDrawableComponent(DefaultLayers::GAMEPLAY_LAYER)
{
}

ParticleSystemDrawableComponent::ParticleSystemDrawableComponent(SceneLayer layer) :
    ParticleSystemDrawableComponent(layer, 
        TextureFilter::LINEAR_FILTER, 
        TextureWrap::CLAMP_TO_EDGE)
{
}

ParticleSystemDrawableComponent::ParticleSystemDrawableComponent(SceneLayer layer, 
    TextureFilter filter, TextureWrap wrap) :
    DrawableComponent(layer, "ParticleSystemDrawableComponent"),
    _wrap(wrap),
    _filter(filter)
{
}

ParticleSystemDrawableComponent::~ParticleSystemDrawableComponent()
{
}

void ParticleSystemDrawableComponent::initialize(bool force)
{
    this->_behavior = this->_owner->findFirstComponentOfType<ParticleSystemBehavior>();
    this->_spriteComponent = this->_owner->findFirstComponentOfType<SpriteComponent>();
}

void ParticleSystemDrawableComponent::terminate()
{
    this->_behavior = nullptr;
    this->_spriteComponent = nullptr;
}

void ParticleSystemDrawableComponent::draw(Renderer * renderer, Camera* camera, float deltaTime)
{
    auto data = this->_behavior->get_particles();
    size_t active = data->countActive;
    auto batch = renderer->get_batch();
    batch->begin(nullptr, this->_wrap, this->_filter, camera->get_viewMatrix());
    for (size_t particle = 0; particle < active; particle++)
    {
        batch->draw(this->_spriteComponent->get_texture(),
            data->positions[particle],
            &data->textureFrames[particle],
            Colors::white,
            0.f);
    }
    batch->end();
}
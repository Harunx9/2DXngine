#include "Renderer.h"

Renderer::Renderer(SpriteBatch * batch) :
    _batch(batch)
{
    _graphics = batch->get_device();
    this->_registerdLayer = std::vector<SceneLayer*>();
    this->_currentTargets = std::map<std::string, RenderTarget*>();
}

Renderer::~Renderer()
{
    if (this->_currentTargets.empty() == false)
    {
        for (auto& pair : this->_currentTargets)
        {
            delete pair.second;
        }
        this->_currentTargets.clear();
    }

    for (auto& layer : this->_registerdLayer)
    {
        delete layer;
    }

    this->_registerdLayer.clear();
}

void Renderer::registerLayer(SceneLayer * layer)
{
    this->_registerdLayer.push_back(layer);
}

void Renderer::beginRendering()
{
    if (this->_currentTargets.empty() == false)
    {
        for (auto& pair : this->_currentTargets)
        {
            delete pair.second;
        }
        this->_currentTargets.clear();
    }

    for (auto& layer : this->_registerdLayer)
    {
        Viewport viewport = this->_graphics
            ->get_viewport();

        this->_currentTargets[layer->get_name()] = new RenderTarget(viewport.width, viewport.height);
    }
}

void Renderer::drawAllTargets(glm::mat4 camera, TextureFilter filter, TextureWrap wrap)
{
    std::sort(this->_registerdLayer.begin(), this->_registerdLayer.end(),
        [=](SceneLayer* layer1, SceneLayer* layer2) { return layer1->get_order() < layer2->get_order(); });

    this->_batch->begin(nullptr, wrap, filter, camera);

    for (auto& layer : this->_registerdLayer)
    {
        RenderTarget* target = this->_currentTargets[layer->get_name()];

        RectangleI viewportRect = this->_graphics
            ->get_viewport()
            .toRectangle();

        this->_batch->draw(
            target,
            viewportRect,
            Colors::white,
            (float)layer->get_order());
    }

    this->_batch->end();
}

void Renderer::applyEffectShader(ShaderProgram * program, SceneLayer * layer, TextureFilter filter, TextureWrap wrap, glm::mat4 camera)
{
    RenderTarget* target = this->_currentTargets[layer->get_name()];

    RenderTarget* newTarget = new RenderTarget(
        target
        ->get_bitmap()
        ->get_width(),
        target
        ->get_bitmap()
        ->get_height());

    RectangleI viewportRect = this->_graphics
        ->get_viewport()
        .toRectangle();

    this->_batch->set_renderTarget(newTarget);
    this->_batch->begin(program, wrap, filter, camera);

    this->_batch->draw(
        target,
        viewportRect,
        Colors::white,
        (float)layer->get_order());

    this->_batch->end();
    this->_batch->set_renderTarget(nullptr);

    delete target;
    this->_currentTargets[layer->get_name()] = newTarget;
}

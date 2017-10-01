#pragma once
#include "../Scenes/SceneLayer.h"
#include "SpriteBatch.h"
#include "GraphicDevice.h"
#include "../Utils/Macros/PropertyMacro.h"
#include <vector>
#include <map>

class Renderer
{
public:
    Renderer(SpriteBatch* batch);
    virtual ~Renderer();

    void registerLayer(SceneLayer* layer);
    void beginRendering();
    void drawAllTargets(glm::mat4 camera, TextureFilter filter, TextureWrap wrap);
    void applyEffectShader(ShaderProgram * program, SceneLayer * layer, TextureFilter filter, TextureWrap wrap, glm::mat4 camera);

    READONLY_PROPERTY(SpriteBatch*, batch)
    READONLY_PROPERTY(GraphicDevice*, graphics)

    bool has_layer(SceneLayer* layer)
    {
        return this->_currentTargets.find(layer->get_name()) != this->_currentTargets.end();
    }

    void set_batchTarget(SceneLayer* layer)
    {
        this->_batch->set_renderTarget(this->_currentTargets[layer->get_name()]);
    }

    void reset_batchTarget()
    {
        this->_batch->set_renderTarget(nullptr);
    }
private:
    std::vector<SceneLayer*> _registerdLayer;
    std::map<std::string, RenderTarget*> _currentTargets;
};


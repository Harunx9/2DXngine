#pragma once
#include "../Scenes/SceneLayer.h"
#include "SpriteBatch.h"
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
    void drawAllTargets();
    void applyEffectShader(ShaderProgram * program, SceneLayer* layer);

    READONLY_PROPERTY(SpriteBatch*, batch)
private:
    std::vector<SceneLayer*> _registerdLayer;
    std::map<std::string, RenderTarget*> currentTargets;
};


#include "Renderer.h"


Renderer::Renderer(SpriteBatch * batch)
{
    this->_registerdLayer = std::vector<SceneLayer*>();
}

Renderer::~Renderer()
{
}

void Renderer::registerLayer(SceneLayer * layer)
{
}

void Renderer::beginRendering()
{
    

}

void Renderer::drawAllTargets()
{
}

void Renderer::applyEffectShader(ShaderProgram * program, SceneLayer * layer)
{
}

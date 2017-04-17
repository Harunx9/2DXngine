#pragma once
#include "RenderTarget.h"
#include <glm\glm.hpp>

class ShaderProgram;

class SpriteBatch
{
public:
    SpriteBatch();
    ~SpriteBatch();

    void set_renderTarget(const RenderTarget* target);
    void begin();
    void begin(ShaderProgram * shader, glm::vec2 scale, bool sort, glm::mat4 * viewport = nullptr);
    void end();

    void draw(Texture* texture, glm::vec2 position, glm::vec4 color);
    void draw(Texture* texture, glm::vec2 sourcePosition, glm::vec2 sourceDirection, glm::vec4 color);
    

private:
    void initializeDefaultShader();

    RenderTarget * _currentTarget;
    ShaderProgram * _defaultShader;
};


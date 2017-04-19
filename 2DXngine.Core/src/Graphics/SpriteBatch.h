#pragma once
#include "RenderTarget.h"
#include <glm\glm.hpp>

class ShaderProgram;
class Rectangle;

enum FlipEffect
{
    NONE,
    FLIP_HORIZONTAL,
    FLIP_VERTICAL,
    FLIP_BOTH,
};


class SpriteBatch
{
public:
    SpriteBatch();
    ~SpriteBatch();

    bool initialize();

    void set_renderTarget(const RenderTarget* target);
    void begin();
    void begin(ShaderProgram * shader, glm::vec2 scale, bool sort, glm::mat4 * viewport = nullptr);
    void end();

    void draw(Texture* texture, glm::vec2 position, glm::vec4 color);
    void draw(Texture* texture, glm::vec2 position, glm::vec4 color, float rotation, FlipEffect effect);
    void draw(Texture* texture, glm::vec2 sourcePosition, glm::vec2 sourceDirection, glm::vec4 color);
    void draw(Texture* texture, glm::vec2 sourcePosition, glm::vec2 sourceDirection, glm::vec4 color, float rotation);
    void draw(Texture* texture, glm::vec2 sourcePosition, glm::vec2 sourceDirection, glm::vec4 color, FlipEffect effect);
    void draw(Texture* texture, glm::vec2 sourcePosition, glm::vec2 sourceDirection, glm::vec4 color, float rotation, FlipEffect effect);

private:
    bool initializeDefaultShader();
    bool isRenderTargetSet();

    const RenderTarget * _currentTarget;
    ShaderProgram * _defaultShader;
    ShaderProgram * _customShader;
    bool _isInitialized;
};


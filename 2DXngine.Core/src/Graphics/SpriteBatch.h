#pragma once
#include <GL\glew.h>
#include "../ContentManagement/DefaultAssets/Texture.h"
#include "RenderTarget.h"
#include "SamplerState.h"
#include <glm\glm.hpp>
#include <algorithm>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "../Utils/Math/Rectangle.h"
#include "GraphicDevice.h"
#define MAX_BATCH_ITEMS 2048

class ShaderProgram;


enum FlipEffect
{
    NONE_FLIP,
    FLIP_HORIZONTAL,
    FLIP_VERTICAL,
};

enum SortMode
{
    NONE_SORT,
    FRONT_TO_BACK,
    BACK_TO_FRONT,
};

class SpriteBatch
{
public:
    SpriteBatch(GraphicDevice* device);
    ~SpriteBatch();

    bool initialize();

    void set_renderTarget(RenderTarget* target);
    void begin();
    void begin(TextureWrap wrap, TextureFilter filter);
    void begin(ShaderProgram * shader, TextureWrap wrap, TextureFilter filter, glm::mat4 viewport);
    void end();

    void draw(Texture* texture, glm::vec2 position, glm::vec4 color, float drawOrder);
    void draw(Texture* texture, Rectangle destinationRectangle, glm::vec4 color, float drawOrder);
    void draw(Texture* texture, glm::vec2 position, Rectangle* sourceRectangle, glm::vec4 color, float drawOrder);
    void draw(Texture* texture, Rectangle destinationRectangle, Rectangle* sourceRectangle, glm::vec4 color, float drawOrder);
    void draw(Texture* texture, Rectangle destinationRectangle, Rectangle* sourceRectangle, glm::vec4 color, float rotation, glm::vec2 origin, FlipEffect flip, float drawOrder);
    void draw(Texture* texture, glm::vec2 position, Rectangle* sourceRectangle, glm::vec4 color, float rotation, glm::vec2 origin, glm::vec2 scale, FlipEffect flip, float drawOrder);
    void draw(Texture* texture, glm::vec2 position, Rectangle* sourceRectangle, glm::vec4 color, float rotation, glm::vec2 origin, float scale, FlipEffect flip, float drawOrder);

private:
    struct SpriteBatchItem
    {
        Texture * texture;
        glm::vec2 postions[4];
        glm::vec2 texcoords[4];
        glm::vec4 color;
        glm::vec2 origin;
        GLfloat rot;
        float drawOrder;
    };

    void drawBatch();

    void clearBatchItems();
    SpriteBatchItem * createNewItem();

    glm::mat4 _viewport;
    bool initializeDefaultShader();
    bool isRenderTargetSet();
    size_t _currentSpriteCount;
    std::vector<SpriteBatchItem*>  _items;
    RenderTarget * _currentTarget;
    ShaderProgram * _defaultShader;
    ShaderProgram * _customShader;
    bool _isInitialized;
    bool _isStarted;
    SortMode _sortMode;
    SamplerState* _sampler;
    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;
    GraphicDevice* _device;
    GLfloat _vertexBuffer[MAX_BATCH_ITEMS * 32];
};


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
#include "GraphicDevice.h"
#include "../Utils/Math/RectangleI.h"
#include "../Utils/Macros/PropertyMacro.h"
#include "Color.h"
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
    void begin(ShaderProgram * shader, TextureWrap wrap, TextureFilter filter, glm::mat4 viewportTransform);
    void end();

    void draw(Texture* texture, glm::vec2 position, Color color, float drawOrder);
    void draw(Texture* texture, RectangleI destinationRectangle, Color color, float drawOrder);
    void draw(Texture* texture, glm::vec2 position, RectangleI* sourceRectangle, Color color, float drawOrder);
    void draw(Texture* texture, RectangleI destinationRectangle, RectangleI* sourceRectangle, Color color, float drawOrder);
    void draw(Texture* texture, RectangleI destinationRectangle, RectangleI* sourceRectangle, Color color, float rotation, glm::vec2 origin, FlipEffect flip, float drawOrder);
    void draw(Texture* texture, glm::vec2 position, RectangleI* sourceRectangle, Color color, float rotation, glm::vec2 origin, glm::vec2 scale, FlipEffect flip, float drawOrder);
    void draw(Texture* texture, glm::vec2 position, RectangleI* sourceRectangle, Color color, float rotation, glm::vec2 origin, float scale, FlipEffect flip, float drawOrder);

    bool get_batchingStarted() const
    {
        return this->_items.empty() == false;
    }

    READONLY_PROPERTY(bool, isStarted)
    READONLY_PROPERTY(ShaderProgram *, customShader)
    READONLY_PROPERTY(GraphicDevice*, device)
private:
    struct SpriteBatchItem
    {
        GLuint texture;
        glm::vec2 postions[4];
        glm::vec2 texcoords[4];
        glm::vec4 color;
        glm::vec2 origin;
        float drawOrder;
    };

    void drawBatch();

    void clearBatchItems();
    SpriteBatchItem * createNewItem();

    glm::mat4 _viewport;
    glm::mat4 _viewportTransform;
    bool initializeDefaultShader();
    bool isRenderTargetSet();
    size_t _currentSpriteCount;
    std::vector<SpriteBatchItem*>  _items;
    RenderTarget * _currentTarget;
    ShaderProgram * _defaultShader;
    bool _isInitialized;
    SortMode _sortMode;
    SamplerState* _sampler;
    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;
    GLfloat _vertexBuffer[MAX_BATCH_ITEMS * 32];
};


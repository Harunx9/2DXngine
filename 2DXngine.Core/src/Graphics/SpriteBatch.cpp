#include "SpriteBatch.h"
#include "../ContentManagement/DefaultAssets/ShaderProgram.h"

SpriteBatch::SpriteBatch(GraphicDevice* device) :
    _device(device)
{
    
}

SpriteBatch::~SpriteBatch()
{
    delete this->_defaultShader;
    glDeleteBuffers(1, &this->_vao);
    glDeleteBuffers(1, &this->_ebo);
    glDeleteBuffers(1, &this->_vbo);
}

bool SpriteBatch::initialize()
{
    this->_items = std::vector<SpriteBatchItem*>();
    auto result = this->initializeDefaultShader();

    if (result)
    {
        this->_defaultShader->use();
        this->_sampler = new SamplerState(TextureWrap::REPEAT, TextureFilter::LINEAR);
        glGenVertexArrays(1, &_vao);
        glGenBuffers(1, &_vbo);
        glGenBuffers(1, &_ebo);

        glBindVertexArray(_vao);

        glBindBuffer(GL_ARRAY_BUFFER, _vbo);

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(4 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBufferData(GL_ARRAY_BUFFER, MAX_BATCH_ITEMS * (32 * sizeof(GLfloat)), this->_vertexBuffer, GL_DYNAMIC_DRAW);

        //Element array buffer
        GLint indices[6] = { 0, 1, 2, 2, 3, 1 };
        GLint *indice_array = new GLint[MAX_BATCH_ITEMS * 6];

        for (int i = 0; i < MAX_BATCH_ITEMS; ++i)
            for (int j = 0; j < 6; ++j)
                indice_array[i * 6 + j] = indices[j] + i * 4;

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_BATCH_ITEMS * 6 * sizeof(GLint), indice_array, GL_DYNAMIC_DRAW);

        delete[] indice_array;

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
        this->_isInitialized = true;
    }

    return result;
}

void SpriteBatch::set_renderTarget(RenderTarget * target)
{
    _currentTarget = target;
}

void SpriteBatch::begin()
{
    if (this->_isInitialized && this->_isStarted) return;

    this->_isStarted = true;
    this->_viewport = glm::mat4();

}

void SpriteBatch::begin(TextureWrap wrap, TextureFilter filter)
{
    if (this->_isInitialized && this->_isStarted) return;

    this->_isStarted = true;
    this->_viewport = glm::mat4();
    this->_sampler->changeFilter(filter);
    this->_sampler->changeWrap(wrap);
}

void SpriteBatch::begin(ShaderProgram * shader, TextureWrap wrap, TextureFilter filter, glm::mat4 viewport)
{
    if (this->_isInitialized && this->_isStarted) return;

    this->_customShader = shader;
    this->_viewport = viewport;
    this->_isStarted = true;
    this->_sampler->changeFilter(filter);
    this->_sampler->changeWrap(wrap);
}

void SpriteBatch::end()
{
    //draw to frame buffer
    if (this->_currentTarget == nullptr)
    {
        this->_currentTarget->begin();
        this->drawBatch();
        this->_currentTarget->end();
    }
    else //draw to backbuffer
    {
        this->drawBatch();
    }
}

void SpriteBatch::draw(Texture * texture, glm::vec2 position, glm::vec4 color, float drawOrder)
{
    auto batchItem = createNewItem();
    if (batchItem == nullptr)
        return;

    batchItem->texture = texture;
    //set positions
    batchItem->postions[0] = position;
    batchItem->postions[1] = glm::vec2(
        position.x + texture->get_bitmap()->get_width(),
        position.y);

    batchItem->postions[2] = glm::vec2(
        position.x,
        position.y + texture->get_bitmap()->get_height());

    batchItem->postions[3] = glm::vec2(
        position.x + texture->get_bitmap()->get_width(),
        position.y + texture->get_bitmap()->get_height());

    //set color
    batchItem->color = color;

    batchItem->drawOrder = drawOrder;

    batchItem->origin = glm::vec2(0.f, 0.f);
    batchItem->rot = 0.f;
    //texCoord
    batchItem->texcoords[0] = glm::vec2(0.f, 0.f);
    batchItem->texcoords[1] = glm::vec2(1.f, 0.f);
    batchItem->texcoords[2] = glm::vec2(0.f, 1.f);
    batchItem->texcoords[3] = glm::vec2(1.f, 1.f);
}

void SpriteBatch::draw(Texture * texture, Rectangle destinationRectangle, glm::vec4 color, float drawOrder)
{
    auto batchItem = createNewItem();
    if (batchItem == nullptr)
        return;

    batchItem->texture = texture;

    //set positions
    batchItem->postions[0] = glm::vec2(
        destinationRectangle.get_x(),
        destinationRectangle.get_y());

    batchItem->postions[1] = glm::vec2(
        destinationRectangle.get_x() + destinationRectangle.get_width(),
        destinationRectangle.get_y());

    batchItem->postions[2] = glm::vec2(
        destinationRectangle.get_x(),
        destinationRectangle.get_y() + destinationRectangle.get_height());

    batchItem->postions[3] = glm::vec2(
        destinationRectangle.get_x() + destinationRectangle.get_width(),
        destinationRectangle.get_y() + destinationRectangle.get_height());

    //set color
    batchItem->color = color;

    //origin
    batchItem->origin = glm::vec2(0.f, 0.f);

    //rotation
    batchItem->rot = 0.f;

    batchItem->drawOrder = drawOrder;

    //texCoord
    batchItem->texcoords[0] = glm::vec2(0.f, 0.f);
    batchItem->texcoords[1] = glm::vec2(1.f, 0.f);
    batchItem->texcoords[2] = glm::vec2(0.f, 1.f);
    batchItem->texcoords[3] = glm::vec2(1.f, 1.f);
}

void SpriteBatch::draw(Texture * texture, glm::vec2 position, Rectangle * sourceRectangle, glm::vec4 color, float drawOrder)
{
    auto batchItem = createNewItem();
    if (batchItem == nullptr)
        return;

    batchItem->texture = texture;

    //set positions
    batchItem->postions[0] = position;

    batchItem->postions[1] = glm::vec2(
        position.x + texture->get_bitmap()->get_width(),
        position.y);

    batchItem->postions[2] = glm::vec2(
        position.x,
        position.y + texture->get_bitmap()->get_height());

    batchItem->postions[3] = glm::vec2(
        position.x + texture->get_bitmap()->get_height(),
        position.y + texture->get_bitmap()->get_width());

    //set color
    batchItem->color = color;

    //origin
    batchItem->origin = glm::vec2(0.f, 0.f);

    //rotation
    batchItem->rot = 0.f;

    batchItem->drawOrder = drawOrder;

    //texCoord
    if (sourceRectangle != nullptr)
    {
        batchItem->texcoords[0] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[1] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[2] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[3] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());
    }
    else
    {
        batchItem->texcoords[0] = glm::vec2(0.f, 0.f);
        batchItem->texcoords[1] = glm::vec2(1.f, 0.f);
        batchItem->texcoords[2] = glm::vec2(0.f, 1.f);
        batchItem->texcoords[3] = glm::vec2(1.f, 1.f);
    }
}

void SpriteBatch::draw(Texture * texture, Rectangle destinationRectangle, Rectangle * sourceRectangle, glm::vec4 color, float drawOrder)
{
    auto batchItem = createNewItem();
    if (batchItem == nullptr)
        return;

    batchItem->texture = texture;

    batchItem->postions[0] = glm::vec2(
        destinationRectangle.get_x(),
        destinationRectangle.get_y());

    batchItem->postions[1] = glm::vec2(
        destinationRectangle.get_x() + destinationRectangle.get_width(),
        destinationRectangle.get_y());

    batchItem->postions[2] = glm::vec2(
        destinationRectangle.get_x(),
        destinationRectangle.get_y() + destinationRectangle.get_height());

    batchItem->postions[3] = glm::vec2(
        destinationRectangle.get_x() + destinationRectangle.get_width(),
        destinationRectangle.get_y() + destinationRectangle.get_height());

    //set color
    batchItem->color = color;

    //origin
    batchItem->origin = glm::vec2(0.f, 0.f);

    //rotation
    batchItem->rot = 0.f;

    batchItem->drawOrder = drawOrder;

    //texCoord
    if (sourceRectangle != nullptr)
    {
        batchItem->texcoords[0] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[1] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[2] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[3] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());
    }
    else
    {
        batchItem->texcoords[0] = glm::vec2(0.f, 0.f);
        batchItem->texcoords[1] = glm::vec2(1.f, 0.f);
        batchItem->texcoords[2] = glm::vec2(0.f, 1.f);
        batchItem->texcoords[3] = glm::vec2(1.f, 1.f);
    }
}

void SpriteBatch::draw(Texture * texture, Rectangle destinationRectangle, Rectangle * sourceRectangle, glm::vec4 color, float rotation, glm::vec2 origin, FlipEffect flip, float drawOrder)
{
    auto batchItem = createNewItem();
    if (batchItem == nullptr)
        return;

    batchItem->texture = texture;

    if (sourceRectangle != nullptr)
    {
        batchItem->texcoords[0] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[1] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[2] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[3] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());

        if (sourceRectangle->get_width() != 0)
            origin.x = origin.x * (float)destinationRectangle.get_width() / (float)sourceRectangle->get_width();
        else
            origin.x = origin.x * (float)destinationRectangle.get_width() * texture->get_bitmap()->get_texelWidth();

        if (sourceRectangle->get_height() != 0)
            origin.y = origin.y * (float)destinationRectangle.get_height() / (float)sourceRectangle->get_height();
        else
            origin.y = origin.y * (float)destinationRectangle.get_height() * texture->get_bitmap()->get_texelHeight();
    }
    else
    {
        batchItem->texcoords[0] = glm::vec2(0.f, 0.f);
        batchItem->texcoords[1] = glm::vec2(1.f, 0.f);
        batchItem->texcoords[2] = glm::vec2(0.f, 1.f);
        batchItem->texcoords[3] = glm::vec2(1.f, 1.f);

        origin.x = origin.x * (float)destinationRectangle.get_width() * texture->get_bitmap()->get_texelWidth();
        origin.y = origin.y * (float)destinationRectangle.get_height() * texture->get_bitmap()->get_texelHeight();
    }

    if (rotation == 0.f)
    {
        batchItem->postions[0] = glm::vec2(
            destinationRectangle.get_x() - origin.x,
            destinationRectangle.get_y() - origin.y);

        batchItem->postions[1] = glm::vec2(
            (destinationRectangle.get_x() - origin.x) + destinationRectangle.get_width(),
            (destinationRectangle.get_y() - origin.y));

        batchItem->postions[2] = glm::vec2(
            (destinationRectangle.get_x() - origin.x),
            (destinationRectangle.get_y() - origin.y) + destinationRectangle.get_height());

        batchItem->postions[3] = glm::vec2(
            (destinationRectangle.get_x() - origin.x) + destinationRectangle.get_width(),
            (destinationRectangle.get_y() - origin.y) + destinationRectangle.get_height());
    }
    else
    {
        float cosRot = glm::cos(rotation);
        float sinRot = glm::sin(rotation);

        batchItem->postions[0] = glm::vec2(
            destinationRectangle.get_x() + (-origin.x * cosRot) - (-origin.y * sinRot),
            destinationRectangle.get_y() + (-origin.x * sinRot) - (-origin.y * cosRot));

        batchItem->postions[1] = glm::vec2(
            destinationRectangle.get_x() + (-origin.x + destinationRectangle.get_width()) * cosRot - (-origin.y)* sinRot,
            destinationRectangle.get_y() + (-origin.x + destinationRectangle.get_width()) * sinRot - (-origin.y)* cosRot);

        batchItem->postions[2] = glm::vec2(
            destinationRectangle.get_x() + (-origin.x * cosRot) - (-origin.y + destinationRectangle.get_height())* sinRot,
            destinationRectangle.get_y() + (-origin.x * sinRot) - (-origin.y + destinationRectangle.get_height())* cosRot);

        batchItem->postions[3] = glm::vec2(
            destinationRectangle.get_x() + (-origin.x + destinationRectangle.get_width()) * cosRot - (-origin.y + destinationRectangle.get_height())* sinRot,
            destinationRectangle.get_y() + (-origin.x + destinationRectangle.get_width()) * sinRot - (-origin.y + destinationRectangle.get_height())* cosRot);
    }

    //set color
    batchItem->color = color;

    //origin
    batchItem->origin = glm::vec2(0.f, 0.f);

    //rotation
    batchItem->rot = 0.f;

    batchItem->drawOrder = drawOrder;

    //texCoord


    switch (flip)
    {
    case FLIP_HORIZONTAL:
    {
        auto tl_tmp1 = batchItem->texcoords[0];
        auto tr_tmp = batchItem->texcoords[1];
        batchItem->texcoords[0] = batchItem->texcoords[2];
        batchItem->texcoords[1] = batchItem->texcoords[3];
        batchItem->texcoords[2] = tl_tmp1;
        batchItem->texcoords[3] = tr_tmp;
    }
    break;
    case FLIP_VERTICAL:
    {
        auto tl_tmp2 = batchItem->texcoords[0];
        auto bl_tmp = batchItem->texcoords[2];
        batchItem->texcoords[0] = batchItem->texcoords[1];
        batchItem->texcoords[2] = batchItem->texcoords[3];
        batchItem->texcoords[1] = tl_tmp2;
        batchItem->texcoords[3] = bl_tmp;
    }
    break;
    }
}

void SpriteBatch::draw(Texture * texture, glm::vec2 position, Rectangle * sourceRectangle, glm::vec4 color, float rotation, glm::vec2 origin, glm::vec2 scale, FlipEffect flip, float drawOrder)
{
    auto batchItem = createNewItem();
    if (batchItem == nullptr)
        return;

    auto size = glm::vec2(texture->get_bitmap()->get_width(), texture->get_bitmap()->get_height()) * scale;

    batchItem->texture = texture;

    if (rotation == 0.f)
    {
        batchItem->postions[0] = glm::vec2(
            position.x - origin.x,
            position.y - origin.y);

        batchItem->postions[1] = glm::vec2(
            (position.x - origin.x) + size.x,
            position.y - origin.y);

        batchItem->postions[2] = glm::vec2(
            position.x - origin.x,
            (position.y - origin.y) + size.y);

        batchItem->postions[3] = glm::vec2(
            position.x - origin.x + size.x,
            (position.y - origin.y) + size.y);
    }
    else
    {
        float cosRot = glm::cos(rotation);
        float sinRot = glm::sin(rotation);

        batchItem->postions[0] = glm::vec2(
            position.x + (-origin.x * cosRot) - (-origin.y * sinRot),
            position.y + (-origin.x * sinRot) - (-origin.y * cosRot));

        batchItem->postions[1] = glm::vec2(
            position.x + (-origin.x + size.x) * cosRot - (-origin.y)* sinRot,
            position.y + (-origin.x + size.x) * sinRot - (-origin.y)* cosRot);

        batchItem->postions[2] = glm::vec2(
            position.x + (-origin.x * cosRot) - (-origin.y + size.y)* sinRot,
            position.y + (-origin.x * sinRot) - (-origin.y + size.y)* cosRot);

        batchItem->postions[3] = glm::vec2(
            position.x + (-origin.x + size.x) * cosRot - (-origin.y + size.y)* sinRot,
            position.y + (-origin.x + size.x) * sinRot - (-origin.y + size.y)* cosRot);
    }

    //set color
    batchItem->color = color;

    //origin
    batchItem->origin = glm::vec2(0.f, 0.f);

    //rotation
    batchItem->rot = 0.f;

    batchItem->drawOrder = drawOrder;

    //texCoord
    if (sourceRectangle != nullptr)
    {
        batchItem->texcoords[0] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[1] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            sourceRectangle->get_y() * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[2] = glm::vec2(
            sourceRectangle->get_x() * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());

        batchItem->texcoords[3] = glm::vec2(
            (sourceRectangle->get_x() + sourceRectangle->get_width()) * texture->get_bitmap()->get_texelWidth(),
            (sourceRectangle->get_y() + texture->get_bitmap()->get_height()) * texture->get_bitmap()->get_texelHeight());
    }
    else
    {
        batchItem->texcoords[0] = glm::vec2(0.f, 0.f);
        batchItem->texcoords[1] = glm::vec2(1.f, 0.f);
        batchItem->texcoords[2] = glm::vec2(0.f, 1.f);
        batchItem->texcoords[3] = glm::vec2(1.f, 1.f);
    }

    switch (flip)
    {
    case FLIP_HORIZONTAL:
    {
        auto tltmp1 = batchItem->texcoords[0];
        auto trtmp = batchItem->texcoords[1];
        batchItem->texcoords[0] = batchItem->texcoords[2];
        batchItem->texcoords[1] = batchItem->texcoords[3];
        batchItem->texcoords[2] = tltmp1;
        batchItem->texcoords[3] = trtmp;
    }
    break;
    case FLIP_VERTICAL:
    {
        auto tltmp2 = batchItem->texcoords[0];
        auto bltmp = batchItem->texcoords[2];
        batchItem->texcoords[0] = batchItem->texcoords[1];
        batchItem->texcoords[2] = batchItem->texcoords[3];
        batchItem->texcoords[1] = tltmp2;
        batchItem->texcoords[3] = bltmp;
    }
    break;
    }
}

void SpriteBatch::draw(Texture * texture, glm::vec2 position, Rectangle * sourceRectangle, glm::vec4 color, float rotation, glm::vec2 origin, float scale, FlipEffect flip, float drawOrder)
{
    auto size = glm::vec2(scale);
    this->draw(texture, position, sourceRectangle, color, rotation, origin, size, flip, drawOrder);
}

void SpriteBatch::drawBatch()
{

    switch (this->_sortMode)
    {
    case SortMode::FRONT_TO_BACK:
        std::sort(this->_items.begin(), this->_items.end(),
            [=](SpriteBatchItem* item1, SpriteBatchItem* item2) { return item1->drawOrder < item2->drawOrder; });
        break;
    case SortMode::BACK_TO_FRONT:
        std::sort(this->_items.begin(), this->_items.end(),
            [=](SpriteBatchItem* item1, SpriteBatchItem* item2) { return item1->drawOrder > item2->drawOrder; });
        break;
    }

    if (this->_viewport == glm::mat4())
    {
        GLint display[4];
        glGetIntegerv(GL_VIEWPORT, display);
        this->_viewport = glm::ortho(0.f, (float)display[2],
            (float)display[3], 0.f);
    }

    GLuint currentProgram;
    if (this->_customShader == nullptr)
    {
        this->_customShader->use();
        currentProgram = this->_customShader->get_programId();
    }
    else
    {
        this->_defaultShader->use();
        currentProgram = this->_defaultShader->get_programId();
    }

    glUniformMatrix4fv(glGetUniformLocation(currentProgram, "projection"), 1, GL_FALSE, glm::value_ptr(this->_viewport));

    glBindVertexArray(this->_vao);

    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo);

    size_t spritesCount = this->_items.size();
    size_t batchesToDraw = spritesCount / MAX_BATCH_ITEMS;

    this->_sampler->bind();
    for (size_t batchNumber = 0; batchNumber < batchesToDraw + 1; ++batchNumber)
    {
        size_t spriteNumber = spritesCount - (batchNumber * MAX_BATCH_ITEMS);
        if (spriteNumber > MAX_BATCH_ITEMS)
            spriteNumber = MAX_BATCH_ITEMS;

        for (size_t i = batchNumber * MAX_BATCH_ITEMS; i < batchNumber * MAX_BATCH_ITEMS + spriteNumber; ++i)
        {
            auto item = this->_items[i];

            size_t newI = (i - (i / MAX_BATCH_ITEMS * MAX_BATCH_ITEMS)) * 32;

            //top left
            this->_vertexBuffer[newI + 0] = item->postions[0].x;
            this->_vertexBuffer[newI + 1] = item->postions[0].y;
            this->_vertexBuffer[newI + 2] = item->texcoords[0].x;
            this->_vertexBuffer[newI + 3] = item->texcoords[0].y;
            this->_vertexBuffer[newI + 4] = item->color.x;
            this->_vertexBuffer[newI + 5] = item->color.y;
            this->_vertexBuffer[newI + 6] = item->color.z;
            this->_vertexBuffer[newI + 7] = item->color.w;
            //top right
            this->_vertexBuffer[newI + 8] = item->postions[1].x;
            this->_vertexBuffer[newI + 9] = item->postions[1].y;
            this->_vertexBuffer[newI + 10] = item->texcoords[1].x;
            this->_vertexBuffer[newI + 11] = item->texcoords[1].y;
            this->_vertexBuffer[newI + 12] = item->color.x;
            this->_vertexBuffer[newI + 13] = item->color.y;
            this->_vertexBuffer[newI + 14] = item->color.z;
            this->_vertexBuffer[newI + 15] = item->color.w;
            //top left
            this->_vertexBuffer[newI + 16] = item->postions[2].x;
            this->_vertexBuffer[newI + 17] = item->postions[2].y;
            this->_vertexBuffer[newI + 18] = item->texcoords[2].x;
            this->_vertexBuffer[newI + 19] = item->texcoords[2].y;
            this->_vertexBuffer[newI + 20] = item->color.x;
            this->_vertexBuffer[newI + 21] = item->color.y;
            this->_vertexBuffer[newI + 22] = item->color.z;
            this->_vertexBuffer[newI + 23] = item->color.w;
            //top right
            this->_vertexBuffer[newI + 24] = item->postions[3].x;
            this->_vertexBuffer[newI + 25] = item->postions[3].y;
            this->_vertexBuffer[newI + 26] = item->texcoords[3].x;
            this->_vertexBuffer[newI + 27] = item->texcoords[3].y;
            this->_vertexBuffer[newI + 28] = item->color.x;
            this->_vertexBuffer[newI + 29] = item->color.y;
            this->_vertexBuffer[newI + 30] = item->color.z;
            this->_vertexBuffer[newI + 31] = item->color.w;
        }

        size_t fullSize = spritesCount - batchNumber * MAX_BATCH_ITEMS;

        if (fullSize > MAX_BATCH_ITEMS)
            fullSize = MAX_BATCH_ITEMS;

        glBufferSubData(GL_ARRAY_BUFFER, 0, fullSize* (32 * sizeof(GLfloat)),
            &this->_vertexBuffer[0]);

        auto lastTex = this->_items[batchNumber * MAX_BATCH_ITEMS]->texture;
        int offset = 0;

        SpriteBatchItem* spriteItem;
        for (size_t i = 0; i < spriteNumber; ++i)
        {
            spriteItem = this->_items[batchNumber * MAX_BATCH_ITEMS + i];
            if (spriteItem->texture->get_textureId() != lastTex->get_textureId())
            {
                lastTex->bind();
                glDrawElements(GL_TRIANGLES, (i - offset) * 6,
                    GL_UNSIGNED_INT, (GLvoid*)(offset * 6 * sizeof(GLuint)));
                offset = i;
                lastTex = spriteItem->texture;
            }
        }

        lastTex->bind();
        glDrawElements(GL_TRIANGLES, (spriteNumber - offset) * 6,
            GL_UNSIGNED_INT, (GLvoid*)(offset * 6 * sizeof(GLuint)));
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    this->_sampler->bind();

    glBindVertexArray(0);
    glUseProgram(0);

    this->_isStarted = false;
    this->_items.clear();
}

void SpriteBatch::clearBatchItems()
{
    for (auto& item : this->_items)
    {
        delete item;
    }

    this->_items.clear();
}

SpriteBatch::SpriteBatchItem * SpriteBatch::createNewItem()
{
    if (this->_items.size() > 256)
        return nullptr;

    auto newItem = new SpriteBatchItem();

    this->_items.push_back(newItem);

    return newItem;
}

bool SpriteBatch::initializeDefaultShader()
{
    const char *vertexSource =
        "#version 330 core\n"
        "layout (location = 0) in vec4 vertexPos;\n"
        "layout (location = 1) in vec4 vertexColor;\n"
        "out vec2 fragmentTexCoord;\n"
        "out vec4 fragmentColor;\n"
        "uniform mat4 projection;\n"
        "void main(void)\n"
        "{\n"
        "gl_Position = projection * vec4(vertexPos.x, vertexPos.y, 0.0f, 1.0f);\n"
        "fragmentTexCoord = vec2(vertexPos.w, vertexPos.z);\n"
        "fragmentColor = vertexColor;\n"
        "}\n";

    const char *fragmentSource =
        "#version 330 core\n"
        "layout (location = 0) out vec4 color;\n"
        "in vec2 fragmentTexCoord;\n"
        "in vec4 fragmentColor;\n"
        "uniform sampler2D tex;\n"
        "uniform float global_alpha;\n"
        "void main(void)\n"
        "{\n"
        "color = vec4(fragmentColor.x, fragmentColor.y, fragmentColor.z, global_alpha * fragmentColor.w) * texture(tex, fragmentTexCoord);\n"
        "}";

    this->_defaultShader = new ShaderProgram(vertexSource, fragmentSource);
    ProgramCompilationResult result = this->_defaultShader->compile();
    if (result == ShaderCompileResult::COMPILATION_ERROR)
    {
        //TODO: log error
        return false;
    }

    return true;
}

bool SpriteBatch::isRenderTargetSet()
{
    if (_currentTarget == nullptr)
        return false;

    return true;
}

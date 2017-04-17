#include "SpriteBatch.h"
#include "../ContentManagement/DefaultAssets/ShaderProgram.h"


SpriteBatch::SpriteBatch()
{
}


SpriteBatch::~SpriteBatch()
{
}

void SpriteBatch::initializeDefaultShader()
{
    const char *vertexSource =
        "#version 330 core\n"
        "layout (location = 0) in vec4 position;\n"
        "layout (location = 1) in vec4 in_tint;\n"
        "out vec2 tex_pos;\n"
        "out vec4 tint;\n"
        "uniform mat4 projection;\n"
        "void main(void)\n"
        "{\n"
        "gl_Position = projection * vec4(position.x, position.y, 0.0f, 1.0f);\n"
        "tex_pos = vec2(position.z, position.w);\n"
        "tint = in_tint;\n"
        "}\n";

    const char *fragmentSource=
        "#version 330 core\n"
        "in vec2 tex_pos;\n"
        "in vec4 tint;\n"
        "out vec4 color;\n"
        "uniform sampler2D tex;\n"
        "uniform float global_alpha;\n"
        "void main(void)\n"
        "{\n"
        "color = vec4(tint.x, tint.y, tint.z, global_alpha * tint.w) * texture(tex, tex_pos);\n"
        "}";

    this->_defaultShader = new ShaderProgram(vertexSource, fragmentSource);
    this->_defaultShader->compile();
}

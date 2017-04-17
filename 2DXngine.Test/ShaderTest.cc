#include "gtest\gtest.h"
#include <ContentManagement\DefaultAssets\ShaderProgram.h>
#include <SDL.h>

class ShaderTestFixture : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        auto _window = SDL_CreateWindow("Game Window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            640,
            360,
            SDL_WINDOW_OPENGL);

        auto ctx = SDL_GL_CreateContext(_window);

        GLenum glewError = glewInit();
    }

    virtual void TearDown()
    {
        SDL_Quit();
    }
};


TEST_F(ShaderTestFixture, shader_can_be_load_from_inline_source)
{
    //ARRANGE
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

    const char *fragmentSource =
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

    auto shader = new ShaderProgram(vertexSource, fragmentSource);

    //ACT
    auto result = shader->compile();

    //ASSERT
    ASSERT_EQ(ShaderCompileResult::COMPILATION_SUCESS, result);
}
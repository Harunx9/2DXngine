#include "gtest\gtest.h"
#include <ContentManagement\DefaultAssets\Shader.h>
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

    const char *fragmentErrorSource =
        "#version 330 core\n"
        "in vec2 tex_pos;\n"
        "in vec4 tint;\n"
        "out vec4 color;\n"
        "uniform sampler2D tex;\n"
        "uniform float global_alpha;\n"
        "void main(void)\n"
        "{\n"
        "color = vec4(tint.x, tint.y, tint.z, global_alpha * tint.w) * texture(t, tex_pos)\n"
        "}";
};

TEST_F(ShaderTestFixture, when_shader_program_is_valid_should_compile_with_sucess)
{
    //Arrange
    auto shader = new Shader(std::string(fragmentSource), ShaderType::FRAGMENT_SHADER);

    //Act
    auto result = shader->compile();

    //Assert
    ASSERT_EQ(ShaderCompileResult::COMPILATION_SUCESS, result);
}

TEST_F(ShaderTestFixture, when_shader_program_is_not_valid_should_compile_with_error)
{
    //Arrange
    auto shader = new Shader(std::string(fragmentErrorSource), ShaderType::FRAGMENT_SHADER);

    //Act
    auto result = shader->compile();

    //Assert
    ASSERT_EQ(ShaderCompileResult::COMPILATION_ERROR, result);
}

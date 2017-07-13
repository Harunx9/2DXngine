#include "gtest\gtest.h"
#include <SDL.h>
#include <Graphics\RenderTarget.h>

class RenderTargetTestFixture : public ::testing::Test
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

TEST_F(RenderTargetTestFixture, render_target_will_setup_corretct)
{
    auto  rt = new RenderTarget(640, 360);

    ASSERT_TRUE(rt->get_textureId() != 0);
    ASSERT_TRUE(rt->get_fbo() != 0);
}

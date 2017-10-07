#include "gtest\gtest.h"
#include <SDL.h>
#include <ContentManagement\DefaultAssets\Texture.h>

class TextureTestFixture : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

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

TEST_F(TextureTestFixture, texutre_can_be_load_from_file)
{
    auto tex = Texture::load(AssetPath::create("Content\\dot.png"));

    ASSERT_EQ(AssetPath::create("Content\\dot.png").get_fullPath(), tex->get_path().get_fullPath());
    ASSERT_TRUE(tex->get_bitmap()->get_data() != nullptr);
    ASSERT_TRUE(tex->get_textureId() != 0);
}
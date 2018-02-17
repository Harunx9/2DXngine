#include "gtest/gtest.h"
#include <SDL.h>
#include <GL/glew.h>
#include <Services/ServiceLocator.h>
#include <ContentManagement/ContentManagerService.h>
#include <ContentManagement/DefaultAssets/Bitmap.h>
#include <ContentManagement/DefaultAssets/Texture.h>
#include <ContentManagement/DefaultAssets/TTFont.h>

class ContentManagerTestFixture : public ::testing::Test
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

        ServiceLocator::registerService(new ContentManagerService());
    }

    virtual void TearDown()
    {
        SDL_Quit();
    }
};

TEST_F(ContentManagerTestFixture, texture_should_be_loaded_corectly_if_file_exist)
{
    auto srv = ServiceLocator::get<ContentManagerService>("ContentManagerService");

    auto tex = srv->load<Texture>(AssetPath::create("Content/dot.png"));
    
    ASSERT_TRUE(tex != nullptr);
    ASSERT_GT((int)tex->get_bitmap()->get_height(), 0);
    ASSERT_GT((int)tex->get_bitmap()->get_width(), 0);
    ASSERT_TRUE(tex->get_textureId() != 0);
}

//TEST_F(ContentManagerTestFixture, font_should_be_loaded_corectly_if_file_exist)
//{
//    auto srv = ServiceLocator::get<ContentManagerService>("ContentManagerService");
//
//    auto fnt = srv->load<TTFont>(AssetPath::create("Content/babyblocks.ttf"));
//    
//    ASSERT_TRUE(fnt != nullptr);
//}


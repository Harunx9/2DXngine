#include "TestGameHandler.h"
#include <ContentManagement\DefaultAssets\Texture.h>

TestGameHandler::TestGameHandler()
{
}


TestGameHandler::~TestGameHandler()
{
}

void TestGameHandler::initialize()
{
    batch = new SpriteBatch();
    batch->initialize();
    texture = Texture::load(AssetPath::create("Content\\dot.png"));
}

void TestGameHandler::update(float deltaTime)
{

}

void TestGameHandler::draw(float deltaTime)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    batch->begin(TextureWrap::REPEAT, TextureFilter::POINT);
    batch->draw(texture, glm::vec2(0.f, 0.f), glm::vec4(1.f, 1.f, 1.f, 1.f), 1);
    batch->draw(texture, glm::vec2(100.f, 100.f), glm::vec4(1.f, 1.f, 1.f, 1.f), 1);
    batch->draw(texture, glm::vec2(100.f, 300.f), glm::vec4(1.f, 1.f, 1.f, 1.f), 1);
    batch->draw(texture, glm::vec2(200.f, 300.f), glm::vec4(1.f, 1.f, 1.f, 1.f), 1);
    batch->draw(texture, glm::vec2(300.f, 300.f), glm::vec4(1.f, 1.f, 1.f, 1.f), 1);
    batch->draw(texture, glm::vec2(200.f, 200.f), nullptr, glm::vec4(1.f, 1.f, 1.f, 1.f), 0, glm::vec2(0.f, 0.f), 2, FlipEffect::NONE_FLIP, 2);

    batch->draw(texture, glm::vec2(300.f, 200.f), nullptr, glm::vec4(1.f, 1.f, 1.f, 1.f), 0, glm::vec2(0.f, 0.f), 3, FlipEffect::NONE_FLIP, 2);
    batch->end();
    SDL_GL_SwapWindow(this->_window);
}

void TestGameHandler::handleInput()
{
}

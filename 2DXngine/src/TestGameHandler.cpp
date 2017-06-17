#include "TestGameHandler.h"
#include <ContentManagement\DefaultAssets\Texture.h>
#include <Graphics\Color.h>
#include <Services\ServiceLocator.h>

TestGameHandler::TestGameHandler()
{
}


TestGameHandler::~TestGameHandler()
{
}

void TestGameHandler::initialize()
{
    batch = new SpriteBatch(this->_device);
    batch->initialize();
    texture = Texture::load(AssetPath::create("Content\\dot.png"));
    _mp3 = Mp3Sound::load(AssetPath::create("Content\\CorporationHeadquarters.mp3"));
    _wav = WavSound::load(AssetPath::create("Content\\107589__qat__unsheath-sword.wav"));
    sound = ServiceLocator::get<SoundService>("SoundService");
    music = ServiceLocator::get<MusicService>("MusicService");
    auto vp = this->_device->get_viewport();
    cam = new Camera(vp.width, vp.height);
    cam->set_position(glm::vec2(-200.f, -200.f));
    //cam->set_rotation(-1.f);
    this->_camRot = 0;
}

void TestGameHandler::update(float deltaTime)
{
    _camRot += 0.4 * deltaTime;
    cam->set_rotation(_camRot);
    if (_wav->get_soundState() == SoundState::STOPPED)
        sound->play(_wav);

   /* if (this->_mp3->get_musicState() == SoundState::STOPPED)
        music->play(_mp3);*/
}

void TestGameHandler::draw(float deltaTime)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    batch->begin(nullptr, TextureWrap::REPEAT, TextureFilter::POINT_FILTER, cam->get_viewMatrix());
    //batch->begin(TextureWrap::REPEAT, TextureFilter::POINT_FILTER);
    batch->draw(texture, glm::vec2(0.f, 0.f), Colors::white, 1);
    batch->draw(texture, glm::vec2(100.f, 100.f), Colors::white, 1);
    batch->draw(texture, glm::vec2(100.f, 300.f), Colors::white, 1);
    batch->draw(texture, glm::vec2(200.f, 300.f), Colors::white, 1);
    batch->draw(texture, glm::vec2(300.f, 300.f), Colors::white, 1);
    batch->draw(texture, glm::vec2(200.f, 200.f), nullptr, Colors::white, 0, glm::vec2(0.f, 0.f), 2, FlipEffect::NONE_FLIP, 2);

    batch->draw(texture, glm::vec2(300.f, 200.f), nullptr, Colors::white, 0, glm::vec2(0.f, 0.f), 3, FlipEffect::NONE_FLIP, 2);
    batch->end();
    this->_device->swapBuffers();
}

void TestGameHandler::handleInput()
{

}

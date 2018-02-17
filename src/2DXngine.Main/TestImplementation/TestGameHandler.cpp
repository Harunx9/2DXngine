#include "TestGameHandler.h"
#include <ContentManagement/DefaultAssets/Texture.h>
#include <Graphics/Color.h>
#include <Services/ServiceLocator.h>

TestGameHandler::TestGameHandler()
{
}


TestGameHandler::~TestGameHandler()
{
}

void TestGameHandler::initialize()
{
    this->_device->enable_Blend(BlendFunc::SRC_ALPHA, BlendFunc::ONE_MINUS_SRC_ALPHA);
    //this->_device->enable_CullFace();
    batch = new SpriteBatch(this->_device);
    batch->initialize();
    texture = Texture::load(AssetPath::create("Content\\dot.png"));
    _mp3 = Mp3Sound::load(AssetPath::create("Content\\CorporationHeadquarters.mp3"));
    _wav = WavSound::load(AssetPath::create("Content\\107589__qat__unsheath-sword.wav"));
    font = TTFont::load(AssetPath::create("Content\\babyblocks.ttf"));
    sound = ServiceLocator::get<SoundService>("SoundService");
    music = ServiceLocator::get<MusicService>("MusicService");
    auto vp = this->_device->get_viewport();
    cam = new Camera(vp.width, vp.height);
    cam->set_position(glm::vec2(-200.f, -200.f));
    //cam->set_rotation(-1.f);
    //this->_camRot = 0;
}

void TestGameHandler::update(float deltaTime)
{
    //_camRot += 0.4 * deltaTime;
    /*cam->set_rotation(_camRot);
    if (_wav->get_soundState() == SoundState::STOPPED)
        sound->play(_wav);*/

   /* if (this->_mp3->get_musicState() == SoundState::STOPPED)
        music->play(_mp3);*/
}

void TestGameHandler::draw(float deltaTime)
{
    this->_device->clear(Colors::black);
    font->draw(this->batch, "Hello world 2DXngine !!!", glm::vec2(100.f, 100.f), Colors::blue, cam->get_viewMatrix());
    

    this->_device->swapBuffers();
}

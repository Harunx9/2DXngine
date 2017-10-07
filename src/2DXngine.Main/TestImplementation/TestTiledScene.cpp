#include "TestTiledScene.h"
#include <Graphics\Renderer.h>
#include <Graphics\GraphicDevice.h>
#include <Graphics\Camera.h>



TestTiledScene::TestTiledScene(SpriteBatch* batch, SceneLoader* loader)
    :LoadableScene(batch, loader)
{
}


TestTiledScene::~TestTiledScene()
{
}

void TestTiledScene::setup()
{
    Viewport vp = this->get_renderer()->get_graphics()->get_viewport();
    this->_camera = new Camera(vp.width, vp.height, Colors::white);
    this->_camera->set_position(glm::vec2(0.f, 0.f));
    this->_camera->set_zoom(5.f);
}

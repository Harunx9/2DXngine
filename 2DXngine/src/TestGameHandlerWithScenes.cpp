#include "TestGameHandlerWithScenes.h"
#include <Scenes\SceneManagerService.h>
#include "SceneTest.h"

TestGameHandlerWithScenes::TestGameHandlerWithScenes()
{
}


TestGameHandlerWithScenes::~TestGameHandlerWithScenes()
{
}

void TestGameHandlerWithScenes::initialize()
{
    Game2DWithScenesHandler::initialize();
    this->_device->enable_Blend(BlendFunc::SRC_ALPHA, BlendFunc::ONE_MINUS_SRC_ALPHA);
    this->_sceneManager->startWith(new SceneTest(this->_batch));
}


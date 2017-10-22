#include "TestGameHandlerWithScenes.h"
#include <Scenes\SceneManagerService.h>
#include <Integrations\Tiled\GameObjectFactories.h>
#include <Integrations\Tiled\TiledMapLoader.h>
#include <Integrations\Tiled\Factories\TileLayersFactory.h>
#include <Integrations\Tiled\Factories\TilesetsFactory.h>
#include "SceneTest.h"
#include "TestTiledScene.h"

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
    
    //auto factories = new GameObjectFactories();
    //factories->registerFactory(new TilesetsFactory());
    //factories->registerFactory(new TileLayersFactory());
    //auto loader = new TiledMapLoader(AssetPath::create("Content\\RenderTestMap.tmx"), factories);
    //this->_sceneManager->startWith(new TestTiledScene(this->_batch, loader));
    this->_sceneManager->startWith(new SceneTest(this->_batch));
}


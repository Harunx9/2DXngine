#include "SceneTest.h"
#include <ComponentModel\GameObject.h>
#include <Components\Graphics\Transform.h>
#include <Components\Graphics\SpriteDrawableComponent.h>
#include <Components\Graphics\SpriteComponent.h>
#include <ComponentModel\GameObjectManager.h>
#include <Graphics\Camera.h>
#include "DotTestController.h"
#include "TestMouseCoordsComponent.h"
#include <Components\Graphics\FontDrawableComponent.h>
#include <Components\Data\FontComponent.h>
#include <Components\Data\TextComponent.h>
#include <Components\Graphics\SpritesheetFactory\XMLSpritesheetParserFactory.h>
#include <Components\Graphics\SpriteSheetComponent.h>
#include <Components\Graphics\ParticleSystemDrawable.h>
#include <Components\Behaviors\ParticleSystemBehavior.h>
#include <Components\Behaviors\ParticleSystem\ParticleGenerators.h>
#include <Components\Behaviors\ParticleSystem\ParticleUpdaters.h>

SceneTest::SceneTest(SpriteBatch* batch) : Scene(batch, "SceneTest")
{
}


SceneTest::~SceneTest()
{
}

void SceneTest::createScene()
{
    Viewport vp = this->get_renderer()->get_graphics()->get_viewport();
    this->_camera = new Camera(vp.width, vp.height, Colors::black);
    this->_camera->set_position(glm::vec2(0.f, 0.f));

    GameObject* go6 = new GameObject("ParticleTest");
    auto  sheet = XMLSpritesheetParserFactory::create(AssetPath::create("Content/sparks.xml"));
    Transform* t6 = new Transform();
    t6->set_position(glm::vec2(0.f, 0.f));
    t6->set_width(vp.width);
    t6->set_height(vp.height);

    auto emiter = new ParticleEmiter(std::vector<ParticleGenerator*>
    {
        new AreaParticleGenerator(),
            new AllFrameRectsGenerator(),
            new AliveTimeGenerator(1.f, 3.f)

    }, 200.f);

    auto updater = new ParticleSystemBehavior(emiter, 
        std::vector<ParticleUpdater*>{
        new ConstAccelerationUpdater({ 0, 200.f }),
            new TimeUpdater(),
    }, 300);

    go6->addComponent(t6)
        ->addComponent(new SpriteComponent("Content/sparks.png"))
        ->addComponent(sheet)
        ->addComponent(updater)
        ->addComponent(new ParticleSystemDrawableComponent(DefaultLayers::GAMEPLAY_LAYER, TextureFilter::POINT_FILTER, TextureWrap::CLAMP_TO_EDGE));


    this->get_gameObjectManager()->addGameObject(go6);
}


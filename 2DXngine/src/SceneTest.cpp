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
#include <Components\Graphics\AnimationFactory\XMLSpritesheetAnimationFactory.h>
#include <Components\Graphics\AnimationDrawableComponent.h>

SceneTest::SceneTest(SpriteBatch* batch) : Scene(batch, "SceneTest")
{
}


SceneTest::~SceneTest()
{
}

void SceneTest::createScene()
{
    Viewport vp = this->get_renderer()->get_graphics()->get_viewport();
    this->_camera = new Camera(vp.width, vp.height, Colors::white);
    this->_camera->set_position(glm::vec2(0.f, 0.f));
    GameObject* go = new GameObject("Dot1");
    Transform* t1 = new Transform();
    t1->set_position(glm::vec2(100.f, 100.f));
    t1->set_origin(glm::vec2(0.5f));
    go->addComponent(t1);
    go->addComponent(new SpriteComponent("Content/dot.png"))
        ->addComponent(new SpriteDrawableComponent())
        ->addComponent(new DotTestController());

    this->get_gameObjectManager()->addGameObject(go);

    GameObject* go2 = new GameObject("Dot2");
    Transform* t2 = new Transform();
    t2->set_position(glm::vec2(300.f, 300.f));
    t2->set_origin(glm::vec2(0.5f));
    t2->set_scale(2.f);
    go2->addComponent(t2);
    go2->addComponent(new SpriteComponent("Content/dot.png"))
        ->addComponent(new SpriteDrawableComponent())
        ->addComponent(new DotTestController());

    this->get_gameObjectManager()->addGameObject(go2);

    GameObject* go3 = new GameObject("Dot3");
    Transform* t3 = new Transform();
    t3->set_position(glm::vec2(600.f, 600.f));
    t3->set_origin(glm::vec2(0.5f));
    t3->set_scale(3.f);
    go3->addComponent(t3);
    go3->addComponent(new SpriteComponent("Content/dot.png"))
        ->addComponent(new SpriteDrawableComponent())
        ->addComponent(new DotTestController());

    this->get_gameObjectManager()->addGameObject(go3);

    GameObject* go4 = new GameObject("MouseRecalc");
    go4->addComponent(new TestMouseCoordsComponent(this->_camera));
    this->get_gameObjectManager()->addGameObject(go4);

    GameObject* go5 = new GameObject("TextObject");
    Transform* t5 = new Transform();
    t5->set_position(glm::vec2(400.f, 400.f));
    go5->addComponent(new TextComponent("Test text"))
        ->addComponent(new FontComponent(AssetPath::create("Content\\babyblocks.ttf"), Colors::red))
        ->addComponent(t5)
        ->addComponent(new FontDrawableComponent());

    this->get_gameObjectManager()->addGameObject(go5);

    GameObject* go6 = new GameObject("AnimationTest");
    auto  animation = XMLSpritesheetAnimationFactory::createFromXmlWithAllNames(AssetPath::create("Content/TestAnim.xml"));
    Transform* t6 = new Transform();
    t6->set_position(glm::vec2(600.f, 100.f));
    t6->set_origin(glm::vec2(0.5f));
    t6->set_scale(4.f);
    go6->addComponent(t6)
        ->addComponent(new SpriteComponent("Content/TestAnim.png"))
        ->addComponent(animation)
        ->addComponent(new AnimationDrawableComponent(TextureWrap::CLAMP_TO_EDGE, TextureFilter::POINT_FILTER));
    animation->play_animation("ball", true);

    this->get_gameObjectManager()->addGameObject(go6);
}


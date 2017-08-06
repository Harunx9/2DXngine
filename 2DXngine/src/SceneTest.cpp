#include "SceneTest.h"
#include <ComponentModel\GameObject.h>
#include <Components\Graphics\Transform.h>
#include <Components\Graphics\SpriteDrawableComponent.h>
#include <Components\Graphics\SpriteComponent.h>
#include <ComponentModel\GameObjectManager.h>
#include <Graphics\Camera.h>
#include "DotTestController.h"
#include "TestMouseCoordsComponent.h"

SceneTest::SceneTest(SpriteBatch* batch): Scene(batch, "SceneTest")
{
}


SceneTest::~SceneTest()
{
}

void SceneTest::createScene()
{
    Viewport vp = this->get_renderer()->get_graphics()->get_viewport();
    this->_camera = new Camera(vp.width, vp.height);
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
}


#include "gtest\gtest.h"
#include <TypeInformation\BaseTypesDefinitions.h>
#include <Components\Graphics\Transform.h>
#include <Components\Interactions\ColliderComponent.h>
#include <ComponentModel\GameObject.h>

TEST(ColliderComponentTest, when_colliders_not_intersected)
{
    auto oneObj = new  GameObject("Obj1");
    auto twoObj = new  GameObject("Obj2");
    auto colliderOne = new ColliderComponent();
    auto colliderTwo = new ColliderComponent();
    
    oneObj
        ->addComponent(colliderOne)
        ->addComponent(new Transform(glm::vec2(0.f, 0.f), 50.f, 50.f));

    twoObj
        ->addComponent(colliderTwo)
        ->addComponent(new Transform(glm::vec2(100.f, 100.f), 50.f, 50.f));

    oneObj->initialize();
    twoObj->initialize();

    bool result = colliderOne->is_collide(colliderTwo);

    ASSERT_FALSE(result);
}

TEST(ColliderComponentTest, when_colliders_intersected)
{
    auto oneObj = new  GameObject("Obj1");
    auto twoObj = new  GameObject("Obj2");
    auto colliderOne = new ColliderComponent();
    auto colliderTwo = new ColliderComponent();

    oneObj
        ->addComponent(colliderOne)
        ->addComponent(new Transform(glm::vec2(0.f, 0.f), 50.f, 50.f));

    twoObj
        ->addComponent(colliderTwo)
        ->addComponent(new Transform(glm::vec2(20.f, 20.f), 50.f, 50.f));

    oneObj->initialize();
    twoObj->initialize();

    bool result = colliderOne->is_collide(colliderTwo);

    ASSERT_TRUE(result);
}

TEST(ColliderComponentTest, when_colliders_not_intersected_and_then_game_object_collides)
{
    auto oneObj = new  GameObject("Obj1");
    auto twoObj = new  GameObject("Obj2");
    auto colliderOne = new ColliderComponent();
    auto colliderTwo = new ColliderComponent();
    auto transfromOne = new Transform(glm::vec2(0.f, 0.f), 50.f, 50.f);
    auto transformTwo = new Transform(glm::vec2(100.f, 100.f), 50.f, 50.f);

    oneObj
        ->addComponent(colliderOne)
        ->addComponent(transfromOne);

    twoObj
        ->addComponent(colliderTwo)
        ->addComponent(transformTwo);

    oneObj->initialize();
    twoObj->initialize();

    bool result = colliderOne->is_collide(colliderTwo);

    ASSERT_FALSE(result);

    transformTwo->set_x(20.f);
    transformTwo->set_y(20.f);

    result = colliderOne->is_collide(colliderTwo);

    ASSERT_TRUE(result);
}
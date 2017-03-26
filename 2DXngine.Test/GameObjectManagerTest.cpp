#include <gtest\gtest.h>
#include <ComponentModel\GameObject.h>
#include <ComponentModel\GameObjectManager.h>
#include "TestComponents.h"
#include "TestScene.h"

class GameObjectMananagerTestFixture : public testing::Test
{
protected:
    virtual void SetUp()
    {
        playerController = new PlayerControllerComponentTest();
        playerDrawable = new PlayerDrawableComponentTest();
        swordController = new SwordControllerComponentTest();
        swordDrawable = new SwordDrawableComponentTest();

        player = new GameObject("Player");
        player
            ->addComponent(playerController)
            ->addComponent(playerDrawable);

        sword = new GameObject("Sword");
        sword
            ->addComponent(swordController)
            ->addComponent(swordDrawable);
    }

    virtual void TearDown()
    {

    }

    GameObject* player;
    GameObject* sword;
    PlayerControllerComponentTest* playerController;
    PlayerDrawableComponentTest* playerDrawable;
    SwordControllerComponentTest* swordController;
    SwordDrawableComponentTest* swordDrawable;
};


TEST_F(GameObjectMananagerTestFixture, GameObject_can_be_found_in_GameObjectMananager)
{
    //Arrange
    auto manager = new GameObjectManager(new TestScene());
    manager->addGameObject(player);
    manager->addGameObject(sword);
    
    //Act
    manager->initialize();

    //Assert
    ASSERT_TRUE(strcmp("Player", manager->findObject("Player")->get_name()) == 0);
    ASSERT_TRUE(strcmp("Sword", manager->findObject("Sword")->get_name()) == 0);
}

TEST_F(GameObjectMananagerTestFixture, GameObject_can_be_removed_from_GameObjectMananager)
{
    //Arrange
    auto manager = new GameObjectManager(new TestScene());
    manager->addGameObject(player);
    manager->addGameObject(sword);
    manager->initialize();

    //Act
    manager->removeGameObject("Sword");

    //Assert
    ASSERT_TRUE(strcmp("Player", manager->findObject("Player")->get_name()) == 0);
    ASSERT_EQ(nullptr, manager->findObject("Sword"));
}
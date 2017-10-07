#include <gtest\gtest.h>
#include <ComponentModel\GameObject.h>
#include <ComponentModel\GameObjectManager.h>
#include "../TypeSystem/TestComponents.h"
#include "../Scenes/TestScene.h"
#include <Services\ServiceLocator.h>
#include <Scenes\SceneManagerService.h>

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
        ServiceLocator::registerService(new SceneManagerService());
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
    ASSERT_EQ("Player", manager->findObject("Player")->get_name());
    ASSERT_EQ("Sword", manager->findObject("Sword")->get_name());
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
    ASSERT_EQ("Player", manager->findObject("Player")->get_name());
    ASSERT_EQ(nullptr, manager->findObject("Sword"));
}
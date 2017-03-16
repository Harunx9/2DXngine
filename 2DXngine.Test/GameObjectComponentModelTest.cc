#include <gtest\gtest.h>
#include "TestTypes.h"


TEST(GameObject, ComponentCanBeAddedToGameObject)
{
    //Arrange
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");
    
    //Act
    go->addComponent(component);
    
    //Assert
    ASSERT_EQ(false, go->get_isEmpty());
}

TEST(GameObject, ComponentCanBeFoundInGameObjectOFExactType)
{
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");
    auto component2 = new TestComponent2("Test2");
    go->addComponent(component)
        ->addComponent(component2);
    
    auto cmp = go->findFirstComponentOfType<TestComponent2>();

    ASSERT_EQ("Test2", cmp->get_Name());
}

TEST(GameObject, ComponentCanBeFoundInGameObjectOfBaseType)
{
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");
    auto component2 = new TestComponent2("Test2");
    go->addComponent(component)
        ->addComponent(component2);

    auto cmp = go->findFirstComponentOfType<Component>(false);

    ASSERT_EQ("Test", cmp->get_Name());
}


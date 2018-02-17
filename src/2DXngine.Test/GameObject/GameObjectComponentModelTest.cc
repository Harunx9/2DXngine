#include <gtest/gtest.h>
#include <TypeInformation/BaseTypesDefinitions.h>
#include "../TypeSystem/TestTypes.h"
#include <ComponentModel/GameObjectFilterFunctions.h>

TEST(GameObject, Component_can_be_added_to_GameObject)
{
    //Arrange
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");

    //Act
    go->addComponent(component);

    //Assert
    ASSERT_EQ(false, go->get_isEmpty());
}

TEST(GameObject, Component_can_be_found_in_GameObject_of_exact_type)
{
    //Arrange
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");
    auto component2 = new TestComponent2("Test2");
    go->addComponent(component)
        ->addComponent(component2);

    //Act
    auto cmp = go->findFirstComponentOfType<TestComponent2>();

    //Assert
    ASSERT_EQ("Test2", cmp->get_name());
}

TEST(GameObject, Component_can_be_found_in_GameObject_of_base_type)
{
    //Arrange
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");
    auto component2 = new TestComponent2("Test2");
    go->addComponent(component)
        ->addComponent(component2);

    //Act
    auto cmp = go->findFirstComponentOfType<Component>(false);

    //Assert
    ASSERT_EQ("Test", cmp->get_name());
}

TEST(GameObject, all_Components_of_certin_type_can_be_found_in_GameObject)
{
    //Arrange
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");
    auto component2 = new TestComponent2("Test2");
    go->addComponent(component)
        ->addComponent(component2);

    //Act
    auto cmp = go->findAllComponentsOfType<Component>(false);

    //Assert
    ASSERT_EQ(2, cmp.size());
    ASSERT_EQ("Test", cmp[0]->get_name());
    ASSERT_EQ("Test2", cmp[1]->get_name());
}

TEST(GameObject, all_Components_of_certin_type_can_be_found_in_GameObject_when_GameObject_has_mixed_Components)
{
    //Arrange
    auto go = new GameObject("Player");
    auto component = new TestComponent("Test");
    auto component2 = new TestComponent2("Test2");
    auto component3 = new TestDrawableComponent1("TestDrawable1");
    auto component4 = new TestDrawableComponent2("TestDrawable2");
    go->addComponent(component)
        ->addComponent(component2)
        ->addComponent(component3)
        ->addComponent(component4);

    //Act
    auto cmp = go->findAllComponentsOfType<DrawableComponent>(false);

    //Assert
    ASSERT_EQ(2, cmp.size());
    ASSERT_EQ("TestDrawable1", cmp[0]->get_name());
    ASSERT_EQ("TestDrawable2", cmp[1]->get_name());
}

TEST(GameObject, all_components_can_be_found_by_getAllComponentFromGameObjectAndChildren_filter_function)
{
    //Arrange
    auto go = new GameObject("Player");
    auto goChild = new GameObject("Sword");

    auto component = new TestComponent("Test");
    auto component2 = new TestComponent2("Test2");
    auto component3 = new TestDrawableComponent1("TestDrawable1");
    auto component4 = new TestDrawableComponent2("TestDrawable2");

    go->addComponent(component)
        ->addComponent(component3);

    goChild
        ->addComponent(component2)
        ->addComponent(component4);
    go->addChild(goChild);

    //Act
    auto cmp = getAllComponentFromGameObjectAndChildren<DrawableComponent>(go, false);

    //Assert
    ASSERT_EQ(2, cmp.size());
    ASSERT_EQ("TestDrawable2", cmp[0]->get_name());
    ASSERT_EQ("TestDrawable1", cmp[1]->get_name());
}
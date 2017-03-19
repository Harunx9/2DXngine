#pragma once
#include <gtest\gtest.h>
#include <ComponentModel\GameObject.h>
#include "TestTypes.h"

TEST(GameObject, when_GameObject_is_created_is_not_initialized_and_component_is_not_resolved)
{
    //Arrange
    auto go_test = new GameObject("TestPlayer");
    auto component = new TestComponent("Test");
    auto go_sword = new GameObject("SwordTest");
    //Act
    go_test->addComponent(component)
        ->addChild(go_sword);
    //Assert
    ASSERT_FALSE(go_test->get_isInitialized());
    ASSERT_FALSE(go_sword->get_isInitialized());
    ASSERT_FALSE(component->get_isInitialized());
    ASSERT_FALSE(component->get_isDependenciesResovled());
}

TEST(GameObject, when_GameObject_is_created_and_initialized_components_and_childen_is_initialized_and_dependencies_resolved)
{
    //Arrange
    auto go_test = new GameObject("TestPlayer");
    auto component = new TestComponent("Test");
    auto go_sword = new GameObject("SwordTest");
    go_test->addComponent(component)
        ->addChild(go_sword);
    //Act
    go_test->initialize();
    //Assert
    ASSERT_TRUE(go_test->get_isInitialized());
    ASSERT_TRUE(go_sword->get_isInitialized());
    ASSERT_TRUE(component->get_isInitialized());
    ASSERT_TRUE(component->get_isDependenciesResovled());
}
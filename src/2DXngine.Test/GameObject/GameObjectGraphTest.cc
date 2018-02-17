#pragma once
#include "gtest/gtest.h"
#include <ComponentModel/GameObject.h>

TEST(GameObject, GameObject_can_be_added_to_other_GameObject_as_child)
{
    //Arrange
    auto go_parent = new GameObject("PlayerTest");
    auto go_child = new GameObject("SwordTest");
    
    //Act
    go_parent->addChild(go_child);
    
    //Assert
    ASSERT_TRUE(go_parent->findChild("SwordTest") != nullptr);
    ASSERT_EQ(go_child->get_name(), go_parent->findChild("SwordTest")
        ->get_name());

    ASSERT_TRUE(go_child->get_parent() != nullptr);
    ASSERT_EQ(go_parent->get_name(), go_parent->findChild("SwordTest")
        ->get_parent()
        ->get_name());
}

TEST(GameObject, child_object_can_be_found_in_parent_GameObject)
{
    //Arrange
    auto go_parent = new GameObject("PlayerTest");
    auto go_child = new GameObject("SwordTest");
    go_parent->addChild(go_child);
    
    //Act
    auto child_found = go_parent->findChild("SwordTest");
    
    //Assert
    ASSERT_TRUE(child_found != nullptr);
    ASSERT_EQ(go_child->get_name(), child_found->get_name());
}

TEST(GameObject, child_object_can_be_removed_from_parent_GameObject)
{
    //Arrange
    auto go_parent = new GameObject("PlayerTest");
    auto go_child = new GameObject("SwordTest");
    go_parent->addChild(go_child);
    
    //Act
    go_parent->removeChild("SwordTest");
    
    //Assert
    ASSERT_TRUE(go_parent->findChild("SwordTest") == nullptr);
}

TEST(GameObject, child_object_can_be_removed_from_parent_GameObject_when_partn_have_more_children)
{
    //Arrange
    auto go_parent = new GameObject("PlayerTest");
    auto go_sword = new GameObject("SwordTest");
    auto go_bow = new GameObject("BowTest");
    go_parent->addChild(go_sword);
    go_parent->addChild(go_bow);
    //Act
    go_parent->removeChild("SwordTest");
    //Assert
    ASSERT_TRUE(go_parent->findChild("SwordTest") == nullptr);
    ASSERT_TRUE(go_parent->findChild("BowTest") != nullptr);
}
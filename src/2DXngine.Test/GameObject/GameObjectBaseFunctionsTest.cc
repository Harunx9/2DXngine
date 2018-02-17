#pragma once
#include "gtest/gtest.h"
#include <ComponentModel/GameObject.h>

TEST(GameObject, afer_creation_GameObject_is_not_initialized_vislible_and_active)
{
    auto go = new GameObject("Player");
    ASSERT_EQ(true, go->get_isActive());
    ASSERT_EQ(true, go->get_isVisible());
    ASSERT_EQ(false, go->get_isPersistant());
}

TEST(GameObject, GameObject_can_be_deactivated)
{
    auto go = new GameObject("Player");
    go->deactivate();
    ASSERT_EQ(false, go->get_isActive());
}

TEST(GameObject, GameObject_can_be_activated)
{
    auto go = new GameObject("Player");
    go->deactivate();
    ASSERT_EQ(false, go->get_isActive());
    go->activate();
    ASSERT_EQ(true, go->get_isActive());
    
}

TEST(GameObject, GameObjec_can_be_hide)
{
    auto go = new GameObject("Player");
    go->hide();
    ASSERT_EQ(false, go->get_isVisible());
}

TEST(GameObject, GameObjec_can_be_shown)
{
    auto go = new GameObject("Player");
    go->hide();
    ASSERT_EQ(false, go->get_isVisible());
    go->show();
    ASSERT_EQ(true, go->get_isVisible());
}
#pragma once
#include <ComponentModel\GameObject.h>
#include "gtest\gtest.h"

TEST(GameObject, AferCreationGameObjectIsNotInitializedVislibleAndActive)
{
    auto go = new GameObject("Player");
    ASSERT_EQ(true, go->get_isActive());
    ASSERT_EQ(true, go->get_isVisible());
    ASSERT_EQ(false, go->get_isPersistant());
}

TEST(GameObject, GameObjectCanBeDeactivated)
{
    auto go = new GameObject("Player");
    go->deactivate();
    ASSERT_EQ(false, go->get_isActive());
}

TEST(GameObject, GameObjectCanBeActivated)
{
    auto go = new GameObject("Player");
    go->deactivate();
    ASSERT_EQ(false, go->get_isActive());
    go->activate();
    ASSERT_EQ(true, go->get_isActive());
    
}

TEST(GameObject, GameObjecCanBeHide)
{
    auto go = new GameObject("Player");
    go->hide();
    ASSERT_EQ(false, go->get_isVisible());
}

TEST(GameObject, GameObjecCanBeShown)
{
    auto go = new GameObject("Player");
    go->hide();
    ASSERT_EQ(false, go->get_isVisible());
    go->show();
    ASSERT_EQ(true, go->get_isVisible());
}
#include "gtest\gtest.h"
#include <Graphics\Camera.h>

TEST(CameraUnproject, camera_can_recalculate_zero_zero_window_coords_to_world_coords)
{
    auto camera = new Camera(640, 360);
    camera->set_position(glm::vec2(-100.f, -100.f));

    auto result = camera->unproject(glm::vec2(0, 0));

    ASSERT_EQ((int)result.x, -100);
    ASSERT_EQ((int)result.y, -100);
}

TEST(CameraUnproject, camera_can_recalculate_max_x_max_y_window_coords_to_world_coords)
{
    auto camera = new Camera(640, 360);
    camera->set_position(glm::vec2(-100.f, -100.f));

    auto result = camera->unproject(glm::vec2(640, 360));

    ASSERT_EQ((int)result.x, 540);
    ASSERT_EQ((int)result.y, 260);
}

TEST(CameraUnproject, camera_can_recalculate_zero_max_y_window_coords_to_world_coords)
{
    auto camera = new Camera(640, 360);
    camera->set_position(glm::vec2(-100.f, -100.f));

    auto result = camera->unproject(glm::vec2(0, 360));

    ASSERT_EQ((int)result.x, -100);
    ASSERT_EQ((int)result.y, 260);
}

TEST(CameraUnproject, camera_can_recalculate_max_x_zero_window_coords_to_world_coords)
{
    auto camera = new Camera(640, 360);
    camera->set_position(glm::vec2(-100.f, -100.f));

    auto result = camera->unproject(glm::vec2(640, 0));

    ASSERT_EQ((int)result.x, 540);
    ASSERT_EQ((int)result.y, -100);
}

TEST(CameraUnproject, camera_can_recalculate_half_half_window_coords_to_world_coords)
{
    auto camera = new Camera(640, 360);
    camera->set_position(glm::vec2(-100.f, -100.f));

    auto result = camera->unproject(glm::vec2(320, 180.f));

    ASSERT_EQ((int)result.x, 220);
    ASSERT_EQ((int)result.y, 79);
}
#include "gtest/gtest.h"
#include <Utils/Math/RectangleI.h>
#include <Utils/Math/RectangleF.h>

TEST(Rectangle, rectangle_dimension_is_proper_when_new_rectangle_is_created)
{
    //Arrange
    auto rect = new RectangleI(1, 2, 10, 20);

    //Act
    auto  top = rect->get_top();
    auto  bottom = rect->get_bottom();
    auto  left = rect->get_left();
    auto  right = rect->get_right();

    //Assert
    ASSERT_EQ(top, 2);
    ASSERT_EQ(bottom, 22);
    ASSERT_EQ(left, 1);
    ASSERT_EQ(right, 11);
}

TEST(Rectangle, rectnagle_can_intersect_with_other_rectangle)
{
    //Arrange
    auto rect1 = new RectangleI(1, 2, 10, 20);
    auto rect2 = new RectangleI(5, 5, 10, 20);
    //Act
    auto intersectResult = rect1->insersect(rect2);

    //Assert
    ASSERT_TRUE(intersectResult);
}

TEST(Rectangle, rectnagle_can_intersect_with_other_rectangle_when_value_init)
{
    //Arrange
    auto rect1 = RectangleI(1, 2, 10, 20);
    auto rect2 = RectangleI(5, 5, 10, 20);
    //Act
    auto intersectResult = rect1.insersect(&rect2);

    //Assert
    ASSERT_TRUE(intersectResult);
}

TEST(Rectangle, rectnagle_can_contains_point)
{
    //Arrange
    auto rect = new RectangleI(1, 2, 10, 20);
    //Act
    auto intersectResult = rect->contains(3, 4);

    //Assert
    ASSERT_TRUE(intersectResult);
}

TEST(RectangleF, rectangle_dimension_is_proper_when_new_rectangle_is_created)
{
    //Arrange
    auto rect = new RectangleF(1.5, 2.5, 8.5, 20);

    //Act
    auto  top = rect->get_top();
    auto  bottom = rect->get_bottom();
    auto  left = rect->get_left();
    auto  right = rect->get_right();

    //Assert
    ASSERT_EQ(top, 2.5f);
    ASSERT_EQ(bottom, 22.5f);
    ASSERT_EQ(left, 1.5f);
    ASSERT_EQ(right, 10.f);
}

TEST(RectangleF, rectnagle_can_intersect_with_other_rectangle)
{
    //Arrange
    auto rect1 = new RectangleF(1.5f, 2.5, 8.5, 20);
    auto rect2 = new RectangleF(5.5, 5.5, 10, 20);
    //Act
    auto intersectResult = rect1->insersect(rect2);

    //Assert
    ASSERT_TRUE(intersectResult);
}

TEST(RectangleF, rectnagle_can_intersect_with_other_rectangle_when_value_init)
{
    //Arrange
    auto rect1 = RectangleF(1.5f, 2.5, 8.5, 20);
    auto rect2 = RectangleF(5.5, 5.5, 10, 20);
    //Act
    auto intersectResult = rect1.insersect(&rect2);

    //Assert
    ASSERT_TRUE(intersectResult);
}

TEST(RectangleF, rectnagle_can_contains_point)
{
    //Arrange
    auto rect = new RectangleF(1.5f, 2.5, 8.5, 20);
    //Act
    auto intersectResult = rect->contains(4.f, 4.f);

    //Assert
    ASSERT_TRUE(intersectResult);
}
#include "gtest\gtest.h"
#include <Utils\Math\Rectangle.h>

TEST(Rectangle, rectangle_dimension_is_proper_when_new_rectangle_is_created)
{
    //Arrange
    auto rect = new Rectangle(1, 2, 10, 20);

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
    auto rect1 = new Rectangle(1, 2, 10, 20);
    auto rect2 = new Rectangle(5, 5, 10, 20);
    //Act
    auto intersectResult = rect1->insersect(rect2);

    //Assert
    ASSERT_TRUE(intersectResult);
}

TEST(Rectangle, rectnagle_can_intersect_with_other_rectangle_when_value_init)
{
    //Arrange
    auto rect1 = Rectangle(1, 2, 10, 20);
    auto rect2 = Rectangle(5, 5, 10, 20);
    //Act
    auto intersectResult = rect1.insersect(&rect2);

    //Assert
    ASSERT_TRUE(intersectResult);
}
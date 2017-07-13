#include "gtest\gtest.h"
#include "PropTestClass.h"

TEST(PropertyMacroTest, macro_generate_correct_properties_with_setters_and_getters)
{
    //Arrange
    auto testClass = new PropTestClass();

    //Act
    testClass->set_floating(2.5);
    testClass->set_number(4);
    testClass->set_logical(false);

    //Assert
    ASSERT_EQ(testClass->get_floating(), 2.5);
    ASSERT_EQ(testClass->get_number(), 4);
    ASSERT_EQ(testClass->get_logical(), false);
}
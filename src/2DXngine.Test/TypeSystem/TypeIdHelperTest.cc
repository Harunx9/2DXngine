#include <gtest/gtest.h>
#include "TestTypesHierarhy.h"

TEST(TypeSystem, base_type_has_no_base_type)
{
    //Arrange
    auto instance = new BaseType();

    //Act
    bool result = instance->getType().get_hasBaseType();

    //Assert
    ASSERT_FALSE(result);
}

TEST(TypeSystem, first_derrive_type_has_only_one_base_type)
{
    //Arrange
    auto instance = new TestType1();

    //Act
    bool result = instance->getType().get_hasBaseType();
    auto baseTypes = instance->getType().get_baseTypes();

    //Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(baseTypes.size(), 1);
}


TEST(TypeSystem, second_derrive_type_has_two_base_types)
{
    //Arrange
    auto instance = new TestType2();

    //Act
    bool result = instance->getType().get_hasBaseType();
    auto baseTypes = instance->getType().get_baseTypes();

    //Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(baseTypes.size(), 2);
}


TEST(TypeSystem, third_derrive_type_has_three_base_types)
{
    //Arrange
    auto instance = new TestType4();

    //Act
    bool result = instance->getType().get_hasBaseType();
    auto baseTypes = instance->getType().get_baseTypes();

    //Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(baseTypes.size(), 3);
}

TEST(TypeSystem, other_first_derrive_has_only_one_base_type)
{
    //Arrange
    auto instance = new TestType3();

    //Act
    bool result = instance->getType().get_hasBaseType();
    auto baseTypes = instance->getType().get_baseTypes();

    //Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(baseTypes.size(), 1);
}

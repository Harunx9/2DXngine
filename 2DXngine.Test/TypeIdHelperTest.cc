#include <gtest\gtest.h>
#include "TestTypesHierarhy.h"

TEST(TypeSystem, BaseTapyHasNoBaseTypes)
{
    //Arrange
    auto instance = new BaseType();

    //Act
    bool result = instance->getType().get_hasBaseType();

    //Assert
    ASSERT_FALSE(result);
}

TEST(TypeSystem, FirstDerriveTypeHasOnlyOneBaseType)
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


TEST(TypeSystem, SecondDerriveTypeHasTwoBaseTypes)
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


TEST(TypeSystem, ThirdDerriveTypeHasThreeBaseTypes)
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

TEST(TypeSystem, OtherFirstDerriveHasOnlyOneBaseType)
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

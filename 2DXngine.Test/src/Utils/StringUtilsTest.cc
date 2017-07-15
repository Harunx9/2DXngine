#include "gtest\gtest.h"
#include <Utils\StringUtils.h>

TEST(StringUtilsTest, string_can_be_trimmed_from_left)
{
    std::string testData = "     Test";

    std::string result = trimL(testData);

    ASSERT_EQ("Test", result);
}

TEST(StringUtilsTest, string_cant_be_trimmed_from_left_if_sign_appear)
{
    std::string testData = "a     Test";

    std::string result = trimL(testData);

    ASSERT_EQ("a     Test", result);
}

TEST(StringUtilsTest, string_can_be_trimmed_from_right)
{
    std::string testData = "Test      ";

    std::string result = trimR(testData);

    ASSERT_EQ("Test", result);
}

TEST(StringUtilsTest, string_cant_be_trimmed_from_right_if_sign_appear)
{
    std::string testData = "Test      a";

    std::string result = trimR(testData);

    ASSERT_EQ("Test      a", result);
}

TEST(StringUtilsTest, string_cant_be_trimmed_from_left_and_right_if_sign_appear)
{
    std::string testData = "a     Test       a";

    std::string result = trim(testData);

    ASSERT_EQ("a     Test       a", result);
}
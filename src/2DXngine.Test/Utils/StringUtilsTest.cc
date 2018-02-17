#include "gtest/gtest.h"
#include <Utils/StringUtils.h>

TEST(StringUtilsTest, string_can_be_trimmed_from_left)
{
    std::string testData = "     Test";

    std::string result = stringutils::trimL(testData);

    ASSERT_EQ("Test", result);
}

TEST(StringUtilsTest, string_cant_be_trimmed_from_left_if_sign_appear)
{
    std::string testData = "a     Test";

    std::string result = stringutils::trimL(testData);

    ASSERT_EQ("a     Test", result);
}

TEST(StringUtilsTest, string_can_be_trimmed_from_right)
{
    std::string testData = "Test      ";

    std::string result = stringutils::trimR(testData);

    ASSERT_EQ("Test", result);
}

TEST(StringUtilsTest, string_cant_be_trimmed_from_right_if_sign_appear)
{
    std::string testData = "Test      a";

    std::string result = stringutils::trimR(testData);

    ASSERT_EQ("Test      a", result);
}

TEST(StringUtilsTest, string_cant_be_trimmed_from_left_and_right_if_sign_appear)
{
    std::string testData = "a     Test       a";

    std::string result = stringutils::trim(testData);

    ASSERT_EQ("a     Test       a", result);
}

TEST(StringUtilsTest, string_can_be_proper_splitted)
{
    std::string testData = "1,2 3,4 5,6";

    auto result = stringutils::split(testData, ' ');

    ASSERT_EQ(3, result.size());
    ASSERT_EQ("1,2", result[0]);
    ASSERT_EQ("3,4", result[1]);
    ASSERT_EQ("5,6", result[2]);
}

TEST(StringUtilsTest, base64_string_can_be_decoded_properly)
{
    std::string testData = "YWJjZGU=";

    auto result = stringutils::Base64decode(testData);

    ASSERT_EQ("abcde", result);
}

TEST(StringUtilsTest, base64_string_can_be_encoded_properly)
{
    std::string testData = "abcde";

    auto result = stringutils::Base64encode(testData);

    ASSERT_EQ("YWJjZGU=", result);
}
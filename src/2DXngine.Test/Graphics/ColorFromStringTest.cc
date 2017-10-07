#include "gtest\gtest.h"
#include <Graphics\Color.h>

TEST(ColorFromString, can_create_rgb_white_from_hex_string)
{
    auto str = "#ffffff";

    auto result = Color(str);

    ASSERT_FLOAT_EQ(result.r, 1.f);
    ASSERT_FLOAT_EQ(result.g, 1.f);
    ASSERT_FLOAT_EQ(result.b, 1.f);
    ASSERT_FLOAT_EQ(result.a, 1.f);
}

TEST(ColorFromString, can_create_rgb_black_from_hex_string)
{
    auto str = "#000000";

    auto result = Color(str);

    ASSERT_FLOAT_EQ(result.r, 0.f);
    ASSERT_FLOAT_EQ(result.g, 0.f);
    ASSERT_FLOAT_EQ(result.b, 0.f);
    ASSERT_FLOAT_EQ(result.a, 1.f);
}

TEST(ColorFromString, can_create_rgb_color_from_hex_string)
{
    auto str = "#EEE8AA";

    auto result = Color(str);

    ASSERT_FLOAT_EQ(result.r, 0.93333334f);
    ASSERT_FLOAT_EQ(result.g, 0.90980393f);
    ASSERT_FLOAT_EQ(result.b, 0.66666669f);
    ASSERT_FLOAT_EQ(result.a, 1.f);
}


TEST(ColorFromString, can_create_rgba_color_from_hex_string)
{
    auto str = "#32140a20";

    auto result = Color(str);

    ASSERT_FLOAT_EQ(result.r, 0.19607843f);
    ASSERT_FLOAT_EQ(result.g, 0.078431375f);
    ASSERT_FLOAT_EQ(result.b, 0.039215688f);
    ASSERT_FLOAT_EQ(result.a, 0.1254902f);
}
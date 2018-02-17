#include <gtest/gtest.h>
#include <Utils/Errors/Result.h>

class A{};

TEST(ResultTest, result_should_be_invalid_if_errors_occured)
{
    auto result = new Result();

    ASSERT_TRUE(result->isValid());
}

TEST(ResultTest, result_should_be_valid_if_no_errors_occured)
{
    auto result = new Result();
    auto err = Error();
    err.issuer = nullptr;
    err.message = "Oh gosh an error occured";

    result->addError(err);

    ASSERT_FALSE(result->isValid());
    ASSERT_EQ("Oh gosh an error occured", result->get_errors()[0].message);
    ASSERT_EQ(nullptr, result->get_errors()[0].issuer);
}


TEST(ResultTest, result_should_not_be_valid_if_errors_occured_more)
{
    auto result = new Result();

    auto a = new A();

    auto err = Error();
    err.issuer = nullptr;
    err.message = "Oh gosh an error occured";
    
    auto err2 = Error();
    err2.issuer = a;
    err2.message = "Oh gosh an error occured again";

    result->addError(err);
    result->addError(err2);

    ASSERT_FALSE(result->isValid());
    ASSERT_EQ("Oh gosh an error occured", result->get_errors()[0].message);
    ASSERT_EQ(nullptr, result->get_errors()[0].issuer);
    ASSERT_EQ("Oh gosh an error occured again", result->get_errors()[1].message);
    ASSERT_EQ(a, result->get_errors()[1].issuer);
}
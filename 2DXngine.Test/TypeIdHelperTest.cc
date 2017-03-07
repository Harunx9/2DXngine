#include <gtest\gtest.h>
#include <Utils\TypeIdHelper.h>

struct T {};

TEST(TypeIdInfo, DifferentTypesHaveDifferentTypeId)
{
    auto intId = TypeIdInfo<T>::GetTypeId<int>();
    auto boolId = TypeIdInfo<T>::GetTypeId<bool>();
    ASSERT_GT(boolId, intId);
    ASSERT_EQ(0, intId);
    ASSERT_EQ(1, boolId);
}

TEST(TypeIdInfo, SameTypesHaveSameTypeId)
{
    auto intId = TypeIdInfo<T>::GetTypeId<int>();
    auto inttId = TypeIdInfo<T>::GetTypeId<int>();
    ASSERT_EQ(inttId, intId);
    ASSERT_EQ(0, intId);
    ASSERT_EQ(0, inttId);
}

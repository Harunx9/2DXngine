#pragma once
#include <TypeInformation/TypeMetaInfo.h>

class BaseType
{
public:
    ADD_TYPE_META_INFO()
        BaseType() {}
    virtual ~BaseType() {}
};

class TestType1 : public BaseType
{
public:
    ADD_TYPE_META_INFO()
        TestType1() {}
    virtual ~TestType1() {}
};

class TestType2 :public TestType1
{
public:
    ADD_TYPE_META_INFO()
        TestType2() {}
    virtual ~TestType2() {}
};

class TestType4 : public TestType2
{
public:
    ADD_TYPE_META_INFO()
        TestType4() {}
    virtual ~TestType4() {}
};

class TestType3 :public BaseType
{
public:
    ADD_TYPE_META_INFO()
        TestType3() {}
    virtual ~TestType3() {}
};


DECLARE_TYPE_INFO_VARIANTS(BaseType, "")
DECLARE_TYPE_INFO_VARIANTS(TestType1, BaseType)
DECLARE_TYPE_INFO_VARIANTS(TestType2, TestType1)
DECLARE_TYPE_INFO_VARIANTS(TestType3, BaseType)
DECLARE_TYPE_INFO_VARIANTS(TestType4, TestType2)
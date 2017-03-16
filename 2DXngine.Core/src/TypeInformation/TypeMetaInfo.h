#pragma once
#include "TypeInfo.h"
#define ADD_TYPE_META_INFO()             \
virtual TypeInfo getType()               \
{                                        \
    return getTypeInfoFromInstance(this);\
}
#pragma once
#include <string>


class TypeInfo
{
public:
    TypeInfo();
    TypeInfo(const char* name, int id, int paretnId = -1);
    ~TypeInfo();

    inline bool operator==(const TypeInfo *other)
    {
        return this->_id == other->_id && this->_baseTypeId == other->_baseTypeId;
    }

    inline bool operator!=(const TypeInfo *other)
    {
        return !(this == other);
    }

    friend inline bool operator==(const TypeInfo &left, const TypeInfo &right)
    {
        return left._id == right._id && left._baseTypeId == right._baseTypeId;
    }

    friend inline bool operator!=(const TypeInfo &left, const TypeInfo &right)
    {
        return !(left == right);
    }

    bool get_isEmpty();

    bool get_hasBaseType() const;
    TypeInfo* get_BaseType() const;
    int get_Id() const;
    const char* get_Name();

    template<typename T>
    static TypeInfo get();

    template<typename T>
    static TypeInfo get(T*);
private:
    std::string _name;
    int _id;
    int _baseTypeId;
};

#include "TypeIdHelper.h"
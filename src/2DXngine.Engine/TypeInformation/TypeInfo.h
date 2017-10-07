#pragma once
#include <string>
#include <vector>


class TypeInfo
{
public:
    typedef std::vector<TypeInfo> type_list;
    typedef std::vector<TypeInfo*> type_refs_list;
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
    TypeInfo* get_baseType() const;
    type_refs_list get_baseTypes();
    bool get_hasBaseTypeOf(TypeInfo type);
    int get_id() const;
    const char* get_name();

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
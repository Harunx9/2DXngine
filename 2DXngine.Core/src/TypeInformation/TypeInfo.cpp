#include "TypeInfo.h"
#include "TypeCache.h"

#define BASE_OBJECT -1

TypeInfo::TypeInfo() :
    _name(""),
    _id(-1),
    _baseTypeId(-1)
{
}


TypeInfo::TypeInfo(const char * name, int id, int paretnId) :
    _name(name),
    _id(id),
    _baseTypeId(paretnId)
{
}

TypeInfo::~TypeInfo()
{
}

bool TypeInfo::get_isEmpty()
{
    return _id == -1 && _baseTypeId == -1 && _name.empty();
}

bool TypeInfo::get_hasBaseType() const
{
    return this->_baseTypeId > BASE_OBJECT;
}

TypeInfo * TypeInfo::get_BaseType() const
{
    return nullptr;
}

int TypeInfo::get_Id() const
{
    return this->_id;
}

const char * TypeInfo::get_Name()
{
    return this->_name.c_str();
}

//getOrRegisterTypeInChache implementation

TypeInfo getOrRegisterTypeInChache(const char * name, const char * parentTypeName)
{
    TypeInfo type;

    auto typeCache = TypeCache::get_Instance();

    if (typeCache->get_TypeAlreadyExist(name) == false)
    {
        int id = TypeCache::get_NextId();
        int paretnId = -1;
        if (strcmp("", parentTypeName) != 0)
        {
            TypeInfo* parentType = typeCache->get_TypeByRef(parentTypeName);

            if (parentType)
            {
                paretnId = parentType->get_Id();
            }
        }

        type = TypeInfo(name, id, paretnId);
        typeCache->addType(type);
    }
    else
    {
        type = typeCache->get_TypeByValue(name);
    }

    return type;
}
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

TypeInfo * TypeInfo::get_baseType() const
{
    if (_baseTypeId != -1)
    {
        auto typeCache = TypeCache::get_instance();
        return typeCache->get_typeByRef(_baseTypeId);
    }
    return nullptr;
}

TypeInfo::type_refs_list TypeInfo::get_baseTypes()
{
    type_refs_list list;
    auto baseType = get_baseType();
    if (baseType)
    {
        list.push_back(baseType);
        while (baseType->get_hasBaseType())
        {
            list.push_back(baseType);
            baseType = baseType->get_baseType();
        }
    }
    return list;
}

bool TypeInfo::get_hasBaseTypeOf(TypeInfo type)
{
    auto baseTypes = get_baseTypes();
    for (auto& t : baseTypes)
    {
        if (t->get_id() == type.get_id()) 
            return true;
    }

    return false;
}

int TypeInfo::get_id() const
{
    return this->_id;
}

const char * TypeInfo::get_name()
{
    return this->_name.c_str();
}

//getOrRegisterTypeInChache implementation

TypeInfo getOrRegisterTypeInChache(const char * name, const char * parentTypeName)
{
    TypeInfo type;

    auto typeCache = TypeCache::get_instance();

    if (typeCache->get_typeAlreadyExist(name) == false)
    {
        int id = TypeCache::get_nextId();
        int paretnId = -1;
        if (strcmp("", parentTypeName) != 0)
        {
            TypeInfo* parentType = typeCache->get_typeByRef(parentTypeName);

            if (parentType)
            {
                paretnId = parentType->get_id();
            }
        }

        type = TypeInfo(name, id, paretnId);
        typeCache->addType(type);
    }
    else
    {
        type = typeCache->get_typeByValue(name);
    }

    return type;
}
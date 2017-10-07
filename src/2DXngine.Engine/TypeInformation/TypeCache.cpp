#include "TypeCache.h"
#include "TypeInfo.h"
#include <string>

int TypeCache::currentId = 0;

TypeCache * TypeCache::get_instance()
{
    static TypeCache instance;
    return &instance;
}

bool TypeCache::get_typeAlreadyExist(int id)
{
    return this->_cache[id] != nullptr;
}

bool TypeCache::get_typeAlreadyExist(const char * name)
{
    for (auto &pair : this->_cache)
    {
        if (strcmp(pair.second.get_name(), name) == 0)
        {
            return true;
        }
    }
    return false;
}

void TypeCache::addType(TypeInfo type)
{
    this->_cache[type.get_id()] = type;
}

TypeInfo TypeCache::get_typeByValue(int typeId)
{
    return this->_cache[typeId];
}

TypeInfo TypeCache::get_typeByValue(const char * name)
{
    for (auto &pair : this->_cache)
    {
        if (strcmp(pair.second.get_name(), name) == 0)
        {
            return pair.second;
        }
    }
    return TypeInfo();
}

TypeInfo* TypeCache::get_typeByRef(int typeId)
{
    return &this->_cache[typeId];
}

TypeInfo * TypeCache::get_typeByRef(const char * name)
{
    for (auto &pair : this->_cache)
    {
        if (strcmp(pair.second.get_name(), name) == 0)
        {
            return &pair.second;
        }
    }
    return nullptr;
}

TypeCache::TypeCache()
{
}

TypeCache::~TypeCache()
{
}

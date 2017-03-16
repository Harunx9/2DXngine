#include "TypeCache.h"
#include "TypeInfo.h"
#include <string>

int TypeCache::currentId = 0;

TypeCache * TypeCache::get_Instance()
{
    static TypeCache instance;
    return &instance;
}

bool TypeCache::get_TypeAlreadyExist(int id)
{
    return this->_cache[id] != nullptr;
}

bool TypeCache::get_TypeAlreadyExist(const char * name)
{
    for (auto &pair : this->_cache)
    {
        if (strcmp(pair.second.get_Name(), name) == 0)
        {
            return true;
        }
    }
    return false;
}

void TypeCache::addType(TypeInfo type)
{
    this->_cache[type.get_Id()] = type;
}

TypeInfo TypeCache::get_TypeByValue(int typeId)
{
    return this->_cache[typeId];
}

TypeInfo TypeCache::get_TypeByValue(const char * name)
{
    for (auto &pair : this->_cache)
    {
        if (strcmp(pair.second.get_Name(), name) == 0)
        {
            return pair.second;
        }
    }
    return TypeInfo();
}

TypeInfo* TypeCache::get_TypeByRef(int typeId)
{

    return &this->_cache[typeId];
}

TypeInfo * TypeCache::get_TypeByRef(const char * name)
{
    for (auto &pair : this->_cache)
    {
        if (strcmp(pair.second.get_Name(), name) == 0)
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

#pragma once
#include <map>
#include <string>
class TypeInfo;

typedef std::map<int, TypeInfo> types_map;

class TypeCache
{
public:
    static TypeCache * get_instance();
    
    bool get_typeAlreadyExist(int id);
    bool get_typeAlreadyExist(const char* name);
    
    void addType(TypeInfo type);
    TypeInfo* get_typeByRef(int typeId);
    TypeInfo* get_typeByRef(const char* name);
    TypeInfo get_typeByValue(int typeId);
    TypeInfo get_typeByValue(const char* name);

    
    inline static int get_nextId()
    {
        return currentId++;
    }

private:
    TypeCache();
    TypeCache(const TypeCache * other) = delete;
    ~TypeCache();
    static int currentId;
    types_map _cache;
};
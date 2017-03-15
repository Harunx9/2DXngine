#pragma once
#include <map>
#include <string>
class TypeInfo;

typedef std::map<int, TypeInfo> types_map;

class TypeCache
{
public:
    static TypeCache * get_Instance();
    
    bool get_TypeAlreadyExist(int id);
    bool get_TypeAlreadyExist(const char* name);
    
    void addType(TypeInfo type);
    TypeInfo* get_TypeByRef(int typeId);
    TypeInfo* get_TypeByRef(const char* name);
    TypeInfo get_TypeByValue(int typeId);
    TypeInfo get_TypeByValue(const char* name);

    
    inline static int get_NextId()
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
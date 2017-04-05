#pragma once
#include <string>

class AssetType
{
public:
    AssetType(const char* name, int gropuId);
    ~AssetType();

    inline bool operator==(AssetType other)
    {
        return _name == other._name && _gropuId == other._gropuId;
    }

    inline bool operator==(AssetType* other)
    {
        return this->_name == other->_name && this->_gropuId == other->_gropuId;
    }

private:
    std::string _name;
    int _gropuId;
};


class Asset
{
public:
    Asset(std::string _path);
    ~Asset();

    
private:
    std::string _path;
    AssetType * _type;
};


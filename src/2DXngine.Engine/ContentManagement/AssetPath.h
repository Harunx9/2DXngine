#pragma once
#include <string>
#include "../Utils/Macros/PropertyMacro.h"

enum AssetLocation
{
    EMPTY = 0,
    INTERNAL = 1,
    CONTENT = 2,
    CONTENT_PACKED = 3
};

class AssetPath
{
public:
    static AssetPath create(std::string path, AssetLocation location = AssetLocation::CONTENT);
    static AssetPath empty() { return AssetPath("", "", AssetLocation::EMPTY); }
    static std::string get_fileName(std::string path);
    ~AssetPath();
    inline bool isEmpty()
    {
        return  this->_containerPath.empty() && this->_fullPath.empty();
    }

    inline const char * toCStr()
    {
        return this->_fullPath.c_str();
    }

    inline bool  operator==(const AssetPath& other)
    {
        return this->_containerPath == other.get_containerPath() &&
            this->_fullPath == other.get_fullPath();
    }

    READONLY_PROPERTY(AssetLocation, location)
    PROPERTY(std::string, containerPath)
    READONLY_PROPERTY(std::string, fullPath)
private:
    AssetPath(std::string fileName, std::string fullPath, AssetLocation location);
};


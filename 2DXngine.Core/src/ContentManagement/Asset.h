#pragma once
#include <string>
#include "AssetTypes.h"

class Asset
{
public:
    bool ofType(AssetType * type) const;
    std::string get_path() const;
    virtual ~Asset();

protected:
    Asset(std::string _path, const AssetType * assetType);

protected:
    std::string _path;
    const AssetType * _type;
};


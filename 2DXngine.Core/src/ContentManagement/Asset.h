#pragma once
#include <string>
#include "AssetTypes.h"
#include "AssetPath.h"

class Asset
{
public:
    bool ofType(AssetType * type) const;
    AssetPath get_path() const;
    virtual ~Asset();

protected:
    Asset(AssetPath path, const AssetType * assetType);

protected:
    AssetPath _path;
    const AssetType * _type;
};


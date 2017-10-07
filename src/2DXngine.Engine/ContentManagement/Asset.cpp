#include "Asset.h"

Asset::Asset(AssetPath path, const AssetType * assetType):
    _path(path),
    _type(assetType)
{
}

Asset::~Asset()
{
}

bool Asset::ofType(AssetType * type) const
{
    return this->_type == type;
}

AssetPath Asset::get_path() const
{
    return this->_path;
}

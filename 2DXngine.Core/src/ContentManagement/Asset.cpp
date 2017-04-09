#include "Asset.h"

Asset::Asset(std::string _path, const AssetType * assetType)
{
}

Asset::~Asset()
{
}

bool Asset::ofType(AssetType * type) const
{
    return this->_type == type;
}

std::string Asset::get_path() const
{
    return this->_path;
}

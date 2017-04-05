#include "Asset.h"


Asset::Asset(std::string _path)
{

}

Asset::~Asset()
{
}

AssetType::AssetType(const char * name, int gropuId):
    _name(name),
    _gropuId(gropuId)
{
}

AssetType::~AssetType()
{
}

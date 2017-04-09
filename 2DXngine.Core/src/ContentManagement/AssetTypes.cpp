#include "AssetTypes.h"

AssetType::AssetType(const char * name, int gropuId)
{
}

AssetType::~AssetType()
{
}


const AssetType * DefaultAssetType::XML_TYPE = new AssetType("XML", DefinedAssets::XML);
const AssetType * DefaultAssetType::JSON_TYPE = new AssetType("JSON", DefinedAssets::JSON);
const AssetType * DefaultAssetType::TEXTURE_TYPE = new AssetType("TEXTURE", DefinedAssets::TEXTURE);
const AssetType * DefaultAssetType::SPRITE_SHEET_TYPE = new AssetType("SPRITE_SHEET", DefinedAssets::SPRITE_SHEET);
const AssetType * DefaultAssetType::WAV_TYPE = new AssetType("WAV", DefinedAssets::WAV);
const AssetType * DefaultAssetType::MP3_TYPE = new AssetType("MP3", DefinedAssets::MP3);
const AssetType * DefaultAssetType::OGG_TYPE = new AssetType("OGG", DefinedAssets::OGG);
const AssetType * DefaultAssetType::SHADER_PROGRAM_TYPE = new AssetType("SHADER_PROGRAM", DefinedAssets::SHADER_PROGRAM);
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

struct DefaultAssetType
{
    enum DefinedAssets
    {
        XML,
        JSON,
        TEXTURE,
        SPRITE_SHEET,
        WAV,
        MP3,
        OGG,
        SHADER_PROGRAM
    };

    static const AssetType * XML_TYPE;
    static const AssetType * JSON_TYPE;
    static const AssetType * TEXTURE_TYPE;
    static const AssetType * SPRITE_SHEET_TYPE;
    static const AssetType * WAV_TYPE;
    static const AssetType * MP3_TYPE;
    static const AssetType * OGG_TYPE;
    static const AssetType * SHADER_PROGRAM_TYPE;
};
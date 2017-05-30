#pragma once
#include "../Services/Service.h"
#include <string>
#include <vector>
#include "Asset.h"
#include "AssetPath.h"

typedef std::vector<Asset*> cached_assets_list;

class ContentManagerService : public Service
{
public:
    ContentManagerService(std::string contentFolder = "Content");
    ~ContentManagerService();

    virtual void initialize() override;
    virtual void terminate() override;

    template <typename TAsset>
    TAsset* load(AssetPath assetPath);

    bool unload(AssetPath assetPath);

    const char* get_contentFolder() const;
    void set_contentFolder(std::string contentFolder);
private:
    template<typename TAsset>
    TAsset* tryGet(AssetPath assetPath);
    std::string _contentFolder;
    cached_assets_list _cachedAssets;
};

template<typename TAsset>
inline TAsset * ContentManagerService::load(AssetPath assetPath)
{
    TAsset * asset = this->tryGet<TAsset>(assetPath);
    if (asset == nullptr)
    {
        asset = TAsset::load(assetPath);
    }

    return (TAsset *)asset;
}

template<typename TAsset>
inline TAsset * ContentManagerService::tryGet(AssetPath assetPath)
{
    for (auto& asset : this->_cachedAssets)
    {
        if (asset->get_path() == assetPath)
            return (TAsset *)asset;
    }
    return nullptr;
}



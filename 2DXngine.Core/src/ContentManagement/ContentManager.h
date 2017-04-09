#pragma once
#include "../Services/Service.h"
#include <string>
#include <vector>
#include "Asset.h"

typedef std::vector<Asset*> cached_assets_list;

class ContentManager : public Service
{
public:
    ContentManager(const char* name = "ContentManager", std::string contentFolder = "Content");
    ~ContentManager();

    // Inherited via Service
    virtual void initialize() override;
    virtual void terminate() override;

    template <typename TAsset>
    TAsset* load(std::string assetPath);

    bool unload(std::string assetName);
    bool unloadByType(AssetType* type);

    const char* get_contentFolder() const;
    void set_contentFolder(std::string contentFolder);
private:
    template<typename TAsset>
    TAsset* tryGet(std::string assetPath);
    std::string _contentFolder;
    cached_assets_list _cachedAssets;
};

template<typename TAsset>
inline TAsset * ContentManager::load(std::string assetPath)
{
    TAsset * asset = this->tryGet<TAsset>(assetPath);
    if (!asset)
    {
        asset = TAsset::load(assetPath);
    }
    return (TAsset *) asset;
}

template<typename TAsset>
inline TAsset * ContentManager::tryGet(std::string assetPath)
{
    for (auto& asset : this->_cachedAssets)
    {
        if (asset->get_path().compare(assetPath) == 0)
            return (TAsset *)asset;
    }
    return nullptr;
}



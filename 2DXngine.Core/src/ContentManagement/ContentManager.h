#pragma once
#include "../Services/Service.h"
#include <string>
#include <vector>
#include "Asset.h"

typedef std::vector<Asset*> cached_assets_list;

class ContentManager : public Service
{
public:
    ContentManager(const char* name = "ContentManager");
    ~ContentManager();

    // Inherited via Service
    virtual void initialize() override;
    virtual void terminate() override;

    template <typename TAsset>
    TAsset* load(std::string assetName, std::string assetPath);

    bool unload(std::string assetName);
    bool unloadByType(AssetType* type);

    const char* get_contentFolder() const;
    void set_contentFolder(std::string contentFolder);
private:
    std::string _contentFolder;
    cached_assets_list _cachedAssets;
};

template<typename TAsset>
inline TAsset * ContentManager::load(std::string assetName, std::string assetPath)
{
    return NULL;
}

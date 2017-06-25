#include "ContentManagerService.h"


ContentManagerService::ContentManagerService(std::string contentFolder) : Service("ContentManagerService"),
_contentFolder(contentFolder)
{
    this->_cachedAssets = cached_assets_list();
}

ContentManagerService::~ContentManagerService()
{

}

void ContentManagerService::initialize()
{
}

void ContentManagerService::terminate()
{
    for (auto& asset : this->_cachedAssets)
    {
        delete asset;
    }
}

bool ContentManagerService::unload(AssetPath assetPath)
{
    if (this->_cachedAssets.empty()) return true;

    for (auto& asset : this->_cachedAssets)
    {
        if (asset->get_path() == assetPath)
        {
            delete asset;
            return true;
        }
    }

    return false;
}

const char * ContentManagerService::get_contentFolder() const
{
    return this->_contentFolder.c_str();
}

void ContentManagerService::set_contentFolder(std::string contentFolder)
{
    this->_contentFolder = contentFolder;
}


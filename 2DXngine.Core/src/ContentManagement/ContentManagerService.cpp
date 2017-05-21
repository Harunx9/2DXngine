#include "ContentManagerService.h"


ContentManagerService::ContentManagerService(std::string contentFolder) : Service("ContentManager"),
_contentFolder(contentFolder)
{
}

ContentManagerService::~ContentManagerService()
{
}

void ContentManagerService::initialize()
{
}

void ContentManagerService::terminate()
{
}

bool ContentManagerService::unload(std::string assetName)
{
    if (this->_cachedAssets.empty()) return true;


    return false;
}

bool ContentManagerService::unloadByType(AssetType * type)
{
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


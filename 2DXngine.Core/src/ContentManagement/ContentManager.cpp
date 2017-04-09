#include "ContentManager.h"


ContentManager::ContentManager(const char * name, std::string contentFolder) : Service(name),
_contentFolder(contentFolder)
{
}

ContentManager::~ContentManager()
{
}

void ContentManager::initialize()
{
}

void ContentManager::terminate()
{
}

bool ContentManager::unload(std::string assetName)
{
    if (this->_cachedAssets.empty()) return true;


    return false;
}

bool ContentManager::unloadByType(AssetType * type)
{
    return false;
}

const char * ContentManager::get_contentFolder() const
{
    return this->_contentFolder.c_str();
}

void ContentManager::set_contentFolder(std::string contentFolder)
{
    this->_contentFolder = contentFolder;
}


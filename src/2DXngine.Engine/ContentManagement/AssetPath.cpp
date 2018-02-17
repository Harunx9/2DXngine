#include "AssetPath.h"
#include <SDL.h>
#include "../Utils/File.h"
#include "../Utils/StringUtils.h"
#include "../Utils/Path.h"
AssetPath::AssetPath(std::string containerPath, std::string fullPath, AssetLocation location) :
    _containerPath(containerPath),
    _fullPath(fullPath)
{
}

AssetPath AssetPath::create(std::string path, AssetLocation location)
{
    if (location == AssetLocation::CONTENT || location == AssetLocation::CONTENT_PACKED)
    {
        std::string basePath = std::string(SDL_GetBasePath());
        std::string fullPath = basePath.append(path);
        std::string normalizedPath = Path::normalize(fullPath);
        
        if (File::exist(normalizedPath) == false)
            return AssetPath("", "", AssetLocation::EMPTY);
     
        return AssetPath(path, normalizedPath, location);
    }

    return AssetPath("", "", location);
}

std::string AssetPath::get_fileName(std::string path)
{
    auto splittedPath = stringutils::split(path, '/');
    auto fileWithextension = splittedPath.back();
    auto splittedFileName = stringutils::split(fileWithextension, '.');

    return splittedFileName.front();
}

AssetPath::~AssetPath()
{
}

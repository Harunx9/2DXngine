#include "AssetPath.h"
#include <SDL.h>
#include "../Utils/File.h"

AssetPath::AssetPath(std::string containerPath, std::string fullPath, AssertLocation location) :
    _containerPath(containerPath),
    _fullPath(fullPath)
{
}

AssetPath AssetPath::create(std::string path, AssertLocation location)
{
    if (location == AssertLocation::CONTENT || location == AssertLocation::CONTENT_PACKED)
    {
        auto basePath = std::string(SDL_GetBasePath());
        auto fullPath = basePath.append(path);

        if (File::exist(fullPath) == false)
            return AssetPath("", "", AssertLocation::EMPTY);
     
        return AssetPath(path, fullPath, location);
    }

    return AssetPath("", "", location);
}

AssetPath::~AssetPath()
{
}

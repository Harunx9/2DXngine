#include "Texture.h"
#include <gli\texture2d.hpp>

Texture::Texture(std::string path) : Asset(path, DefaultAssetType::TEXTURE_TYPE)
{
}

Texture * Texture::load(std::string path)
{
    gli::texture2d t;
    return nullptr;
}

Texture::~Texture()
{
}

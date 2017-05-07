#include "Texture.h"
#include "../../Utils/File.h"
#include <SDL.h>


Texture::Texture(AssetPath assetPath, Bitmap* bitmap) : Asset(assetPath, DefaultAssetType::TEXTURE_TYPE),
    _bitmap(bitmap)
{
    this->generate();
}

Texture * Texture::load(AssetPath assetPath)
{
    auto bitmap = Bitmap::load(assetPath);
    return new Texture(assetPath, bitmap);
}

Texture::~Texture()
{
    glDeleteTextures(1, &this->_textureId);
}

void Texture::generate()
{
    glGenTextures(1, &this->_textureId);
    glBindTexture(GL_TEXTURE_2D, this->_textureId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->_bitmap->get_width(), this->_bitmap->get_height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, this->_bitmap->get_data());

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->_textureId);
}


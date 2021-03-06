#include "Texture.h"
#include "../../Utils/File.h"
#include <SDL.h>


Texture::Texture(AssetPath assetPath, Bitmap* bitmap) : Asset(assetPath, DefaultAssetType::TEXTURE_TYPE),
    _bitmap(bitmap),
    _format(GL_RGBA),
    _internalFormat(GL_RGBA)
{
    this->generate();
}

Texture::Texture(AssetPath assetPath, Bitmap * bitmap, GLint format) : Asset(assetPath, DefaultAssetType::TEXTURE_TYPE),
    _bitmap(bitmap),
    _format(format),
    _internalFormat(format)
{
    this->generate();
}

Texture::Texture(AssetPath assetPath, Bitmap * bitmap, GLint format, GLint internalFormat) : Asset(assetPath, DefaultAssetType::TEXTURE_TYPE),
    _bitmap(bitmap),
    _format(format),
    _internalFormat(internalFormat)
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
    delete this->_bitmap;
}

void Texture::generate()
{
    glGenTextures(1, &this->_textureId);
    glBindTexture(GL_TEXTURE_2D, this->_textureId);

    glTexImage2D(GL_TEXTURE_2D,
        0,
        this->_internalFormat,
        this->_bitmap->get_width(),
        this->_bitmap->get_height(),
        0,
        this->_format,
        GL_UNSIGNED_BYTE,
        this->_bitmap->get_data());

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->_textureId);
}


#include "Texture.h"

Texture::Texture(std::string path, unsigned char * data, int width, int height) : Texture(path, data, width, height, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR)
{
}

Texture::Texture(std::string path, unsigned char * data, int width, int height, GLuint wrapS, GLuint wrapT) : Texture(path, data, width, height, wrapS, wrapS, GL_LINEAR, GL_LINEAR)
{
}

Texture::Texture(std::string path, unsigned char * data, int width, int height, GLuint wrapS, GLuint wrapT, GLuint filterMin, GLuint filterMax) : Asset(path, DefaultAssetType::TEXTURE_TYPE)
{
    this->_path = path;
    this->_data = data;
    this->_width = width;
    this->_height = height;
    this->_wrapS = wrapS;
    this->_filterMin = filterMin;
    this->_filterMax = filterMax;

    glGenTextures(1, &this->_textureId);

    glBindTexture(GL_TEXTURE_2D, this->_textureId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->_width, this->_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->_data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->_wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->_wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->_filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->_filterMax);

    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture * Texture::load(std::string path)
{
    int width, height;
    auto imageData = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
    return new Texture(path, imageData, width, height);
}

Texture::~Texture()
{
    SOIL_free_image_data(this->_data);
}

GLuint Texture::get_textureId() const
{
    return this->_textureId;
}

GLuint Texture::get_width() const
{
    return this->_width;
}

GLuint Texture::get_height() const
{
    return this->_height;
}

GLuint Texture::get_wrapS() const
{
    return this->_wrapS;
}

GLuint Texture::get_wrapT() const
{
    return this->_wrapT;
}

GLuint Texture::get_filterMin() const
{
    return this->_filterMin;
}

GLuint Texture::get_filterMax() const
{
    return this->_filterMax;
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->_textureId);
}


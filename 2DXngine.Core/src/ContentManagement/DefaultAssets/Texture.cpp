#include "Texture.h"
#include "../../Utils/File.h"
#include <SDL.h>

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
    this->_texelHeight = 1.f / height;
    this->_texelWidth = 1.f / width;

    this->generate();
}

Texture * Texture::load(std::string path)
{
    int width, height;

    auto basePath = std::string(SDL_GetBasePath());
    auto fullPath = basePath.append(path);

    if (File::exist(fullPath) == false)
        return nullptr;

    auto pathC_str = fullPath.c_str();
    auto imageData = SOIL_load_image(pathC_str, &width, &height, 0, SOIL_LOAD_RGBA);
    return new Texture(path, imageData, width, height);
}

Texture::~Texture()
{
    if (this->_data != nullptr)
        SOIL_free_image_data(this->_data);

    glDeleteTextures(1, &this->_textureId);
}

void Texture::generate()
{
    glGenTextures(1, &this->_textureId);
    glBindTexture(GL_TEXTURE_2D, this->_textureId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->_width, this->_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->_data);

    glBindTexture(GL_TEXTURE_2D, 0);
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

GLfloat Texture::get_texelWidth() const
{
    return GLfloat();
}

GLfloat Texture::get_texelHeight() const
{
    return GLfloat();
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->_textureId);
}


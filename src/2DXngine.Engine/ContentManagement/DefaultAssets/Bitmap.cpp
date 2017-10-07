#include "Bitmap.h"

Bitmap::Bitmap(unsigned char * data, GLuint width, GLuint height):
    _data(data),
    _width(width),
    _height(height),
    _texelHeight(1.f / height),
    _texelWidth(1.f / width)
{
}

Bitmap::Bitmap(): Bitmap(0, 0, 0)
{
}

Bitmap::~Bitmap()
{
    this->remove();
}

Bitmap* Bitmap::load(AssetPath assetPath)
{
    int width, height;
    auto path = assetPath.toCStr();
    auto imageData = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA);
    
    return new Bitmap(imageData, width, height);
}

void Bitmap::remove()
{
    if (this->_data != nullptr)
        SOIL_free_image_data(this->_data);
}

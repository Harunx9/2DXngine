#pragma once
#include "../Asset.h"
#include <soil\src\SOIL.h>
#include <GL\glew.h>
class Texture : public Asset
{
public:
    static Texture * load(std::string path);
    ~Texture();

private:
    Texture(std::string path,const char * data);

    GLuint _textureId;
    GLuint _width;
};


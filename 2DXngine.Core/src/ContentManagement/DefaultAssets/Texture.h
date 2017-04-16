#pragma once
#include "../Asset.h"
#include <soil\src\SOIL.h>
#include <GL\glew.h>
class Texture : public Asset
{
public:
    static Texture * load(std::string path);

    Texture(std::string path, unsigned char * data, int width, int height);
    Texture(std::string path, unsigned char * data, int width, int height, GLuint wrapS, GLuint wrapT);
    Texture(std::string path, unsigned char * data, int width, int height, GLuint wrapS, GLuint wrapT, GLuint filterMin, GLuint filterMax);
    
    ~Texture();

    GLuint get_textureId() const;

    GLuint get_width() const;
    GLuint get_height() const;

    GLuint get_wrapS() const;
    GLuint get_wrapT() const;

    GLuint get_filterMin() const;
    GLuint get_filterMax() const;

    void bind() const;
protected:

    GLuint _textureId;
    GLuint _width, _height;
    GLuint _wrapS, _wrapT;
    GLuint _filterMin, _filterMax;
    unsigned char * _data;
};


#pragma once
#include <soil\src\SOIL.h>
#include <GL\glew.h>
#include "../AssetPath.h"
#include "../../Utils/Macros/PropertyMacro.h"

class Bitmap 
{
public:
    
    Bitmap(unsigned char * data, GLuint width, GLuint height);
    Bitmap();
    ~Bitmap();
    
    static Bitmap* load(AssetPath assetPath);
    static Bitmap empty(GLuint width, GLuint height)
    {
        return Bitmap(0, width, height);
    }

    void remove();

    READONLY_PROPERTY(GLfloat, texelWidth)
    READONLY_PROPERTY(GLfloat, texelHeight)
    READONLY_PROPERTY(GLuint, width)
    READONLY_PROPERTY(GLuint, height)
    READONLY_PROPERTY(unsigned char *, data)
};
#pragma once
#include <gl\glew.h>

struct Color
{
    Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    Color(GLshort r, GLshort g, GLshort b, GLshort a)
    {
        this->r = r / (GLfloat)255;
        this->g = g / (GLfloat)255;
        this->b = b / (GLfloat)255;
        this->a = a / (GLfloat)255;
    }

    GLfloat r, g, b, a;
};

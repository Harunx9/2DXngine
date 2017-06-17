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

namespace Colors
{
    const Color white = Color(1.f, 1.f, 1.f, 1.f);
    const Color black = Color(0.f, 0.f, 0.f, 1.f);
    const Color red = Color(1.f, 0.f, 0.f, 1.f);
    const Color green = Color(0.f, 1.f, 0.f, 1.f);
    const Color blue = Color(0.f, 0.f, 1.f, 1.f);
    const Color yellow = Color(1.f, 1.f, 0.f, 1.f);
}
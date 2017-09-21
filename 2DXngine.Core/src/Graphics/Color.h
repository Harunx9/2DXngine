#pragma once
#include <string>
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

    Color(std::string hash)
    {
        if (hash.size() < 7)
        {
            r = 1.f;
            g = 1.f;
            b = 1.f;
            a = 1.f;
        }
        else
        {
            std::string red = hash.substr(1, 2);
            std::string green = hash.substr(3, 2);
            std::string blue = hash.substr(5, 2);
            std::string alpha = "";
            if (hash.size() == 9)
            {
                alpha = hash.substr(7, 2);
            }
            r = std::stol(red, nullptr, 16) / (GLfloat)255;
            g = std::stol(green, nullptr, 16) / (GLfloat)255;
            b = std::stol(blue, nullptr, 16) / (GLfloat)255;
            a = alpha.empty() ? 255 / (GLfloat)255 : std::stol(alpha, nullptr, 16) / (GLfloat)255;
        }
    }

    Color() :
        r(0), g(0), b(0), a(1)
    {

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
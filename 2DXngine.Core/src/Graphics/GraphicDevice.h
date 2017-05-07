#pragma once
#include "Color.h"
#include <gl\glew.h>
#include <SDL.h>
#include "../Utils/Macros/PropertyMacro.h"

struct Viewport
{
    Viewport(GLint x, GLint y, GLint width, GLint height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    Viewport(GLint display[4])
    {
        this->x = display[0];
        this->y = display[1];
        this->width = display[2];
        this->height = display[3];
    }

    GLint x;
    GLint y;
    GLint width;
    GLint height;
};

class GraphicDevice
{
public:
    
    GraphicDevice();
    ~GraphicDevice();

    inline void initialize()
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        this->_window = SDL_CreateWindow("Game Window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            640,
            360,
            SDL_WINDOW_OPENGL);

        auto ctx = SDL_GL_CreateContext(_window);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        GLenum glewError = glewInit();
        if (glewError != GLEW_OK)
        {
            SDL_Quit();
        }
    }

    inline void clear(Color color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    inline Viewport get_viewport()
    {
        GLint display[4];
        glGetIntegerv(GL_VIEWPORT, display);
        return Viewport(display);
    }

    READONLY_PROPERTY(bool, isInitialized)

private:
    SDL_Window * _window;
};


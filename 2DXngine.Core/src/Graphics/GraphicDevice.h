#pragma once
#include "Color.h"
#include <gl\glew.h>
#include <SDL.h>
#include "../Utils/Macros/PropertyMacro.h"
#include "../Config/GraphicConfig.h"
#include "../Utils/Math/RectangleI.h"
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

    RectangleI toRectangle()
    {
        return RectangleI(x, y, width, height);
    }
};

enum BlendFunc
{
    ZERO = GL_ZERO,
    ONE = GL_ONE,
    SRC_COLOR = GL_SRC_COLOR,
    ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
    DST_COLOR = GL_DST_COLOR,
    ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
    SRC_ALPHA = GL_SRC_ALPHA,
    ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
    DST_ALPHA = GL_DST_ALPHA,
    ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
    CONSTANT_COLOR = GL_CONSTANT_COLOR,
    ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
    CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
    ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA,
    SRC_ALPHA_SATURATE = GL_SRC_ALPHA_SATURATE,
    SRC1_COLOR = GL_SRC1_COLOR,
    ONE_MINUS_SRC1_COLOR = GL_ONE_MINUS_SRC1_COLOR,
    SRC1_ALPHA = GL_SRC1_ALPHA,
    ONE_MINUS_SRC1_ALPHA = GL_ONE_MINUS_SRC1_ALPHA
};


class GraphicDevice
{
public:

    GraphicDevice() :
        _isInitialized(false)
    {
    }

    ~GraphicDevice()
    {
        SDL_DestroyWindow(this->_window);
    }

    inline void initialize(GraphicConfig * cfg, const char * windowName)
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        this->_window = SDL_CreateWindow(windowName,
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            cfg->get_windowWidth(),
            cfg->get_windowHeight(),
            SDL_WINDOW_OPENGL);

        auto ctx = SDL_GL_CreateContext(_window);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, cfg->get_openGLMajorVerion());
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, cfg->get_openGLMinorVerion());
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, cfg->get_doubleBufferToggle());

        glewExperimental = GL_TRUE;
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK)
        {
            SDL_Quit();
        }

        if (this->_window)
            this->_isInitialized = true;
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

    inline void enable_Blend(BlendFunc srcFactor, BlendFunc destFactor)
    {
        glBlendFunc(srcFactor, destFactor);
        glEnable(GL_BLEND);
    }

    inline void disable_Blend()
    {
        glDisable(GL_BLEND);
    }

    inline void enable_CullFace()
    {
        glEnable(GL_CULL_FACE);
    }

    inline void disable_CullFace()
    {
        glDisable(GL_CULL_FACE);
    }

    inline void swapBuffers()
    {
        SDL_GL_SwapWindow(this->_window);
    }

    READONLY_PROPERTY(bool, isInitialized)
private:
    SDL_Window * _window;
    bool _blending;
};


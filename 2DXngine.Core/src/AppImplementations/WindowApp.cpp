#include "WindowApp.h"
#include <gl\glew.h>


WindowApp::WindowApp(GameHandler* handler): 
    App(handler)
{
}


WindowApp::~WindowApp()
{
}

void WindowApp::initialize()
{

    this->_isFixedTimeStep = true;
    this->_timeStep = 1.f / 30.f;
    this->_timer = new Timer();

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    this->_window = SDL_CreateWindow("Game Window",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        640,
        360,
        SDL_WINDOW_OPENGL);

    auto ctx = SDL_GL_CreateContext(_window);

    GLenum glewError = glewInit();
    if (glewError != GLEW_OK)
    {
        SDL_Quit();
    }

    if (this->_window && this->_game)
    {
        this->_isInitialized = true;
        this->_isRunning = true;
    }
}

void WindowApp::run()
{
    SDL_Event event;
    float accumulator = 0.0f;
    this->_timer->timerStart();
    while (this->getIsRunning())
    {
        float deltaTime = this->_timer->getDeltaTime();
        accumulator += deltaTime;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                this->_isRunning = false;
        }

        while (accumulator >= this->_timeStep)
        {
            this->_game->update(deltaTime);
            accumulator -= deltaTime;
        }

        this->_game->draw(deltaTime);
    }
}

void WindowApp::exit()
{
    SDL_Quit();
}

#include "WindowApp.h"
#include <gl\glew.h>
#include "../Services/ServiceLocator.h"
#include "SDLEvents/SDLEventsMapperService.h"
#include "../ContentManagement/ContentManagerService.h"
#include "../Input/InputService.h"

WindowApp::WindowApp(GameHandler* handler): 
    App(handler)
{
}


WindowApp::~WindowApp()
{
}

void WindowApp::initialize()
{
    this->_device = new GraphicDevice();
    this->_isFixedTimeStep = true;
    this->_timeStep = 1.f / 30.f;
    this->_timer = new Timer();

    this->_device->initialize(640, 360, "Game");

    if (this->_device->get_isInitialized() && this->_game)
    {
        this->_game->set_device(this->_device);
        this->_game->regiserUserServices();
        this->_game->initialize();
        buildServiceContrainer();
        this->_isInitialized = true;
        this->_isRunning = true;
    }
}

void WindowApp::run()
{
    SDL_Event event;
    auto sdlEventMapper = ServiceLocator::get<SDLEventsMapperService>("SDLEventsMapperService");
    float accumulator = 0.0f;
    this->_timer->timerStart();
    while (this->getIsRunning())
    {
        float deltaTime = this->_timer->getDeltaTime();
        accumulator += deltaTime;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                this->_isRunning = false;
            }
            else
            {
                sdlEventMapper->map(&event);
            }
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

void WindowApp::buildServiceContrainer()
{
    ServiceLocator::registerService(new SDLEventsMapperService());
    ServiceLocator::registerService(new ContentManagerService());
    ServiceLocator::registerService(new InputService());
}
